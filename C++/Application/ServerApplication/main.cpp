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
#include <QWidget>
#include "Model/modelview.hpp"
#include "Model/model.hpp"
#include "Model/map_tree.hpp"

#define NB_ZOMBIE   100
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

    ModelView view(ENV_SIZE, ENV_SIZE);

    view.connect_to_model(&model);

    model.connect_to_view(&view);

    view.show();


    MapTree<int> map_tree(ENV_SIZE, ENV_SIZE, 100, 0);

    int depth = map_tree.getDepth();
    int nbLeaf = map_tree.getNbLeaf();
    int length = map_tree.getLength(25.6, 96.1);
    int width = map_tree.getWidth(25.6, 96.1);

    std::cout << std::endl << "Arbre de profondeur : " << depth << " possédant " << nbLeaf << " feuilles" << std::endl;

    std::cout << std::endl << "Zone du point (25.6, 96.1) Longueur : " << length << " Largeur : " << width << std::endl;    

    return app.exec();
}
