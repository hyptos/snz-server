/**
 * File: zear.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 10, 2015, 2:15 PM
 */

#ifndef ZEAR_HPP
#define ZEAR_HPP

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#include "reflexsensor.hpp"
#include "Model/constantes.hpp"
#include "Model/Stimuli/soundstimulus.hpp"
#include "Model/Stimuli/stimulus.hpp"
#include "Model/Entities/Bodies/rabody.hpp"
#include "Model/Entities/Orders/moveorder.hpp"

class RABody;

//! ZEar Class
/*!
 * la class ZEar implémente la manière
 * dont un zombie capte un son.
 */
class ZEar : public ReflexSensor {

	public :

		///Constructeur
		ZEar(RABody*);

		///Destructeur
		~ZEar();

		///Surcharge de l'opérateur << récupérant des objets Stimulus
		/*!
		 * ZEar ne reçoit que les stimuli de type Sonore
		 */
		virtual void operator<<(Stimulus);

		///Surchage de l'opérateur(), boucle d'actions de ZEar
		virtual void operator()();
};

#endif // ZEAR_HPP
