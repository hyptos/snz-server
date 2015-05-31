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
    
    SoundStimulus *sound = new SoundStimulus(x, z, y, power);

    for(std::list<RABody*>::iterator it = m_agents.begin(); it != m_agents.end(); it++)
            *(*it) << sound;

    delete sound;
}

// Retourne les info sur les entités présentes dans un cone de vision
std::list<InfoEntity> Environment::getInfosInArea(double x, double z, double distance, double alpha, double beta){
    
    std::list<InfoEntity> infos;

    for(std::list<Body*>::iterator it = m_bodies.begin(); it != m_bodies.end(); it++){

        (*it)->lock();

        //On commence par regarder ceux dans la bonne distance
        double dist = std::sqrt(std::pow((*it)->getX() - x, 2.0) + std::pow((*it)->getZ() - z, 2.0));

        if(dist <= distance){

            //On calcul son angle par rapport à la position (x, z)
            double x2 = ((*it)->getX() - x) / dist;
            double z2 = ((*it)->getZ() - x) / dist;
            double gamma = atan(z2 / x2);

            //On regarde si l'entité se trouve dans le cone
            if(gamma > beta - alpha || gamma < beta + alpha){
                InfoEntity info(0, EntityType::PLAYER, (*it)->getX(), (*it)->getZ(), (*it)->getY(), (*it)->getDX(), (*it)->getDZ(), (*it)->getDY());
            
                infos.push_back(info);
            }
        }

        (*it)->unlock();
    }

    return infos;
}
