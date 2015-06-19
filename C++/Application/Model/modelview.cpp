#include "modelview.hpp"

ModelView::ModelView(int w, int h)
    : m_model(NULL), m_server(NULL), m_scene(new QGraphicsScene), m_view(new QGraphicsView(m_scene, this)){

    setFixedSize(w, h);
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    QTimer* timerView = new QTimer();
    timerView->connect(timerView, SIGNAL(timeout()), this, SLOT(repaint_scene()));
    timerView->start(100);

    QTimer* timerServ = new QTimer();
    timerServ->connect(timerServ, SIGNAL(timeout()), this, SLOT(notifyServer()));
    timerServ->start(1000);
}

ModelView::~ModelView(){
    delete m_view;
    delete m_scene;

    //Désallocation des entités
    for (auto& x: m_entities)
        delete x.second;

    //Clear la map
    m_entities.clear();
}

void ModelView::connect_to_model(SNZ_Model* model){
    m_model = model;
}

void ModelView::connect_to_server(ICommunicationServer* server){
    m_server = server;
}

void ModelView::setEntity(InfoEntity* info){
    InfoEntity* cpy = new InfoEntity();
    cpy->setEntity(info->getEntity());
    cpy->setType(info->getType());
    cpy->setX(info->getX());
    cpy->setZ(info->getZ());
    cpy->setY(info->getY());
    cpy->setDX(info->getDX());
    cpy->setDZ(info->getDZ());
    cpy->setDY(info->getDY());
    if(m_entities.find(cpy->getEntity()) != m_entities.end()){
        InfoEntity* tmp = m_entities.find(cpy->getEntity())->second;
        m_entities.find(cpy->getEntity())->second = cpy;
        delete tmp;
    }
}

void ModelView::addEntity(InfoEntity* info){
    if(info->getType() == EntityType::PLAYER)
        std::cout << "View Ajout player" << std::endl;

    if(m_entities.find(info->getEntity()) == m_entities.end()){
        InfoEntity* cpy = new InfoEntity(*info);
        m_entities.insert(std::pair<unsigned long long, InfoEntity*>(cpy->getEntity(), cpy));
    }
}

void ModelView::removeEntity(unsigned long long entity){
    if(m_entities.find(entity) != m_entities.end()){
        delete m_entities.find(entity)->second;
        m_entities.erase(m_entities.find(entity));
    }
}

void ModelView::repaint_scene(){

    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    for (auto& x: m_entities){
        InfoEntity entity = *(x.second);

        // Angle de rotation
        double alpha = atan(entity.getDX() / entity.getDZ());
        if(entity.getDZ() < 0)
            alpha += M_PI;

        //Création du triangle
        QPolygonF triangle;
        triangle << QPointF(entity.getX() + sin(alpha)*5, entity.getZ() + cos(alpha)*5)
            << QPointF(entity.getX() + sin(alpha + 3.0*M_PI_4)*5, entity.getZ() + cos(alpha + 3.0*M_PI_4)*5)
            << QPointF(entity.getX() + sin(alpha + 5.0*M_PI_4)*5, entity.getZ() + cos(alpha + 5.0*M_PI_4)*5);

        QPolygonF cone;
        cone << QPointF(entity.getX(), entity.getZ())
            << QPointF(entity.getX() + sin(alpha + M_PI_4)*50, entity.getZ() + cos(alpha + M_PI_4)*50)
            << QPointF(entity.getX() + sin(alpha - M_PI_4)*50, entity.getZ() + cos(alpha - M_PI_4)*50);

        if(entity.getType() == EntityType::PLAYER)
            m_scene->addPolygon(triangle, QPen(QColor("yellow"), 1), QBrush(QColor("yellow")));
        else{
            m_scene->addPolygon(cone, QPen(QColor("orange"), 1), Qt::NoBrush);
            m_scene->addPolygon(triangle, QPen(QColor("red"), 1), QBrush(QColor("red")));
        }
    }
}

void ModelView::notifyServer(){
    if(m_server != NULL){
        for (auto& x: m_entities){
            InfoEntity* cpy = new InfoEntity(*(x.second));
            m_server->sendBroadCast(cpy);
            delete cpy;
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
            m_model->addEntity(player);
            delete player;
        }
    }
}
