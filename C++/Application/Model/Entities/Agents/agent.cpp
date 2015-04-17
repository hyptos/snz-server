#include "agent.hpp"


//Constructeur
Agent::Agent(unsigned long long id, EntityType type, EntityState state, double x, double z, double y, double dx, double dz, double dy, Body* body, Brain* brain)
    : Entity(id, type, state, x, z, y, dx, dz, dy), m_speed(0.0), m_body(body), m_brain(brain){

    //Connections Body->Brain
    QObject::connect(m_body, SIGNAL(hear_something(double,double,double)), m_brain, SLOT(something_heard(double,double,double)));

    //Connections Brain->Body
    QObject::connect(m_brain, SIGNAL(move_body_move()), m_body, SLOT(move()));
    QObject::connect(m_brain, SIGNAL(lets_go_to(double,double)), m_body, SLOT(move_to(double,double)));

    //Connection Body->Agent
    QObject::connect(body, SIGNAL(coordinates(double,double,double)), this, SLOT(setCoordinates(double,double,double)));
    QObject::connect(body, SIGNAL(direction(double,double,double)), this, SLOT(setDirection(double,double,double)));
    QObject::connect(body, SIGNAL(speed(double)), this, SLOT(setSpeed(double)));
}

//Destructeur
Agent::~Agent(){
}

//Modifie la coordonnée X de l'agent dans l'environnement (et met la vitesse à 0)
void Agent::setX(double x){
    m_body->setX(x);
}

//Modifie la coordonnée Z de l'agent dans l'environnement (et met la vitesse à 0)
void Agent::setZ(double z){
    m_body->setZ(z);
}

//Modifie la coordonnée Y de l'agent dans l'environnement (et met la vitesse à 0)
void Agent::setY(double y){
    m_body->setY(y);
}

//Modifie les coordonnées X, Z et Y de l'agent dans l'environnement (et met la vitesse à 0)
void Agent::setCoordinates(double x, double z, double y){
    m_x = x;
    m_z = z;
    m_y = y;

    emitInfo();
}

//Retourne la vitesse
double Agent::getSpeed() const{
    return m_speed;
}

//Retourne le pointeur sur le Body de l'agent
Body* Agent::getBody(){
    return m_body;
}

//Retourne le pointeur sur le Brain de l'agent
Brain* Agent::getBrain(){
    return m_brain;
}

void Agent::setSpeed(double speed){
    m_speed = speed;

    emitInfo();
}

//Génére et emet les info de l'agent
void Agent::emitInfo(){
    InfoAgent m_info(m_id, m_type, m_state, m_x, m_z, m_y, m_dx, m_dz, m_dy, m_speed);
    emit info(m_info);
}
