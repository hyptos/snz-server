/**
 * File: modelview.h
 * Author: Antoine "Azvgui" Richard
 *
 * Created on April 14, 2015, 3:05 PM
 */

#ifndef SERVERVIEW_H
#define SERVERVIEW_H

#include <iostream>
#include <vector>
#include <list>
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

 class SNZ_Model;


class ModelView : public QWidget{

    Q_OBJECT

    public :

        ///Conctructeur
        ModelView(int, int);

        ~ModelView();

        void connect_to_model(SNZ_Model*);

        void setEntity(unsigned long long, InfoEntity);

    public slots :

        void repaint_scene();

    protected :

        void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    private :

        SNZ_Model* m_model;

        QGraphicsScene* m_scene;
        QGraphicsView*  m_view;

        std::vector<InfoEntity> m_entities;
};

#endif // SERVERVIEW_H

