/**
 * File: modelview.hpp
 * Author: Antoine "Azvgui" Richard
 *
 * Created on April 14, 2015, 3:05 PM
 */

#ifndef SERVERVIEW_H
#define SERVERVIEW_H

#include <iostream>
#include <map>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <chrono>

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

#include "model.hpp"
#include "Info/infoentity.hpp"
#include "Server/communicationserver.hpp"

class SNZ_Model;

class ModelView : public QWidget{

    Q_OBJECT

    public :

        ///Conctructeur
        ModelView(int, int);

        ~ModelView();

        void connect_to_model(SNZ_Model*);

        void connect_to_server(ICommunicationServer*);

        void setEntity(InfoEntity*);

        void addEntity(InfoEntity*);

        void removeEntity(unsigned long long);

    public slots :

        void repaint_scene();

        void notifyServer();

    protected :

        void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    private :

        SNZ_Model* m_model;
        ICommunicationServer* m_server;

        QGraphicsScene* m_scene;
        QGraphicsView*  m_view;

        std::map<unsigned long long, InfoEntity*> m_entities;
};

#endif // SERVERVIEW_H

