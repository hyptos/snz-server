/**
 * File: sensormodule.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 7, 2015, 8:47 AM
 */

#ifndef SENSOR_MODULE_HPP
#define SENSOR_MODULE_HPP

#include <iostream>
#include <list>

#include "Model/module.hpp"
#include "Model/constantes.hpp"
#include "Model/Stimuli/stimulus.hpp"
#include "Model/Entities/Bodies/body.hpp"

class Body;

//! SensorModule class
/*!
 * La classe SensorModule est la classe mère
 * de tous les sensors pouvant appartenir à
 * un agent.
 */
class SensorModule : public Module {

	public : 

		///Constructeur
		SensorModule(SensorType, Body*);

		///Destructeur
		virtual ~SensorModule() = 0;

		///Retourne le type du senseur
		virtual SensorType getType() const;

		///Retourne l'acuité du senseur
		virtual double getAcuity() const;

		///Modifie l'acuité du senseur
		virtual void setAcuity(double);

		///Surcharge de l'opérateur << récupérant des objets Stimulus
		virtual void operator<<(Stimulus);

	protected :

		SensorType m_type;				///< Type de senseur

		double m_acuity;				///< Acuité du senseur (1.0 par défaut)

		std::list<Stimulus> m_stimuli;	///< file de stimuli captés par le senseur

		Body* m_body;					///< Pointeur sur le corps de l'agent
};

#endif	//SENSOR_MODULE_HPP
