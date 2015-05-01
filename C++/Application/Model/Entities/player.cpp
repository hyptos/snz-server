#include "player.hpp"

//Constructeur
Player::Player(unsigned long long id, double x, double z, double y, double dx, double dz, double dy, SNZ_Model* model) 
	: Entity(id, EntityType::PLAYER, x, z, y, dx, dz, dy, model), m_health(AgentHealthState::NORMAL), m_moveState(AgentMoveState::WALK){
}

//Destructeur
Player::~Player(){
}


//Retourne l'état de la "santé" du joueur
AgentHealthState Player::getHealthState() const{
	return m_health;
}

//Retourne l'état du mouvement du joueur
AgentMoveState Player::getMoveState() const{
	return m_moveState;
}


//Modifie l'état de la "santé" du joueur
void Player::setHealthState(AgentHealthState health){
	m_health = health;
}

//Modifie l'état du mouvement du joueur
void Player::setMoveState(AgentMoveState moveState){
	m_moveState = moveState;
}
