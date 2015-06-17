#ifndef PROTOCOLEMANAGER
#define PROTOCOLEMANAGER

#include "message.hpp"

class IMessageDispatcher;
class IMessageHandler;

class protocoleManager {
    public :
        protocoleManager();
        ~protocoleManager();
        virtual IMessage *getMessage(ByteBuffer &buffer) const = 0;
        virtual void setMessageDispatcher(IMessageDispatcher *dispt) = 0;
};

class IMessageDispatcher {
    public :
        IMessageDispatcher();
        ~IMessageDispatcher();
        virtual void dispatchMessage(QUuid client, IMessage *msg) = 0;
        virtual void registerMessageHandler(char id, IMessageHandler *Me) = 0;
};

class IMessageHandler {
public:
    virtual void onOutPutMessage(QUuid client, IMessage *msg) = 0;
};

#endif // PROTOCOLEMANAGER

