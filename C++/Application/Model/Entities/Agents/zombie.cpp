#include "zombie.hpp"

#include "Model/Entities/Bodies/zbody.hpp"

//Constructeur
Zombie::Zombie(unsigned long long id, Environment* env, double x, double z, double y, double dx, double dz, double dy, AgentMoveState moveState, AgentHealthState health, SNZ_Model* model) 
	: ReactiveAgent(new InfoAgent(id, AgentType::ZOMBIE, x, z, y, dx, dz, dy, moveState, health),
		new ZBody(env, x, z, y, dx, dz, dy, this), model){
}

//Destructeur
Zombie::~Zombie(){
}
