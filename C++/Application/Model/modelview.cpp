#include "modelview.hpp"

ModelView::ModelView(int w, int h)
    : m_model(NULL), m_scene(new QGraphicsScene), m_view(new QGraphicsView(m_scene, this)){

    setFixedSize(w, h);
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    QTimer* timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(repaint_scene()));
    timer->start(17);
}

ModelView::~ModelView(){

    delete m_view;
    delete m_scene;
}

void ModelView::connect_to_model(SNZ_Model* model){
    m_model = model;
    m_entities = model->getInfos();
}

void ModelView::setEntity(unsigned long long id, InfoEntity info){
    if(m_entities.size() > id)
        m_entities[id] = info;
}

void ModelView::repaint_scene(){
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    for(std::vector<InfoEntity>::iterator it = m_entities.begin(); it != m_entities.end(); it++){
        InfoEntity entity = *it;

        if(entity.getType() == EntityType::PLAYER)
            m_scene->addEllipse(entity.getX(), entity.getZ(), 5, 5, QPen(QColor("yellow"), 1), QBrush(QColor("yellow")));
        else
            m_scene->addEllipse(entity.getX(), entity.getZ(), 5, 5, QPen(QColor("red"), 1), QBrush(QColor("red")));
    }
}

//TODO
void ModelView::mousePressEvent(QMouseEvent *event)
{
    if(m_model != NULL){
        if (event->button() == Qt::LeftButton)
            m_model->getEnvironment()->emitSound(event->x(), event->y(), 0.0, 100.0);
        else if (event->button() == Qt::RightButton){

            int env_size = m_model->getEnvironment()->getLength();
            InfoEntity player(0, EntityType::AGENT, event->x(), event->y(), 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX);
            player.setEntity(m_model->addEntity(player));
            m_entities.push_back(player);
        }
    }
}
