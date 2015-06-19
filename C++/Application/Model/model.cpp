#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int env_size, int nbZ)
    : m_environment(new Environment(env_size, env_size)), m_nbEntities(0), m_view(NULL) {

    std::srand(std::time(NULL));

    //*
    InfoAgent* info = new InfoAgent(0, AgentType::ZOMBIE, 400, 400, 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, 0.0, AgentMoveState::WALK, AgentHealthState::NORMAL);
    addEntity(info);
    delete info;
    info = new InfoAgent(0, AgentType::ZOMBIE, 505, 505, 1.0, (double) rand() / RAND_MAX, ((double) rand() / RAND_MAX) * 2.0 - 1.0, 0.0, AgentMoveState::WALK, AgentHealthState::NORMAL);
    addEntity(info);
    delete info;
    info = new InfoAgent(0, AgentType::ZOMBIE, 320, 640, 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, 0.0, AgentMoveState::WALK, AgentHealthState::NORMAL);
    addEntity(info);
    delete info;
    info = new InfoAgent(0, AgentType::ZOMBIE, 360, 280, 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, ((double) rand() / RAND_MAX) * 2.0 - 1.0, 0.0, AgentMoveState::WALK, AgentHealthState::NORMAL);
    addEntity(info);
    delete info;
    //*/
    /*
    for(int i = 0 ; i < nbZ ; i++){
        InfoAgent* info = new InfoAgent(0, AgentType::ZOMBIE, ((double) rand() / RAND_MAX) * env_size, ((double) rand() / RAND_MAX) * env_size, 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, 0.0, AgentMoveState::WALK, AgentHealthState::NORMAL);
        addEntity(info);
        delete info;
    }
    //*/
}

//Destructeur
SNZ_Model::~SNZ_Model(){
    delete m_environment;

    //Désallocation des entités
    for (auto& x: m_entities)
        delete x.second;

    //Clear la map
    m_entities.clear();
}

//Connecte à la "vue"
void SNZ_Model::connect_to_view(ModelView* view){
    m_view = view;

    if(view != NULL){
        for (auto& x: m_entities)
            view->addEntity(x.second->getInfo());
    }
}

//Notifie la vue d'un changement chez une entitée
void SNZ_Model::notifyEntity(InfoEntity* info){

    if(info->getType() == EntityType::AGENT){
        if(m_view != NULL)
            m_view->setEntity(info);
    }
    else if(info->getType() == EntityType::PLAYER){
        if(m_entities.find(info->getEntity()) != m_entities.end())
            m_entities.find(info->getEntity())->second->setInfo(info);

        if(m_environment != NULL)
            m_environment->emitSound(info->getX(), info->getZ(), info->getY(), 10);
        
        if(m_view != NULL)
          m_view->setEntity(info);
    }
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
    if(entity != NULL && entity->getType() == EntityType::PLAYER){
        InfoPlayer *info = dynamic_cast<InfoPlayer*>(entity);
        Player* player = new Player(id, m_environment, info->getX(), info->getZ(), info->getY(), info->getDX(), info->getDZ(), info->getDY(), info->getMoveState(), info->getHealth(), this);
        m_entities.insert(std::pair<unsigned long long, Entity*>(id, player));
        m_environment->addEntity(EntityType::PLAYER, player->getBody());
    }
    else if(entity != NULL && entity->getType() == EntityType::AGENT){
        InfoAgent *info = dynamic_cast<InfoAgent*>(entity);

        Zombie *zombie = new Zombie(id, m_environment, info->getX(), info->getZ(), info->getY(), info->getDX(), info->getDZ(), info->getDY(), info->getMoveState(), info->getHealth(), this);
        
        m_entities.insert(std::pair<unsigned long long, Entity*>(id, zombie));
        m_environment->addEntity(EntityType::AGENT, zombie->getBody());
    }

    if(m_view != NULL){
        entity->setEntity(id);
        m_view->addEntity(entity);
    }

    return id;
}

//Supprime une entité selon son id
void SNZ_Model::removeEntity(unsigned long long entity){
    if(m_entities.find(entity) != m_entities.end()){
        delete m_entities.find(entity)->second;
        m_entities.erase(m_entities.find(entity));
    }
}
