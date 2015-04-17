#include "body.hpp"

//Constructeur
Body::Body(double x, double z, double y, double dx, double dz, double dy)
    : m_x(x), m_z(z), m_y(y), m_dx(dx), m_dz(z), m_dy(dy), m_speed(0.0){
}

//Destructeur
Body::~Body(){
}

//Retourne la coordonnée X du body
double Body::getX() const{
    return m_x;
}

//Retourne la coordonnée Z du body
double Body::getZ() const{
    return m_z;
}

//Retourne la coordonnée Y du body
double Body::getY() const{
    return m_y;
}

//Retourne la coordonnée DX du body
double Body::getDX() const{
    return m_dx;
}

//Retourne la coordonnée DZ du body
double Body::getDZ() const{
    return m_dz;
}

//Retourne la coordonnée DY du body
double Body::getDY() const{
    return m_dy;
}

//Retourne la vitesse du body
double Body::getSpeed() const{
    return m_speed;
}

//Modifie la coordonnée X
void Body::setX(double x){
    m_x = x;
    m_speed = 0.0;

    emit coordinates(m_x, m_z, m_y);
    emit speed(m_speed);
}

//Modifie la coordonnée Z
void Body::setZ(double z){
    m_z = z;
    m_speed = 0.0;

    emit coordinates(m_x, m_z, m_y);
    emit speed(m_speed);
}

//Modifie la coordonnée Y
void Body::setY(double y){
    m_y = y;
    m_speed = 0.0;

    emit coordinates(m_x, m_z, m_y);
    emit speed(m_speed);
}

//Modifie la coordonnée DX
void Body::setDX(double dx){
    m_dx = dx;

    emit direction(m_dx, m_dz, m_dy);
}

//Modifie la coordonnée DZ
void Body::setDZ(double dz){
    m_dz = dz;

    emit direction(m_dx, m_dz, m_dy);
}

//Modifie la coordonnée DY
void Body::setDY(double dy){
    m_dy = dy;

    emit direction(m_dx, m_dz, m_dy);
}

//Modifie les coordonnées X, Z et Y du body
void Body::setCoordinates(double x, double z, double y){
    m_x = x;
    m_z = z;
    m_y = y;
    m_speed = 0.0;

    emit coordinates(m_x, m_z, m_y);
    emit speed(m_speed);
}

//Modifie la direction du body
void Body::setDirection(double dx, double dz, double dy){
    m_dx = dx;
    m_dz = dz;
    m_dy = dy;

    emit direction(m_dx, m_dz, m_dy);
}

void Body::setSpeed(double speed){
    m_speed = speed;
}

//Fonction senseur appellée lors du déclenchement d'un son dans l'environnement
void Body::hear(double x, double z, double y, double power){

    //On calcule la distance entre le son et le zombie
    double dist = sqrt(pow(x - m_x, 2) + pow(z - m_z, 2) + pow(y - m_y, 2));

    //Si la puissance du son est assez forte pour que le zombie
    //l'entende de la distance calculée
    if(dist <= power)
        emit hear_something(x, z, y);
}

//Fonction moteur qui indique où aller
void Body::move_to(double x, double z){
    double dist = sqrt(pow(x - m_x, 2) + pow(z - m_z, 2));

    m_dx = (x - m_x) / dist;
    m_dz = (z - m_z) / dist;

    m_speed = 1.0;

    emit direction(m_dx, m_dz, m_dy);
    emit speed(m_speed);
}

//Fonction moteur qui bouge
void Body::move(){

    double old_x = m_x;
    double old_z = m_z;
    double old_y = m_y;

    m_x += m_dx*m_speed;
    m_z += m_dz*m_speed;
    //TODO : gestion de la hauteur

    //Si il y a eu modification des coordonnées
    if(m_x != old_x || m_z != old_z || m_y != old_y)
        emit coordinates(m_x, m_z, m_y);
}

void Body::stop_move(){

    m_speed = 0.0;

    emit speed(m_speed);
}
