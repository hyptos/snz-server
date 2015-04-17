#ifndef MESSAGE_H
#define MESSAGE_H

#include "string.h"
#include "Utility/utility.hpp"

#define MSG_WOPAWOPA 'w'

class IMessage
{
public:
    IMessage();
    ~IMessage();

    virtual ByteBuffer *toByteBuffer() = 0;
    virtual char getCode() = 0;

};

class WopawopaMessage  : public IMessage {
public :

    WopawopaMessage() : wopa() {
        strcpy(wopa, "wopawopa");
    };

    ~WopawopaMessage() {};

    ByteBuffer *toByteBuffer() {
        ByteBuffer *res = new ByteBuffer();
        res->append(toBuffer<char>(MSG_WOPAWOPA));
        for(int i = 0; i < 9; i++) {
            res->append(toBuffer<char>(wopa[i]));
        }
        return res;
    }

    char getCode() {
        return MSG_WOPAWOPA;
    }

    char wopa[9];

};

#endif // MESSAGE_H
