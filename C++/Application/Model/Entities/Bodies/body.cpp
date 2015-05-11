#include "body.hpp"

#include "Model/environment.hpp"
#include "Model/Entities/entity.hpp"

//Constructeur
Body::Body(Environment *env, double x, double z, double y, double dx, double dz, double dy, Entity* entity)
    : m_environment(env), m_x(x), m_z(z), m_y(y), m_dx(dx), m_dz(dz), m_dy(dy), m_entity(entity){
}

//Destructeur
Body::~Body(){
}



//Retourne un pointeur sur l'environnement
Environment* Body::getEnvironment(){
    return m_environment;
}

//Retourne la Coordonnée X de l'Entité dans l'Environnement
double Body::getX() const{
    return m_x;
}

//Retourne la Coordonnée Z de l'Entité dans l'Environnement
double Body::getZ() const{
    return m_z;
}

//Retourne la Coordonnée Y de l'Entité dans l'Environnement
double Body::getY() const{
    return m_y;
}

//Retourne la Coordonnée X du vecteur direction de l'Entité
double Body::getDX() const{
    return m_dx;
}

//Retourne la Coordonnée Z du vecteur direction de l'Entité
double Body::getDZ() const{
    return m_dz;
}

//Retourne la Coordonnée Y du vecteur direction de l'Entité
double Body::getDY() const{
    return m_dy;
}



//Modifie la Coordonnée X de l'Entité dans l'Environnement
void Body::setX(double x){
    m_x = x;
}

//Modifie la Coordonnée Z de l'Entité dans l'Environnement
void Body::setZ(double z){
    m_z = z;
}

//Modifie la Coordonnée Y de l'Entité dans l'Environnement
void Body::setY(double y){
    m_y = y;
}

//Modifie la Coordonnée X du vecteur direction de l'Entité
void Body::setDX(double dx){
    m_dx = dx;
}

//Modifie la Coordonnée Z du vecteur direction de l'Entité
void Body::setDZ(double dz){
    m_dz = dz;
}

//Modifie la Coordonnée Y du vecteur direction de l'Entité
void Body::setDY(double dy){
    m_dy = dy;
}

//Modifie les Coordonnées X, Z et Y de l'entité dans l'environnement
void Body::setCoordinates(double x, double z, double y){

    m_x = x;
    m_z = z;
    m_y = y;

    m_entity->notifyCoordinates(m_x, m_z, m_y);
}

//Modifie les Coordonnées X, Z et Y du vecteur direction de l'entité
void Body::setDirection(double dx, double dz, double dy){

    m_dx = dx;
    m_dz = dz;
    m_dy = dy;

    m_entity->notifyDirection(m_dx, m_dz, m_dy);
}



//Indique au corps une action faite sur lui (TODO)
void Body::operator<<(InfoAction action){
}

//Surcharge de l'opérateur()
void Body::operator()(){}

//Vérouille le mutex du body
void Body::lock(){
    m_mutex.lock();
}

//Dévérouille le mutex du body
void Body::unlock(){
    m_mutex.unlock();
}
