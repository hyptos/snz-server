#ifndef MESSAGEHANDLEREXAMPLE_H
#define MESSAGEHANDLEREXAMPLE_H

#include "Message/protocolemanager.h"
#include "Message/message.hpp"
#include "communicationserver.hpp"

class MessageHandlerExample : public IMessageHandler
{
public:
    MessageHandlerExample(ICommunicationServer *_com) {
        com = _com;
    }

    ~MessageHandlerExample();

    void onOutPutMessage(IMessage *msg) {
        WopawopaMessage tes;
        com->sendBroadCast(&tes);
    }

    ICommunicationServer *com;
};

#endif // MESSAGEHANDLEREXAMPLE_H
