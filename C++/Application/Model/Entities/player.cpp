#include "player.hpp"

#include "Model/environment.hpp"
#include "Model/Entities/Bodies/body.hpp"

//Constructeur
Player::Player(unsigned long long id, Environment* env, double x, double z, double y, double dx, double dz, double dy, AgentMoveState moveState, AgentHealthState health, SNZ_Model* model) 
	: Entity(new InfoPlayer(id, x, z, y, dx, dz, dy, moveState, health), new Body(env, x, z, y, dx, dz, dy, this), model){
}

//Destructeur
Player::~Player(){
}
