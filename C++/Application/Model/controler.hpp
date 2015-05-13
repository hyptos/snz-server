/**
 * File: controler.hpp
 * Author: Antoine "Azvgui" Richard
 *
 * Created on April 14, 2015, 3:05 PM
 */

#ifndef CONTROLER_HPP
#define CONTROLER_HPP

#include <iostream>

#include "Server/Message/protocolemanager.h"
#include "constantes.hpp"
#include "Info/infoplayer.hpp"
#include "model.hpp"

//! Controler Class
/*!
 * La classe Controler controle un message
 * reçu d'un client avant de le donner au
 * modèle.
 */
class Controler : public IMessageHandler {

	public : 

		///Constructeur
		Controler();

		///Destructeur
		~Controler();

		///Connecte au modèle
		void connect_to_model(SNZ_Model*);

		///Réception des messages
		void onOutPutMessage(IMessage*);

	private :

		SNZ_Model* m_model;							///< pointeur sur le modèle
		std::vector<unsigned long long> m_players; 	///< list des joueurs déjà connectés
};

#endif // CONTROLER_HPP