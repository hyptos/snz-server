#include "QImageLoader/qimageloader.hpp"
#include "Wavefront/wavefront.hpp"
#include <chrono>
#include <thread>
#include <pthread.h>
#include "Server/Message/messagedispatcher.hpp"
#include "Server/Message/protocolemanager.h"
#include "Server/server.hpp"
#include "Server/messagehandlerexample.hpp"

#include <QApplication>
#include "Model/modelview.hpp"
#include "Model/model.hpp"

#define NB_ZOMBIE   10
#define ENV_SIZE    500

int main ( int argc, char** argv ) {
    
    //Main Server
    /*SNZ_Server s;
    implMessageDispatcher dispatcher;
    MessageHandlerExample msgH(&s);
    dispatcher.registerMessageHandler('u', (IMessageHandler*) &msgH);
    s.setMessageDispatcher(&dispatcher);
    s.start();
    while(s.isRunning()) {
        pthread_yield();
    }
    return 0;*/

    //Main IA
    QApplication app(argc, argv);

    SNZ_Model model(ENV_SIZE, NB_ZOMBIE);

    ModelView view(&model);

    view.show();

    return app.exec();
}
