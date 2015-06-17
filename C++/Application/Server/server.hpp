#ifndef SERVER_HPP
#define SERVER_HPP

#include <thread>
#include <pthread.h>
#include "TcpNetworking/simpletcpstartpoint.hpp"
#include "Message/protocolemanager.h"
#include "Message/message.hpp"
#include <vector>
#include "communicationserver.hpp"

typedef struct  _clientData ClientData;

class SNZ_Server : virtual protocoleManager , virtual public ICommunicationServer {

public:

    SNZ_Server();

    ~SNZ_Server();

    void start();

    bool isRunning() const ;

    void stopServer();

    SimpleTcpStartPoint *getSocketServer();

    static void OnDisconnect ( QUuid client );

    void onReceiveMessage(QUuid client) const;

    IMessage *getMessage(ByteBuffer &buffer) const;

    void setMessageDispatcher(IMessageDispatcher *dispt);

    int sendBroadCast(IMessage *);

    int sendToClient(QUuid, IMessage *);

private :

    SimpleTcpStartPoint *mSocketServer;

    void acceptClient(QUuid client);

    IMessageDispatcher *mMessageDispatcher;

    friend void *serveur_listening_routine(void *data);

protected :

    bool running;

    static QMap<QUuid, ClientData*> mClients;

};

typedef struct  _clientData {
    QUuid uuid;
    //SimpleTcpStartPoint* server;
    SNZ_Server *server;
    FiFoBuffering recv_buffering, send_buffering;
    pthread_t recv_thread, send_thread;
    bool closeMe;
} ClientData;


void *serveur_listening_routine(void *data);
void *client_thread_send (void *data);
void *client_thread_receive (void *data);

#endif // SERVER_HPP
