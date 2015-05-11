#include "zear.hpp"

//Constructeur
ZEar::ZEar(RABody* body) 
	: ReflexSensor(body) {
}

//Destructeur
ZEar::~ZEar(){
}

//Surchage de l'opérateur <<
void ZEar::operator<<(Stimulus* stimulus){

	if(stimulus->getType() == StimulusType::SOUND){

		SoundStimulus *cpy = new SoundStimulus(*(dynamic_cast<SoundStimulus*>(stimulus)));

		m_mutex.lock();
		m_stimuli.push_back(cpy);
		m_mutex.unlock();
	}
}

//Surchage de l'opérateur ()
void ZEar::operator()(){

	m_stopped = false;

	while(!m_stopped){

		if(!m_stimuli.empty()){
			//On récupère le son capté par ZEar
			m_mutex.lock();
			Stimulus *stimulus = m_stimuli.front();
			m_stimuli.pop_front();
			m_mutex.unlock();

			SoundStimulus *sound = dynamic_cast<SoundStimulus*>(stimulus);

			//On récupère les coordonnées du corps
			m_body->lock();
			double x = m_body->getX();
			double z = m_body->getZ();
			double y = m_body->getY();
			m_body->unlock();

			//On calcule la distance entre le corps et l'épicentre du son
			double dist = std::sqrt(std::pow(sound->getX() - x, 2.0) + std::pow(sound->getZ() - z, 2.0) + std::pow(sound->getY() - y, 2.0));


			//Ici l'acuité permet d'entendre un son de plus ou moins loin
			if(dist < sound->getPower() * m_acuity){

				MoveOrder *order = new MoveOrder(sound->getX(), sound->getZ());

				for(std::vector<MotorModule*>::iterator it = m_motors.begin() ; it != m_motors.end() ; it++)
					*(*it) << order;

				delete order;
			}

			delete stimulus;
		}

		//On attends un dixième de seconde
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
