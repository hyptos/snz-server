/**
 * File: zombie.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 10, 2015, 5:00 PM
 */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#include "reactiveagent.hpp"

class Zombie : public ReactiveAgent {

	public :

		///Constructeur
		Zombie(unsigned long long, Environment*, double, double, double, double, double, double, AgentMoveState, AgentHealthState, SNZ_Model*);

		///Destructeur
		virtual ~Zombie();
};

#endif // ZOMBIE_HPP
