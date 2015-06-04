#include "zeye.hpp"
#include "Model/environment.hpp"

//Constructeur
ZEye::ZEye(RABody* body) 
	: ReflexSensor(body) {
}

//Destructeur
ZEye::~ZEye(){
	stop();

	while(!m_stimuli.empty()){
		delete m_stimuli.back();
		m_stimuli.pop_back();
	}
}

//Surchage de l'opérateur <<
void ZEye::operator<<(Stimulus* stimulus){

	if(stimulus->getType() == StimulusType::VISUAL){

		VisualStimulus *cpy = new VisualStimulus(*(dynamic_cast<VisualStimulus*>(stimulus)));

		m_mutex.lock();
		m_stimuli.push_back(cpy);
		m_mutex.unlock();
	}
}

//Surchage de l'opérateur ()
void ZEye::operator()(){

	m_stopped = false;

	while(!m_stopped){

		VisualStimulus *v_stimulus = NULL;
		
		//On récupère les coordonnées du corps
		m_body->lock();
		double x = m_body->getX();
		double z = m_body->getZ();
		double y = m_body->getY();
		m_body->unlock();

		if(!m_stimuli.empty()){
			//On récupère le son capté par ZEar
			m_mutex.lock();
			Stimulus *stimulus = m_stimuli.front();
			m_stimuli.pop_front();
			m_mutex.unlock();

			v_stimulus = dynamic_cast<VisualStimulus*>(stimulus);
		}
		else{
			double beta = atan(x / z);
			if(z < 0)
				beta += M_PI;

			v_stimulus = new VisualStimulus(
				m_body->getEnvironment()->getVisualStimulus(
					x, z, 50.0*m_acuity, M_PI_4, beta));
		}

		// On Récupère les données et on les parcourt
		std::list<std::pair<EntityType, std::pair<double, double>>> datum
			= v_stimulus->getDatum();

		if(!datum.empty()){
			double min_dist = DBL_MAX;
			std::pair<double,double> pos;
			bool player = false;
			for (auto& data: datum){
				if(data.first == EntityType::PLAYER)
					player = true;
				else if(player)
					continue;

				double dist = std::sqrt(std::pow(data.second.first - x, 2.0) 
								+ std::pow(data.second.second - z, 2.0));

				if(dist < min_dist){
					min_dist = dist;
					pos.first = data.second.first;
					pos.second = data.second.second;
				}
			}

			Order *order;
			if(	min_dist < 10 )
				order = new Order(OrderType::STAY);
			else
				order = new MoveOrder(pos.first, pos.second);

			for(std::vector<MotorModule*>::iterator it = m_motors.begin() ; it != m_motors.end() ; it++)
				*(*it) << order;

			delete order;
		}

		if(v_stimulus != NULL)
			delete v_stimulus;
		

		//On attends un dixième de seconde
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
