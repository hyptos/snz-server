#include "model.hpp"

//Constructeur
SNZ_Model::SNZ_Model(int env_size, int nbZ)
    : m_environment(new Environment(env_size, env_size)), m_nbEntities(0), m_view(NULL) {

    std::srand(std::time(NULL));

    for(int i = 0 ; i < nbZ ; i++){
        InfoAgent info(0, AgentType::ZOMBIE, AgentMoveState::WALK, AgentHealthState::NORMAL, ((double) rand() / RAND_MAX) * env_size, ((double) rand() / RAND_MAX) * env_size, 0.0, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX, (double) rand() / RAND_MAX);
        addEntity(info);
    }
}

//Destructeur
SNZ_Model::~SNZ_Model(){
    delete m_environment;

    m_entities.clear();
}

//Connecte à la "vue"
void SNZ_Model::connect_to_view(ModelView* view){
    m_view = view;

    for(std::vector<Entity*>::iterator it = m_entities.begin() ; it != m_entities.end() ; it++)
        m_view->setEntity(it->getInfo());
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
unsigned long long SNZ_Model::addEntity(InfoEntity entity){
    unsigned long long id = m_nbEntities++;
    int env_size = m_environment->getLength();

    if(entity.getType() == EntityType::PLAYER){
        Player* player = new Player(id, entity.getX(), entity.getZ(), entity.getY(), entity.getDX(), entity.getDZ(), entity.getDY(), this);
    
        m_entities.push_back(player);
        m_environment->addEntity(player->getBody());
    }
    else if(entity.getType() == EntityType::AGENT){
        ZAgent *zombie = new ZAgent(id, m_environment, entity.getX(), entity.getZ(), entity.getY(), entity.getDX(), entity.getDZ(), entity.getDY(), this);

        m_entities.push_back(zombie);
        m_environment->addEntity(zombie->getBody());
    }

    return id;
}
