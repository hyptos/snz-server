/**
 * File: reactiveagent.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 8, 2015, 3:16 PM
 */

#ifndef REACTIVE_AGENT_HPP
#define REACTIVE_AGENT_HPP

#include <iostream>

#include "Model/Entities/entity.hpp"
#include "Model/Info/infoagent.hpp"
#include "Model/Entities/Bodies/rabody.hpp"

class RABody;

//! ReactiveAgent class
/*!
 * La classe ReactiveAgent est la classe
 * mère des agents purement réactif du SMA.
 */
class ReactiveAgent : public Entity {

	public :

		///Constructeur
		ReactiveAgent(InfoAgent*, RABody*, SNZ_Model*);

		///Destructeur
		~ReactiveAgent();
};

#endif // REACTIVE_AGENT_HPP
