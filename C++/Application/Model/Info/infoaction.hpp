/**
 * File: player.hpp
 * Author: Antoine
 *
 * Created on April 16, 2015, 11:04 AM
 */

#ifndef INFO_ACTION_HPP
#define INFO_ACTION_HPP

#include <iostream>

#include "Model/constantes.hpp"

//! InfoAction Class
/*!
 * La classe InfoAction est une structure
 * de données contenant toutes les informations
 * concernant une action faite par une entité
 */
class InfoAction
{
	public :
		
		///Constructeur
        InfoAction(const ActionType&, const unsigned long long&, const unsigned long long&);
		
		///Destructeur
		virtual ~InfoAction();

		///Retourne l'action de l'entité
		ActionType getAction();

		///Retourne l'id de l'entité faisant l'action
        unsigned long long getEntity();

		///Retourne l'id de l'entité cible (si l'action en a une)
        unsigned long long getCible();

	private :

		const ActionType m_action;	///< Action faite par une entité

        const unsigned long long m_entity;	///< Entité faisant l'action
        const unsigned long long m_cible;	///< Entité ciblé par l'action
};

#endif // INFO_ACTION_HPP
