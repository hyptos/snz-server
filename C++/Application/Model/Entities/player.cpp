#include "player.hpp"

//Constructeur
Player::Player(unsigned long long id, double x, double z, double y, double dx, double dz, double dy, SNZ_Model* model) 
	: Entity(id, EntityType::PLAYER, x, z, y, dx, dz, dy, model), m_life(AgentLifeState::ALIVE), m_health(AgentHealthState::NORMAL), m_moveState(AgentMoveState::WALK){
}

//Destructeur
Player::~Player(){
}


//Retourne l'état de la "vie" du joueur
AgentLifeState Player::getLifeState(){
	return m_life;
}

//Retourne l'état de la "santé" du joueur
AgentHealthState Player::getHealthState(){
	return m_health;
}

//Retourne l'état du mouvement du joueur
AgentMoveState Player::getMoveState(){
	return m_moveState;
}

//Modifie l'état de la "vie" du joueur
void Player::setLifeState(AgentLifeState life){
	m_life = life;
}

//Modifie l'état de la "santé" du joueur
void Player::setHealthState(AgentHealthState health){
	m_health = health;
}

//Modifie l'état du mouvement du joueur
void Player::setMoveState(AgentMoveState moveState){
	m_moveState = moveState;
}
