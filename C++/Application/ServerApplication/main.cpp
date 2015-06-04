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
#include "Model/controler.hpp"

#define NB_ZOMBIE   5
#define ENV_SIZE    500

int main(int argc, char** argv){
    
    //Main Server
    /*
    SNZ_Server s;

    Controler control;

    implMessageDispatcher dispatcher;
    //MessageHandlerExample msgH(&s);
    //dispatcher.registerMessageHandler('u', (IMessageHandler*) &msgH);
    dispatcher.registerMessageHandler('u', (IMessageHandler*) &control);
    //dispatcher.registerMessageHandler('w', (IMessageHandler*) &msgH);
    s.setMessageDispatcher(&dispatcher);
    s.start();
    /*while(s.isRunning()) {
        pthread_yield();
    }
    return 0;
    //*/

    //Main IA
    //*
    QApplication app(argc, argv);

    SNZ_Model model(ENV_SIZE, NB_ZOMBIE);

    ModelView view(ENV_SIZE, ENV_SIZE);

    //control.connect_to_model(&model);

    view.connect_to_model(&model);

    model.connect_to_view(&view);

    //view.connect_to_server(&s);

    view.show();

    return app.exec();
    //*/

    /*
    MapTree<int> map_tree(ENV_SIZE, ENV_SIZE, 0, 0, 100, 0);

    int depth = map_tree.getDepth();
    int nbLeaf = map_tree.getNbLeaf();
    double length = map_tree.getLength(12, 12);
    double width = map_tree.getWidth(12, 12);
    double x = map_tree.getX(12, 12);
    double z = map_tree.getZ(12, 12);

    std::cout << std::endl << "Arbre de profondeur : " << depth << " possédant " << nbLeaf << " feuilles" << std::endl;

    std::cout << std::endl << "Zone du point (12, 12) Longueur : " << length << " Largeur : " << width << std::endl;

    std::cout << std::endl << "Coordonnée de la zone du point (12, 12) x : " << x << " z : " << z << std::endl;
    ///

    return app.exec();

    //*/
}
