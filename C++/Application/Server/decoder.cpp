#include "decoder.h"

template<> void decode(ByteBuffer &buff, ReceiveMessage &res) {

    char c;
    fromBuffer<char>(buff ,0 , c);
    res.setCode(c);
    unsigned char* data = buff.getData();
    unsigned char* res_data  = new unsigned char[buff.getLength() - 1];

    for(int i = 1; i < buff.getLength() - 1; i++) {
        memcpy(&res_data[i], &data[i  + 1], 1);
    }
    ByteBuffer *nBuff = new ByteBuffer(res_data, buff.getLength() - 1);
    res.setBuffer(nBuff);
}

template<> void decode(ByteBuffer &buff, StringMessage &res) {
    char* str = new char[buff.getLength()];
    unsigned char* data = buff.getData();
    for(int i = 0 ; i < buff.getLength(); i++) {
        str[i] = (char) data[i];
    }
    res.setstr(str);
    res.setLen(buff.getLength());
}

template<> void decode(ByteBuffer &buff, InfoEntity &res) {
      std::cout << "decode bytebuffer to InfoEntity" << std::endl;
//    char* str = new char[buff.getLength()];
//    unsigned char* data = buff.getData();
//    for(int i = 0 ; i < buff.getLength(); i++) {
//        str[i] = (char) data[i];
//    }
//    res.setstr(str);
//    res.setLen(buff.getLength());
}

