#include "infoplayer.hpp"

//Constructeur par défaut
InfoPlayer::InfoPlayer() 
	: InfoEntity() {
		m_type = EntityType::PLAYER;
}

//Constructeur avec paramètres
InfoPlayer::InfoPlayer(unsigned long long id, double x, double z, double y, double dx, double dz, double dy, AgentMoveState moveState, AgentHealthState health) 
	: InfoEntity(id, EntityType::PLAYER, x, z, y, dx, dz, dy), m_moveState(moveState), m_health(health){
}

//Constructeur par copie
InfoPlayer::InfoPlayer(const InfoPlayer& info) 
	: InfoEntity(info.getEntity(), info.getType(), info.getX(), info.getZ(), info.getY(), info.getDX(), info.getDZ(), info.getDY()), m_moveState(info.getMoveState()), m_health(info.getHealth()){	
}

//Destructeur
InfoPlayer::~InfoPlayer(){
}

//Retourne l'état du mouvement du joueur
AgentMoveState InfoPlayer::getMoveState() const{
	return m_moveState;
}

//Retourne l'état de santé du joueur
AgentHealthState InfoPlayer::getHealth() const{
	return m_health;
}

//Modifie l'état du mouvement du joueur
void InfoPlayer::setMoveState(AgentMoveState moveState){
	m_moveState = moveState;
}

//Modifie l'état de santé du joueur
void InfoPlayer::setHealth(AgentHealthState health){
	m_health = health;
}
