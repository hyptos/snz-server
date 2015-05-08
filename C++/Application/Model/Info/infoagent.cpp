#include "infoagent.hpp"

//Constructeur par défaut
InfoAgent::InfoAgent() : InfoEntity() {
	m_type = EntityType::AGENT;
}

//Constructeur avec paramètres
InfoAgent::InfoAgent(unsigned long long id, AgentType atype, double x, double z, double y, double dx, double dz, double dy, AgentMoveState moveState, AgentHealthState health) 
	: InfoEntity(id, EntityType::AGENT, x, z, y, dx, dz, dy), m_atype(atype), m_moveState(moveState), m_health(health) {
}

//Constructeur par copie
InfoAgent::InfoAgent(const InfoAgent& info) 
	: InfoEntity(info.getEntity(), info.getType(), info.getX(), info.getZ(), info.getY(), info.getDX(), info.getDZ(), info.getDY()), m_atype(info.getAgentType()), m_moveState(info.getMoveState()), m_health(info.getHealth()) {
}

//Destructeur
virtual InfoAgent::~InfoAgent(){
}

//Retourne le type de l'agent
AgentType InfoAgent::getAgentType() const{
	return m_atype;
}

//Modifie le type de l'agent
void InfoAgent::setAgentType(AgentType atype){
	m_atype = atype;
}

//Retourne l'état du mouvement de l'agent
AgentMoveState InfoAgent::getMoveState() const{
	return m_moveState;
}

//Modifie l'état du mouvement de l'agent
void InfoAgent::setMoveState(AgentMoveState moveState){
	m_moveState = moveState;
}

//Retourne l'état de "santé" de l'agent
AgentHealthState InfoAgent::getHealth() const{
	return m_health;
}

//Modifie l'état de "santé" de l'agent
void InfoAgent::setHealth(AgentHealthState health){
	m_health = health;
}
