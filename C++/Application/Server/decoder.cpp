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
    std::cout << "decode bytebuffer to InfoEntity" << buff.getLength() << std::endl;

    unsigned long long index = 0;
    char code;
    unsigned long long entity;
    int type;
    double x,y,z,dx,dy,dz;
    index += fromBuffer<char>(buff,index,&code,sizeof(char));
    index += fromBuffer<unsigned long long>(buff,index,&entity,sizeof(unsigned long long));
    index += fromBuffer<int>(buff,index,&type,sizeof(int));
    index += fromBuffer<double>(buff,index,&dx,sizeof(double));
    index += fromBuffer<double>(buff,index,&dz,sizeof(double));
    index += fromBuffer<double>(buff,index,&dy,sizeof(double));
    index += fromBuffer<double>(buff,index,&x,sizeof(double));
    index += fromBuffer<double>(buff,index,&z,sizeof(double));
    index += fromBuffer<double>(buff,index,&y,sizeof(double));

    if(entity == 1){
       res.setType(EntityType::PLAYER);
    } else {
        res.setType(EntityType::AGENT);
    }

    res.setEntity(entity);
    res.setDX(dx);
    res.setDZ(dz);
    res.setDY(dy);
    res.setX(x);
    res.setZ(z);
    res.setY(y);
}



