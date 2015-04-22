#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int env_size, int nbZ)
    : m_environment(new Environment(env_size, env_size)), m_nbEntities(0) {

    std::srand(std::time(NULL));

    for(int i = 0 ; i < nbZ ; i++){
        ZAgent *zombie = new ZAgent(m_nbEntities++, m_environment, ((double) rand() / RAND_MAX) * env_size, ((double) rand() / RAND_MAX) * env_size, ((double) rand() / RAND_MAX) * env_size, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX);

        m_entities.push_back(zombie);
        m_environment->addEntity(zombie);
    }
}

//Destructeur
SNZ_Model::~SNZ_Model(){
    delete m_environment;

    m_entities.clear();
}


//Retourne le lien vers l'environnement
Environment* SNZ_Model::getEnvironment(){
    return m_environment;
}

//Retourne le nombre actuel d'entités
unsigned long long SNZ_Model::getNbEntities(){
    return m_nbEntities;
}

//Retourne les informations concernant une entité
InfoEntity SNZ_Model::getInfo(unsigned long long id){
    return m_entities[id]->getInfo();
}

//Retourne une liste d'informations
std::list<InfoEntity> SNZ_Model::getInfos(){
    return m_environment->getEntities();
}

//Modifie une entité (TODO)
void SNZ_Model::setInfo(InfoEntity info){
}

//Ajoute une entité au modèle (TODO)
unsigned long long SNZ_Model::addEntity(InfoEntity){
}
