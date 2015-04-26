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

//Retourne la Coordonnée X de l'Entité dans l'environnement
double Entity::getX() const {
    return m_x;
}

//Retourne la Coordonnée Z de l'Entité dans l'environnement
double Entity::getZ() const {
    return m_z;
}

//Retourne la Coordonnée Y de l'Entité dans l'environnement
double Entity::getY() const {
    return m_y;
}

//Retourne la Coordonnée X du vecteur direction de l'Entité
double Entity::getDX() const {
    return m_dx;
}

//Retourne la Coordonnée Z du vecteur direction de l'Entité
double Entity::getDZ() const {
    return m_dz;
}

//Retourne la Coordonnée Y du vecteur direction de l'Entité
double Entity::getDY() const {
    return m_dy;
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

//Modifie la Coordonnée X de l'Entité dans l'Environnement
void Entity::setX(double x){
    m_x = x;
}

//Modifie la Coordonnée Z de l'Entité dans l'Environnement
void Entity::setZ(double z){
    m_z = z;
}

//Modifie la Coordonnée Y de l'Entité dans l'Environnement
void Entity::setY(double y){
    m_y = y;
}

//Modifie la Coordonnée X du vecteur direction de l'Entité
void Entity::setDX(double dx){
    m_dx = dx;
}

//Modifie la Coordonnée Z du vecteur direction de l'Entité
void Entity::setDZ(double dz){
    m_dz = dz;
}

//Modifie la Coordonnée Y du vecteur direction de l'Entité
void Entity::setDY(double dy){
    m_dy = dy;
}

//Modifie les Coordonnées X, Z et Y de l'Entité dans l'Environnement
void Entity::setCoordinates(double x, double z, double y){
    m_x = x;
    m_z = z;
    m_y = y;

    if(m_model != NULL)
        m_model->notifyEntity(m_id, getInfo());
}

//Modifie les Coordonnées X, Z et Y du vecteur direction de l'Entité
void Entity::setDirection(double dx, double dz, double dy){
    m_dx = dx;
    m_dz = dz;
    m_dy = dy;

    if(m_model != NULL)
        m_model->notifyEntity(m_id, getInfo());
}

//Vérifie l'égalité entre deux Entités
bool Entity::operator ==(const Entity& entity){
    return (entity.getId() == m_id);
}
