/**
 * File: reflexsensor.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 7, 2015, 8:47 AM
 */

#ifndef REFLEX_SENSOR_HPP
#define REFLEX_SENSOR_HPP

#include <iostream>
#include <vector>

#include "sensormodule.hpp"
#include "Model/Bodies/MotorModules/motormodule.hpp"

///! ReflexSensor class
/*!
 *	La classe ReflexSensor est la classe 
 * mère des senseurs d'un agent étants directement
 * reliés à un ou plusieurs de ses moteurs, plutot 
 * qu'à son cerveau.
 */
class ReflexSensor : public SensorModule {

	public :

		///Constructeur par défaut
		ReflexSensor();

		///Constructeur avec paramètres
		ReflexSensor(std::vector<MotorModule*>);

		///Destructeur
		virtual ~ReflexSensor() = 0;

		///Ajoute un lien vers un module moteur
		virtual void addMotor(MotorModule*);

	protected :

		std::vector<MotorModule*> m_motors;		///< List des modules moteurs pouvant etre utiliser par le senseur
};

#endif // REFLEX_SENSOR_HPP
