#include "server.hpp"
#include "decoder.h"

QMap<QUuid , ClientData*> SNZ_Server::mClients;

SNZ_Server::SNZ_Server() : protocoleManager(), running(false), mMessageDispatcher(NULL) {
  SimpleTcpStartPoint::Options options;
  options.connectionPort = 3000;
  options.cbDisconnect = OnDisconnect;
  options.maximumConnectedClients = 10;
  mSocketServer = new SimpleTcpStartPoint( options );
}

SNZ_Server::~SNZ_Server() {
  if(this->isRunning()) {
    this->stopServer();
  }
  delete(mSocketServer);
}

void SNZ_Server::start() {
  if(this->isRunning()) {
    std::cerr << "serveur is already running , abort \n";
    return;
  }
  if(!this->mSocketServer->start()) {
    std::cerr << "impossible to start socketserver \n";
    return;
  }

  this->running = true;
  pthread_t main_thread;
  pthread_create ( &(main_thread), NULL, serveur_listening_routine, this);
  pthread_detach(main_thread);
}

bool SNZ_Server::isRunning() const {
  return this->running;
}

void SNZ_Server::onReceiveMessage(QUuid client) const {
    ByteBuffer* message = NULL;
    mClients [ client ]->recv_buffering.get(message);
    if(this->mMessageDispatcher != NULL) {
        mMessageDispatcher->dispatchMessage(client, this->getMessage(*message));
    }
    if(message != NULL) {
        delete message;
    }
}

void SNZ_Server::stopServer() {
  if(this->isRunning()) {
    this->mSocketServer->stop();
  }
  this->running = false;
}

void SNZ_Server::acceptClient(QUuid client) {
    
    ClientData* clt_data  = new ClientData;
    clt_data->uuid        = client;
    clt_data->server      = this;
    clt_data->recv_buffering.mGettingReleaseBuffer = true;
    clt_data->send_buffering.mGettingReleaseBuffer = true;
    clt_data->closeMe     = false;
    pthread_create ( &(clt_data->send_thread), NULL, client_thread_send, clt_data );
    pthread_create ( &(clt_data->recv_thread), NULL, client_thread_receive, clt_data );
    
    mClients[ client ]     = clt_data;
}

SimpleTcpStartPoint* SNZ_Server::getSocketServer() {
    return this->mSocketServer;
}

void *serveur_listening_routine(void* data) {
  SNZ_Server *server = (SNZ_Server *) data;
  QUuid fake, client;
  while(server->isRunning()) {
    client = server->mSocketServer->listen();
    if(client != fake) {
      server->acceptClient(client);
    }
    pthread_yield();
  }
  return NULL;
}

void *client_thread_receive ( void* data)
{
    ClientData* client = (ClientData*) data;
    SimpleTcpStartPoint *socket_server = client->server->getSocketServer();
    ByteBuffer* message = new ByteBuffer;
    while ( ! client->closeMe ) {
        if ( socket_server->dataAvailable(client->uuid)) {
            std::cout << "data available" << std::endl;
            socket_server->receive(client->uuid, *message);
            std::cout << "data available2" << std::endl;
        }
        if ( message->getLength() > 0 ) {
            client->recv_buffering.add(message);
            message = new ByteBuffer;
            client->server->onReceiveMessage( client->uuid );
            std::cout << "Receive done" << std::endl;
        }
        pthread_yield();
    }
      return NULL;
}

void *client_thread_send ( void* data )
{
    ClientData* client = (ClientData*) data;

    SimpleTcpStartPoint *socket_server = client->server->getSocketServer();
    while ( ! client->closeMe ) {
       if ( client->send_buffering.available() ) {
            ByteBuffer* message;
            client->send_buffering.get(message);
            socket_server->send ( client->uuid, *message );
            delete message;
        }
        pthread_yield();
    }
    return NULL;
}

void SNZ_Server::OnDisconnect ( QUuid client ) {
  std::cout << "on disconnect" << std::endl;
    SNZ_Server::mClients[ client ]->closeMe = true;
    pthread_join(mClients [ client ]->send_thread, NULL );
    pthread_join(mClients [ client ]->recv_thread, NULL );

    if(mClients.contains(client)) {
        SNZ_Server::mClients.remove( client );
    }
}


IMessage *SNZ_Server::getMessage(ByteBuffer &buffer) const {
    ReceiveMessage *msg = new ReceiveMessage();
    decode<ReceiveMessage>(buffer, *msg);
    return msg;
}

void SNZ_Server::setMessageDispatcher(IMessageDispatcher *dispt) {
    mMessageDispatcher = dispt;
}

int SNZ_Server::sendBroadCast(IMessage *msg) {
    int  i = 0;
    for( auto key: mClients.keys() )
    {
        ByteBuffer *test = msg->toByteBuffer();
        mClients.value( key )->send_buffering.add(test);i++;
    }
    return i;
}

int SNZ_Server::sendToClient(QUuid client, IMessage *msg){

    if(!mClients.contains(client))
      return 1;

    ByteBuffer *buff = msg->toByteBuffer();
    mClients.value(client)->send_buffering.add(buff);

    return 0;
}

int SNZ_Server::sendToClient(QUuid client, IMessage *msg, char code){

    if(!mClients.contains(client))
      return 1;

    ByteBuffer *buff = msg->toByteBuffer(code);
    mClients.value(client)->send_buffering.add(buff);

    return 0;
}
