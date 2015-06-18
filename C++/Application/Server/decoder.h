#ifndef DECODER
#define DECODER

#include <stdint.h>
#include "Message/message.hpp"
#include "utility"
#include "Model/Info/infoentity.hpp"


template<typename T> void decode(ByteBuffer &buff, T &res) {
    fromBuffer<T>(buff, 1, res);
    return res;
}

template<> void decode(ByteBuffer &buff, ReceiveMessage &res);

template<> void decode(ByteBuffer &buff, StringMessage &res);

template<> void decode(ByteBuffer &buff, InfoEntity &res);



#endif // DECODER
