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

    void onOutPutMessage(QUuid client, IMessage *msg) {
        char code = msg->getCode();
        std::cout << "reçu : " << code << std::endl;
        switch(code){
            case 'u':{
                InfoEntity tamere;
                std::cout << "Je passe par le case u" << std::endl;
                decode<InfoEntity>(*(msg->toByteBuffer()), tamere);
            break;
            }
            case 'w':{
                std::cout << "Je passe par le case w" << std::endl;
                StringMessage res;
                decode<StringMessage>(*(msg->toByteBuffer()), res);
                char * str = res.getStr();
                std::cout<< "recu : ";
                for(int i = 0; i < res.getLen(); i++) {
                    std::cout<< str[i];
                }
                //int nb_client = com->sendBroadCast(&res);
                //std::cout<< "  message envoyé à "<< nb_client <<"\n";
            break;
            }
            default:{
                std::cout<<"Error" << std::endl;
            break;
            }
        }
    }

    ICommunicationServer *com;
};

#endif // MESSAGEHANDLEREXAMPLE_H
