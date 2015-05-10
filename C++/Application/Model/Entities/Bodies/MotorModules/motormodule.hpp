/**
 * File: motormodule.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 8, 2015, 0:19 PM
 */

#ifndef MOTOR_MODULE_HPP
#define MOTOR_MODULE_HPP

#include <iostream>

#include "Model/constantes.hpp"
#include "Model/module.hpp"
#include "Model/Entities/Bodies/rabody.hpp"
#include "Model/Entities/Orders/order.hpp"

class RABody;

//! MotorModule class
/*!
 * La classe MotorModule implémente les attributs
 * et méthodes communes aux modules moteur de l'agent.
 */
class MotorModule : public Module {

	public : 

		///Constructeur
		MotorModule(RABody*);

		///Destructeur
		virtual ~MotorModule() = 0;

		///Surchage operateur <<
		virtual void operator<<(Order);

	protected :

		RABody* m_body;				///< Pointeur sur le corps de l'agent

		std::list<Order> m_orders; 	///< FIFO d'ordre à effectuer par le moteur
};

#endif // MOTOR_MODULE_HPP