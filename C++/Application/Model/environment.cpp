#include "environment.hpp"
#include "Entities/Agents/agent.hpp"

//Constructeur
Environment::Environment(const int &length, const int &width)
    : m_length(length), m_width(width), m_height(INT_MAX) {
}

//Destructeur
Environment::~Environment(){
    m_entities.clear();
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

//Retourne une liste d'InfoEntité (A améliorer pour ne retourner que les entités autour d'un seul points, voir différencier objets de zombies)
std::list<InfoEntity> Environment::getEntities(){

    std::list<InfoEntity> infos;

    for(std::list<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
        infos.push_back((*it)->getInfo());

    return infos;
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
void Environment::addEntity(Entity *entity){
    m_entities.push_back(entity);
}

//Emet un son à un point (x,z,y)
void Environment::emitSound(double x, double z, double y, double power){
    SoundStimulus sound(x, z, y, power);

    for(std::list<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); it++){
        if((*it)->getType() == EntityType::AGENT){
            Agent *agent = dynamic_cast<Agent*>(*it);
            agent->getBody()->catchSound(sound);
        }
    }

}
