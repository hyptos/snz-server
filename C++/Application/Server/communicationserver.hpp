#ifndef COMMUNICATIONSERVER
#define COMMUNICATIONSERVER

#include "Message/message.hpp"

class ICommunicationServer {
public :
    ICommunicationServer();
    ~ICommunicationServer();
    virtual int sendBroadCast(IMessage *) = 0;
    virtual int sendToClient(QUuid, IMessage *) = 0;
};

#endif // COMMUNICATIONSERVER

