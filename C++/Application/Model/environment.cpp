#include "environment.hpp"

#include "Entities/Bodies/body.hpp"
#include "Entities/Bodies/rabody.hpp"

//Constructeur
Environment::Environment(const int &length, const int &width)
    : m_length(length), m_width(width), m_height(INT_MAX) {
}

//Destructeur
Environment::~Environment(){
    m_bodies.clear();
    m_agents.clear();
}

//Retourne la longueur de l'environnement
int Environment::getLength(){
    return m_length;
}

//Retourne la largeur de l'environnement
int Environment::getWidth(){
    return m_width;
}

//Retourne la hauteur de l'environnement
int Environment::getHeight(){
    return m_height;
}

//Retourne si un déplacement est valide ou non (TODO)
bool Environment::validTravel(double old_x, double old_z, double new_x, double new_z){
    return true;
}

//TODO
//Retourne les données concernant la zone autour d'un point (x, z)
void Environment::getArea(double x, double z){
}

//Ajoute un lien vers un agent dans l'environnement
void Environment::addEntity(EntityType type, Body* body){

    if(type == EntityType::PLAYER)
        m_bodies.push_back(body);
    else if(type == EntityType::AGENT)
        m_agents.push_back(dynamic_cast<RABody*>(body));
}

//Emet un son à un point (x,z,y)
void Environment::emitSound(double x, double z, double y, double power){
    SoundStimulus sound(x, z, y, power);

    for(std::list<RABody*>::iterator it = m_agents.begin(); it != m_agents.end(); it++)
            *(*it) << sound;
}
