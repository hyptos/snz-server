#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int size, int nbZ)
    : m_envX(size), m_envY(size), m_nbEntities(0){

    std::srand(std::time(NULL));

    for(int i = 0 ; i < nbZ ; i++){

        //Création de l'agent
        ZAgent* zagent = new ZAgent(m_nbEntities++, rand() % size, rand() % size, 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, 0.0);

        //Connexion son->body
        QObject::connect(this, SIGNAL(sound(double,double,double,double)), zagent->getBody(), SLOT(hear(double,double,double,double)));

        //Connexion agent->model
        QObject::connect(zagent, SIGNAL(info(InfoEntity)), this, SLOT(entity_maj(InfoEntity)));

        //On ajoute l'agent dans la liste
        m_entities.push_back(zagent);
    }
}

//Destructeur
SNZ_Model::~SNZ_Model(){
}

//Actions sur les agents
void SNZ_Model::entity_action(InfoAction info){
    emit maj_action(info);
}

//Transmet les info des entités à la vue
void SNZ_Model::entity_maj(InfoEntity info){
    emit maj_entity(info);
}

//Demande à chaque entités d'émettre ses infos
void SNZ_Model::ask_maj(){
    for(unsigned long long i = 0 ; i < m_entities.size() ; i++)
        m_entities[i]->emitInfo();
}

//Déclenche un son. TODO : Spacialiser le son en 3D
void SNZ_Model::do_sound(double x, double z){
    emit sound(x, z, 0.0, 50.0);
}


