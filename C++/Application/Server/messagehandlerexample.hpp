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
        char code = msg->getCode();
        switch(code){
        case 'u':
            InfoEntity tamere;
            decode<InfoEntity>(*(msg->toByteBuffer()), tamere);
            break;
        }

        StringMessage res;
        decode<StringMessage>(*(msg->toByteBuffer()), res);
        char * str = res.getStr();
        std::cout<< "recu : ";
        for(int i = 0; i < res.getLen(); i++) {
            std::cout<< str[i];
        }
        int nb_client = com->sendBroadCast(&res);
        std::cout<< "  message envoyé à "<< nb_client <<"\n";
    }

    ICommunicationServer *com;
};

#endif // MESSAGEHANDLEREXAMPLE_H
