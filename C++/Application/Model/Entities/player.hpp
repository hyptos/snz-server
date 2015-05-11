/**
 * File: player.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 24, 2015, 10:26 AM
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "entity.hpp"
#include "Model/Info/infoplayer.hpp"

class Environment;

//! Player Class
/*!
 * La classe Player regroupe les données concernant
 * un joueur utiles pour le SMA. 
 */
class Player : public Entity {

	public :

		///Constructeur
		Player(unsigned long long, Environment*, double, double, double, double, double, double, AgentMoveState moveState, AgentHealthState health, SNZ_Model*);

		///Destructeur
		virtual ~Player();

};


#endif	//PLAYER_HPP
