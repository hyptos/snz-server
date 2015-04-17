#ifndef MESSAGEHANDLEREXAMPLE_H
#define MESSAGEHANDLEREXAMPLE_H

#include "Message/protocolemanager.h"
#include "decoder.h"
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
        StringMessage res;
        decode<StringMessage>(*(msg->toByteBuffer()), res);
        char * str = res.getStr();
        std::cout<< "recu : ";
        for(int i = 0; i < res.getLen(); i++) {
            std::cout<< str[i];
        }
        com->sendBroadCast(&res);
        std::cout<< "\n";
    }

    ICommunicationServer *com;
};

#endif // MESSAGEHANDLEREXAMPLE_H
