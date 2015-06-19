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
		double dx = m_body->getDX();
		double dz = m_body->getDZ();
		m_body->unlock();

		if(!m_stimuli.empty()){
			//On récupère le son capté par ZEar
			m_mutex.lock();
			Stimulus *stimulus = m_stimuli.front();
			m_stimuli.pop_front();
			m_mutex.unlock();

			v_stimulus = dynamic_cast<VisualStimulus*>(stimulus);
		}

		double beta = atan(dx / dz);
		if(dz < 0){
            if(dx > 0)
                beta += M_PI;
            else 
                beta -= M_PI;
        }

        bool player = false;
        int count1 = 0;
		int count2 = 0;
		double min_dist = DBL_MAX;
		std::pair<double,double> pos;
		
		std::pair<double, double> cohesion;
		cohesion.first = 0.0;
		cohesion.second = 0.0;

		std::pair<double, double> alignment;
		alignment.first = 0.0;
		alignment.second = 0.0;

		double desired_separation = 10.0;
		std::pair<double, double> separation;
		separation.first = 0.0;
		separation.second = 0.0;

		// On get les player
		v_stimulus = new VisualStimulus(
			m_body->getEnvironment()->getVisualStimulus(
				EntityType::PLAYER, x, z, 50.0, M_PI_4, beta, m_body));

		// On Récupère les données et on les parcourt
		std::list<std::pair<EntityType, 
			std::pair<std::pair<double, double>,
				std::pair<double, double>>>> datum
			= v_stimulus->getDatum();

		if(!datum.empty()){
			
			player = true;
			
			for (auto& data: datum){
				double dist = std::sqrt(std::pow(x - data.second.first.first, 2.0) 
							+ std::pow(z - data.second.first.second, 2.0));

				if(dist < min_dist){
					min_dist = dist;
					cohesion.first = data.second.first.first;
					cohesion.second = data.second.first.second;
				}
			}
		}

		if(v_stimulus != NULL)
			delete v_stimulus;

		v_stimulus = new VisualStimulus(
		m_body->getEnvironment()->getVisualStimulus(
			EntityType::AGENT, x, z, 50.0, M_PI_2, beta, m_body));			
		
		datum = v_stimulus->getDatum();
		for (auto& data: datum){
			count1++;

			//Si aucun joueur vu, on s'aligne aux autres
			if(!player){
				alignment.first += data.second.second.first;
				alignment.second += data.second.second.second;

				cohesion.first += data.second.first.first;
				cohesion.second += data.second.first.second;
			}

			//Séparation
			double dist = std::sqrt(std::pow(x - data.second.first.first, 2.0) 
							+ std::pow(z - data.second.first.second, 2.0));

			if(dist <= desired_separation){
				count2++;
				separation.first += (x - data.second.first.first) / dist;
				separation.second += (z - data.second.first.second) / dist;
			}
		}

		if(!player && count1 != 0){
			alignment.first /= count1;
			alignment.second /=	count1;

			cohesion.first /= count1;
			cohesion.second /= count1;
		}

		if(count2 != 0){
			separation.first /= count2;
			separation.second / count2;
		}
		
		//Définition de la destination
		pos.first = cohesion.first + alignment.first + separation.first;
		pos.second = cohesion.second + alignment.second + separation.second;

		if(!datum.empty() || player){

			Order *order;
			if(player && min_dist <= 1.0)
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
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}
