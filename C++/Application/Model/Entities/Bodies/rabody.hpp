/**
 * File: rabody.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 8, 2015, 3:16 PM
 */

#ifndef RA_BOBY_HPP
#define RA_BOBY_HPP

#include <iostream>
#include <vector>

#include "body.hpp"
#include "Model/Stimuli/stimulus.hpp"

class ReactiveAgent;
class SensorModule;
class ReflexSensor;
class MotorModule;

//! RABody class
/*!
 * La classe RABody est la classe mère des
 * corps des agents réactif du modèle.
 */
class RABody : public Body {

	public :

		///Constructeur
		RABody(Environment*, double, double, double, double, double, double, ReactiveAgent*);

		///Destructeur
		virtual ~RABody() = 0;

		///Ajoute un module moteur au corps
		virtual void addMotor(MotorModule*);

		///Ajoute un module senseur au corps
		virtual void addSensor(SensorModule*);

		///Retourne la vitesse actuelle du corps
		virtual double getSpeed();

		///Modifie la vitesse actuelle du corps
		virtual void setSpeed(double);

		///Surcharge de l'opérateur <<
		virtual void operator<<(Stimulus);

	protected :

		std::vector<MotorModule*> m_motors;		///< List des modules moteur du body

		std::vector<ReflexSensor*> m_reflexes;	///< List des modules senseur/reflexes

		double m_speed;							///< vitesse de déplacement de l'agent
};

#endif //RA_BOBY_HPP