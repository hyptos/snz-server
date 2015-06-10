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
		else{
			double beta = atan(dx / dz);
			if(dz < 0){
                if(dx > 0)
                    beta += M_PI;
                else 
                    beta -= M_PI;
            }

			v_stimulus = new VisualStimulus(
				m_body->getEnvironment()->getVisualStimulus(
					x, z, 50.0, M_PI_4, beta, m_body));
		}

		// On Récupère les données et on les parcourt
		std::list<std::pair<EntityType, 
			std::pair<std::pair<double, double>,
				std::pair<double, double>>>> datum
			= v_stimulus->getDatum();

		if(!datum.empty()){
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

			bool player = false;
			for (auto& data: datum){
				double dist = std::sqrt(std::pow(data.second.first.first - x, 2.0)
									+ std::pow(data.second.first.second - z, 2.0));
				if(data.first == EntityType::PLAYER){
					player = true;
					if(dist < min_dist){
						min_dist = dist;
						cohesion.first = data.second.first.first;
						cohesion.second = data.second.first.second;
					}
				}
				else{
					
					if(dist > 0){
						//Gestion du flocking
						count1++;
						
						//Si aucun player en vue
						if(!player){
							cohesion.first += data.second.first.first;
							cohesion.second += data.second.first.second;
						}

						alignment.first += data.second.second.first;
						alignment.second += data.second.second.second;

						if(dist < desired_separation){
							count2++;
							std::pair<double, double> tmp;
							tmp.first = x - data.second.first.first;
							tmp.second = z - data.second.first.second;
							double d = std::sqrt(std::pow(tmp.first, 2.0)
										+ std::pow(tmp.second, 2.0));
							tmp.first /= d;
							tmp.second /= d;
							tmp.first /= dist;
							tmp.second /= dist;

							separation.first += tmp.first;
							separation.second += tmp.second;
						}
					}	
				}
			}

			if(!player){
				cohesion.first /= count1;
				cohesion.second /= count1;
			}

			alignment.first /= count1;
			alignment.second /= count1;

			separation.first /= count2;
			separation.second /= count2;

			pos.first = cohesion.first + alignment.first + separation.first;
			pos.second = cohesion.second + alignment.second + separation.second;

			Order *order;
			//if(	min_dist < 10 )
				//order = new Order(OrderType::STAY);
			//else
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
