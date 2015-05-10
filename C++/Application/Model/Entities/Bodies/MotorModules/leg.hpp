/**
 * File: leg.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 10, 2015, 9:09 AM
 */

#ifndef LEG_HPP
#define LEG_HPP

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#include "motormodule.hpp"
#include "Model/constantes.hpp"
#include "Model/Entities/Orders/order.hpp"
#include "Model/environment.hpp"

//! Leg Class
/*!
 * La classe Leg implémente la routine
 * de déplacement d'un agent. C'est ce
 * module moteur qui s'occupe de modifier
 * les coordonnées et/ou la direction du
 * corps de l'agent.
 */
class Leg : public MotorModule {

	public :

		///Constructeur
		Leg(RABody*);

		///Destructeur
		virtual ~Leg();

		///Surcharge de l'opérateur <<
		/*!
		 * La classe Leg ne récupère que les ordres
		 * de type MOVE ou STAY.
		 */
		virtual void operator<<(Order);

		///Surchage de l'opérateur ()
		/*!
		 * Boucle d'action de Leg
		 */
		virtual void operator()();
};

#endif // LEG_HPP