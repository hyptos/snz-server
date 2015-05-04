#include "entity.hpp"

#include "Model/model.hpp"

//Constructeur
Entity::Entity(unsigned long long id, EntityType type, double x, double z, double y, double dx, double dz, double dy, SNZ_Model* model)
    : m_id(id), m_type(type), m_x(x), m_z(z), m_y(y), m_dx(dx), m_dz(dz), m_dy(dy), m_model(model){
}

//Destructeur
Entity::~Entity(){
}

//Retourne l'ID de l'Entité
unsigned long long Entity::getId() const {
    return m_id;
}

//Retourne le Type de l'Entité
EntityType Entity::getType() const {
    return m_type;
}

//Retourne les informations sur l'Entité (TODO)
InfoEntity Entity::getInfo() const {
    InfoEntity info(m_id, m_type, m_x, m_z, m_y, m_dx, m_dz, m_dy);

    return info;
}


//Modifie l'ID de l'entité
void Entity::setId(unsigned long long id){
    m_id = id;

    if(m_model != NULL)
        m_model->notifyEntity(m_id, getInfo());
}

//Modifie le Type de l'entité
void Entity::setType(EntityType type){
    m_type = type;

    if(m_model != NULL)
        m_model->notifyEntity(m_id, getInfo());
}

//Vérifie l'égalité entre deux Entités
bool Entity::operator ==(const Entity& entity){
    return (entity.getId() == m_id);
}
