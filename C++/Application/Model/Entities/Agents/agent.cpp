#include "agent.hpp"

//Constructeur
Agent::Agent(unsigned long long id, AgentType atype, Environment *env, Body *body, Brain *brain, double x, double z, double y, double dx, double dz, double dy)
    : Entity(id, EntityType::AGENT, x, z, y, dx, dz, dy), m_atype(atype), m_environment(env), m_body(body), m_brain(brain), m_life(AgentLifeState::ALIVE), m_health(AgentHealthState::NORMAL), m_moveState(AgentMoveState::WALK), m_speed(0.0){
}

//Destructeur
Agent::~Agent(){
}

//Retourne le Type de l'Agent
AgentType Agent::getAgentType(){
    return m_atype;
}

//Retourne le lien vers l'environnement
Environment* Agent::getEnvironment(){
    return m_environment;
}

//Retourne le lien vers le Body de l'Agent
Body* Agent::getBody(){
    return m_body;
}

//Retourne le lien vers le Brain de l'Agent
Brain* Agent::getBrain(){
    return m_brain;
}

//Retourne si l'Agent est toujours "vivant" ou non
bool Agent::isAlive() const {

    if(m_life == AgentLifeState::DEAD)
        return false;

    return true;
}

//Retourne l'état de la "vie" de l'agent
AgentLifeState Agent::getLife() const {
    return m_life;
}

//Retourne l'état de "santé" de l'Agent
AgentHealthState Agent::getHealth() const {
    return m_health;
}

//Retourne l'état du mouvement de l'Agent
AgentMoveState Agent::getMoveState() const {
    return m_moveState;
}

//Retourne la vitesse actuelle de l'Agent
double Agent::getSpeed() const {
    return m_speed;
}

//"Tue" l'Agent
void Agent::kill(){
    m_life = AgentLifeState::DEAD;
}

//Modifie l'état de la "vie" de l'Agent
void Agent::setLife(AgentLifeState life){
    m_life = life;
}

//Modifie l'état de "santé" de l'Agent
void Agent::setHealth(AgentHealthState health){
    m_health = health;
}

//Modifie l'état du mouvement de l'Agent
void Agent::setMoveState(AgentMoveState moveState){
   m_moveState = moveState;
}

//Modifie la vitesse actuelle de l'Agent
void Agent::setSpeed(double speed){
    m_speed = speed;
}
