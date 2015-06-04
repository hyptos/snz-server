/**
 * File: zeye.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on June 4, 2015, 2:25 PM
 */

#ifndef ZEYE_HPP
#define ZEYE_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <thread>
#include <cfloat>
#include <chrono>
#include <list>
#include <utility>

#include "reflexsensor.hpp"
#include "Model/constantes.hpp"
#include "Model/Stimuli/visualstimulus.hpp"
#include "Model/Stimuli/stimulus.hpp"
#include "Model/Entities/Bodies/rabody.hpp"
#include "Model/Entities/Orders/moveorder.hpp"

class RABody;

//! ZEye Class
/*!
 * la class ZEye implémente la manière
 * dont un zombie capte un stimulus visuel.
 */
class ZEye : public ReflexSensor {

	public :

		///Constructeur
		ZEye(RABody*);

		///Destructeur
		~ZEye();

		///Surcharge de l'opérateur << récupérant des objets Stimulus
		/*!
		 * ZEye ne reçoit que les stimuli de type Visuel
		 */
		virtual void operator<<(Stimulus*);

		///Surchage de l'opérateur(), boucle d'actions de ZEar
		virtual void operator()();
};

#endif // ZEYE_HPP
