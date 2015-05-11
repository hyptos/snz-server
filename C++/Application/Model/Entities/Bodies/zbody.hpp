/**
 * File: zbody.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 10, 2015, 4:31 PM
 */

#ifndef ZBODY_HPP
#define ZBODY_HPP

#include <iostream>
#include <thread>

#include "rabody.hpp"

class Environment;
class ReactiveAgent;

//! ZBody Class
/*!
 * La classe ZBody implémente les paramètres
 * par défaut du corps d'un zombie.
 */
class ZBody : public RABody {

	public : 

		///Constructeur
		/*!
		 * Va créer les modules par défaut d'un zombie
		 */
		ZBody(Environment*, double, double, double, double, double, double, ReactiveAgent*);

		///Destructeur
		virtual ~ZBody();
};

#endif // ZBODY_HPP
