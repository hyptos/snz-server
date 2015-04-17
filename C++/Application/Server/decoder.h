#ifndef DECODER
#define DECODER

#include "Message/message.hpp"
#include "utility"

template<typename T> void decode(ByteBuffer &buff, T &res) {
    fromBuffer<T>(buff, 1, res);
    return res;
}

template<> void decode(ByteBuffer &buff, ReceiveMessage &res);

template<> void decode(ByteBuffer &buff, StringMessage &res);



#endif // DECODER

