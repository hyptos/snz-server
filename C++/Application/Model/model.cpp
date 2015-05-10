#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int env_size, int nbZ)
    : m_environment(new Environment(env_size, env_size)), m_nbEntities(0), m_view(NULL) {

    std::srand(std::time(NULL));

    for(int i = 0 ; i < nbZ ; i++){
        InfoAgent info(0, AgentType::ZOMBIE, ((double) rand() / RAND_MAX) * env_size, ((double) rand() / RAND_MAX) * env_size, 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, AgentMoveState::WALK, AgentHealthState::NORMAL);
        addEntity(&info);
    }
}

//Destructeur
SNZ_Model::~SNZ_Model(){
    delete m_environment;

    while(!m_entities.empty()){
        delete m_entities.back();
        m_entities.pop_back();
    }
}

//Connecte à la "vue"
void SNZ_Model::connect_to_view(ModelView* view){
    m_view = view;

    for(std::vector<Entity*>::iterator it = m_entities.begin() ; it != m_entities.end() ; it++)
        m_view->setEntity((*it)->getInfo());
}

//Notifie la vue d'un changement chez une entitée
void SNZ_Model::notifyEntity(InfoEntity info){
    if(m_view != NULL)
        m_view->setEntity(info);
}

//Retourne le lien vers l'environnement
Environment* SNZ_Model::getEnvironment(){
    return m_environment;
}

//Retourne le nombre actuel d'entités
unsigned long long SNZ_Model::getNbEntities(){
    return m_nbEntities;
}

//Ajoute une entité au modèle (TODO)
unsigned long long SNZ_Model::addEntity(InfoEntity *entity){
    unsigned long long id = m_nbEntities++;
    int env_size = m_environment->getLength();

    if(entity->getType() == EntityType::PLAYER){
        InfoPlayer *info = dynamic_cast<InfoPlayer*>(entity);
        Player* player = new Player(id, m_environment, info->getX(), info->getZ(), info->getY(), info->getDX(), info->getDZ(), info->getDY(), info->getMoveState(), info->getHealth(), this);
    
        m_entities.push_back(player);
        m_environment->addEntity(EntityType::PLAYER, player->getBody());
    }
    else if(entity->getType() == EntityType::AGENT){
        InfoAgent *info = dynamic_cast<InfoAgent*>(entity);

        Zombie *zombie = new Zombie(id, m_environment, info->getX(), info->getZ(), info->getY(), info->getDX(), info->getDZ(), info->getDY(), info->getMoveState(), info->getHealth(), this);
        m_entities.push_back(zombie);
        m_environment->addEntity(EntityType::AGENT, zombie->getBody());
    }

    return id;
}
