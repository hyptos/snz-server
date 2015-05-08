/**
 * File: player.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 24, 2015, 10:26 AM
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "Model/constantes.hpp"
#include "entity.hpp"
#include "Bodies/body.hpp"
#include "Model/Environment"
#include "Model/Info/infoplayer.hpp"

//! Player Class
/*!
 * La classe Player regroupe les données concernant
 * un joueur utiles pour le SMA. 
 */
class Player : public Entity {

	public :

		///Constructeur
		Player(unsigned long long, Environment*, double, double, double, double, double, double, SNZ_Model*);

		///Destructeur
		virtual ~Player();



		///Retourne l'état de "santé" du joueur
		virtual AgentHealthState getHealthState() const;

		///Retourne l'état du mouvement du joueur
		virtual AgentMoveState getMoveState() const;



		///Modifie l'état de la "santé" du joueur
		virtual void setHealthState(AgentHealthState);

		///Modifie l'état du mouvement du joueur
		virtual void setMoveState(AgentMoveState);


		//TODO : un notify contenant état de santé tout ça.

	protected :

        AgentHealthState m_health;  ///< Indique l'état de "santé" du joueur

        AgentMoveState m_moveState; ///< Indique si le joueur marche, cours, et caetera


        //TODO : Stocké le skin ici ? ou en BDD.
};


#endif	//PLAYER_HPP
