#include "modelview.hpp"

ModelView::ModelView(int w, int h)
    : m_model(NULL), m_server(NULL), m_scene(new QGraphicsScene), m_view(new QGraphicsView(m_scene, this)){

    setFixedSize(w, h);
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    QTimer* timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(repaint_scene()));
    timer->start(1000);
}

ModelView::~ModelView(){
    delete m_view;
    delete m_scene;

    while(!m_entities.empty()){
        delete m_entities.back();
        m_entities.pop_back();
    }
}

void ModelView::connect_to_model(SNZ_Model* model){
    m_model = model;
    m_entities.resize(m_model->getNbEntities(), NULL);
}

void ModelView::connect_to_server(ICommunicationServer* server){
    m_server = server;
}

void ModelView::setEntity(InfoEntity* info){

    InfoEntity* cpy = new InfoEntity(*info);

    if(m_entities.size() > cpy->getEntity()){
        InfoEntity* tmp = m_entities[cpy->getEntity()];
        m_entities[cpy->getEntity()] = cpy;
        delete tmp;
    }
}

void ModelView::repaint_scene(){

    if(m_server != NULL){
        for(std::vector<InfoEntity*>::iterator it = m_entities.begin(); it != m_entities.end(); it++){
            InfoEntity* cpy = new InfoEntity(*(*it));
            m_server->sendBroadCast(cpy);
            delete cpy;
        }
    }

    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    for(std::vector<InfoEntity*>::iterator it = m_entities.begin(); it != m_entities.end(); it++){
        
        if(*it != NULL){
            InfoEntity entity = *(*it);

            if(entity.getType() == EntityType::PLAYER)
                m_scene->addEllipse(entity.getX(), entity.getZ(), 5, 5, QPen(QColor("yellow"), 1), QBrush(QColor("yellow")));
            else
                m_scene->addEllipse(entity.getX(), entity.getZ(), 5, 5, QPen(QColor("red"), 1), QBrush(QColor("red")));
        }
    }
}

void ModelView::mousePressEvent(QMouseEvent *event){

    if(m_model != NULL){
        if (event->button() == Qt::LeftButton)
            m_model->getEnvironment()->emitSound(event->x(), event->y(), 0.0, 100.0);
        else if (event->button() == Qt::RightButton){
            int env_size = m_model->getEnvironment()->getLength();
            InfoPlayer *player = new InfoPlayer(0, event->x(), event->y(), 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, AgentMoveState::WALK, AgentHealthState::NORMAL);
            player->setEntity(m_model->addEntity(player));
            m_entities.push_back(player);
        }
    }
}
