#include "modelview.hpp"

ModelView::ModelView(SNZ_Model* model)
    : m_model(model), m_scene(new QGraphicsScene), m_view(new QGraphicsView(m_scene, this)){

    setFixedSize(m_model->getEnvironment()->getLength(), m_model->getEnvironment()->getWidth());
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    QTimer* timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(repaint_scene()));
    timer->start(17);
}

ModelView::~ModelView(){

    delete m_view;
    delete m_scene;
}

void ModelView::repaint_scene(){
    m_scene->addRect(QRectF(0, 0, width(), height()), QPen(QColor("green"), 1), QBrush(QColor("green")));

    std::list<InfoEntity> entities = m_model->getInfos();

    for(std::list<InfoEntity>::iterator it = entities.begin(); it != entities.end(); it++){
        InfoEntity entity = *it;
        m_scene->addEllipse(entity.getX(), entity.getZ(), 5, 5, QPen(QColor("red"), 1), QBrush(QColor("red")));
    }
}

//TODO
void ModelView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        m_model->getEnvironment()->emitSound(event->x(), event->y(), 0.0, 100.0);
}
