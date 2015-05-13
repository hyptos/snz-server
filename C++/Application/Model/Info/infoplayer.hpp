/**
 * File: infoplayer.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 6, 2015, 9:10 AM
 */

#ifndef INFO_PLAYER_HPP
#define INFO_PLAYER_HPP

#include <iostream>

#include "Model/constantes.hpp"
#include "infoentity.hpp"


//! InfoPlayer Class
/*!
 * La classe InfoPlayer contient les données
 * concernant un joueur. (à instant t non précisé)
 */
class InfoPlayer : public InfoEntity 
{
	public :

		///Constructeur par défaut
		InfoPlayer();

		///Constructeur avec paramètres
		InfoPlayer(unsigned long long, double, double, double, double, double, double, AgentMoveState, AgentHealthState);

		///Constructeur par copie
		InfoPlayer(const InfoPlayer&);

		///Constructeur par copie
		InfoPlayer(const InfoEntity&); 

		///Destructeur
		virtual ~InfoPlayer();

		///Retourne l'état du mouvement du joueur
		virtual AgentMoveState getMoveState() const;

		///Retourne l'état de santé du joueur
		virtual AgentHealthState getHealth() const;

		///Modifie l'état du mouvement du joueur
		virtual void setMoveState(AgentMoveState);

		///Modifie l'état de santé du joueur
		virtual void setHealth(AgentHealthState);

	protected :

		AgentMoveState m_moveState;   ///< Etat du mouvement du joueur

		AgentHealthState m_health;    ///< Etat de "santé" du joueur
};

#endif	//INFO_PLAYER_HPP
