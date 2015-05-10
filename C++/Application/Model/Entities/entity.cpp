#include "entity.hpp"

#include "Bodies/body.hpp"
#include "Model/model.hpp"

//Constructeur
Entity::Entity(InfoEntity* info, Body* body, SNZ_Model* model)
    : m_info(info), m_body(body), m_model(model){
}

//Destructeur
Entity::~Entity(){
    delete m_info;
    delete m_body;
}



//Retourne les informations sur l'Entité (TODO)
InfoEntity Entity::getInfo() const {
    return *m_info;
}

//Retourne un pointeur sur le corps de l'entité
Body* Entity::getBody() const{
    return m_body;
}




//Modifie les info de l'entité
void Entity::setInfo(InfoEntity* info){
    delete m_info;
    m_info = info;
}

//Modifie le pointeur sur le body de l'entité
void Entity::setBody(Body* body){
    delete m_body;
    m_body = body;
}



///Indique un action extérieur sur l'entité
void Entity::notifyAction(InfoAction action){
    *m_body << action;
}

///Indique une modification des coordonnées du corps à l'entité
void Entity::notifyCoordinates(double x, double z, double y){
    m_info->setX(x);
    m_info->setZ(z);
    m_info->setY(y);

    m_model->notifyEntity(*m_info);
}

///Indique une modification de la direction du corps à l'entité
void Entity::notifyDirection(double dx, double dz, double dy){
    m_info->setDX(dx);
    m_info->setDZ(dz);
    m_info->setDY(dy);

    m_model->notifyEntity(*m_info);
}



//Vérifie l'égalité entre deux Entités
bool Entity::operator ==(const Entity& entity){
    return (m_info->getEntity() == entity.getInfo().getEntity());
}
