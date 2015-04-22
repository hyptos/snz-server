/**
 * File: modelview.h
 * Author: Antoine
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


class ModelView : public QWidget{

    Q_OBJECT

    public :

        ///Conctructeur
        ModelView(SNZ_Model*);

        ~ModelView();

    public slots :

        void repaint_scene();

    protected:

        void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    private :

        SNZ_Model* m_model;

        QGraphicsScene* m_scene;
        QGraphicsView*  m_view;
};

#endif // SERVERVIEW_H

