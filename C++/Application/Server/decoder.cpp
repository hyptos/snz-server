#include "decoder.h"

template<> void decode(ByteBuffer &buff, ReceiveMessage &res) {

    char c , index;
    index = fromBuffer<char>(buff ,0 , c);
    res.setCode(c);
    unsigned char* data = buff.getData();
    unsigned char* res_data  = new unsigned char[buff.getLength() - 1];

    for(int i = 1; i < buff.getLength(); i++) {
        res_data[i - 1] = data[i];
    }
    ByteBuffer *nBuff = new ByteBuffer(res_data, buff.getLength());
    res.setBuffer(nBuff);
}

template<> void decode(ByteBuffer &buff, StringMessage &res) {

    std::cout << "BINARY:" << buff.getData() << std::endl;
    char* str = new char[buff.getLength()];
    unsigned char* data = buff.getData();
    for(int i = 0 ; i < buff.getLength(); i++) {
        std::cout << data[i] << std::endl;
        str[i] = (char) data[i];
    }
    res.setstr(str);
    res.setLen(buff.getLength());
    std::cout<< "fin decode string \n";
}

template<> void decode(ByteBuffer &buff, InfoEntity &res) {
    std::cout << "decode bytebuffer to InfoEntity " << buff.getLength() << std::endl;

    unsigned long long index = 0;
    char code;
    unsigned long long entity;
    int type;
    float x = 0,y =0,z =0,dx=0,dy=0,dz=0;
    unsigned long long test = 0;

    index = fromBuffer<unsigned long long>(buff,index,&entity,1); //8

    index = fromBuffer<int>(buff,index,&type,1); //4

    index = fromBuffer<float>(buff,index,&dx,1); //4

    index = fromBuffer<float>(buff,index,&dz,1); //4

    index = fromBuffer<float>(buff,index,&dy,1); //4

    index = fromBuffer<float>(buff,index,&x,1); //4

    index = fromBuffer<float>(buff,index,&z,1); //4

    index = fromBuffer<float>(buff,index,&y,1); //4

    std::cout << "x" << x << " y" << y << " type" << type << std::endl  ;

    if(type == 1){
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

    res.affiche();

    std::cout << "decoder done!" << std::endl;


}



