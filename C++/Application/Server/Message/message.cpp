#include "message.hpp"



IMessage::IMessage() : code(0), mData(NULL) { }

IMessage::IMessage(char var_code) : code(var_code), mData(NULL) {}

IMessage::IMessage(char var_code, void* data) : code(var_code) , mData(data) {}

IMessage::~IMessage() {}

