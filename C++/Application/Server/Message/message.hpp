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

class ReceiveMessage : public IMessage
{
public:
    ReceiveMessage() {};
    ~ReceiveMessage() {};

    ByteBuffer *toByteBuffer() {
        return mBuff;
    }

    char getCode() {
        return mCode;
    }

    void setBuffer(ByteBuffer *buff) {
        mBuff = buff;
    }

    void setCode(char _code) {
        mCode = _code;
    }

    char mCode;
    ByteBuffer *mBuff;
};

class WopawopaMessage  : public IMessage {
public :

    WopawopaMessage() : wopa() {
        strcpy(wopa, "wopawopa");
    }

    ~WopawopaMessage() {}

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

class StringMessage  : public IMessage {
public :

    StringMessage(){}
    StringMessage(char* str, int len) : mStr(NULL), mLen(len) {
        mStr = new char[len];
        for(int i = 0; i < len; i++) {
            mStr[i] = str[i];
            if(i == len - 1) {
                mStr[i] = '\0';
            }
        }
    }

    ~StringMessage() {}

    ByteBuffer *toByteBuffer() {
        ByteBuffer *res = new ByteBuffer();
        res->append(toBuffer<char>(MSG_WOPAWOPA));
        for(int i = 0; i < mLen; i++) {
            res->append(toBuffer<char>(mStr[i]));
        }
        return res;
    }

    void setstr(char* str) {
        mStr = str;
    }

    char* getStr() {
        return mStr;
    }

    int getLen() {
        return mLen;
    }

    void setLen(int len) {
        mLen = len;
    }

    char getCode() {
        return MSG_WOPAWOPA;
    }

    char *mStr;
    int mLen;
};

#endif // MESSAGE_H
