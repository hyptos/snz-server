#ifndef COMMUNICATIONSERVER
#define COMMUNICATIONSERVER

#include "Message/message.hpp"

class ICommunicationServer {
public :
    ICommunicationServer();
    ~ICommunicationServer();
    virtual void sendBroadCast(IMessage *) = 0;
};

#endif // COMMUNICATIONSERVER

