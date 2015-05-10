#include "leg.hpp"

//Constructeur
Leg::Leg(RABody* body) 
	: MotorModule(body) {
}

//Destructeur
Leg::~Leg(){
	//On arrète la thread
	stop();

	//On clear les ordres reçut
	m_orders.clear();
}

//Surchage de l'opérateur <<
void Leg::operator<<(Order* order){
	std::cout << "Leg::operator<<" << std::endl;
	if(order->getType() == OrderType::STAY || order->getType() == OrderType::MOVE){
		m_mutex.lock();
		m_orders.push_back(order);
		m_mutex.unlock();
	}
}

//Surchage de l'opérateur ()
void Leg::operator()(){

	std::cout << "Leg::operator()" << std::endl;

	m_stopped = false;

	while(!m_stopped){

		//Si leg à des ordres à exécuter
		if(!m_orders.empty()){
			m_mutex.lock();
			Order *order = m_orders.front();
			m_orders.pop_front();
			m_mutex.unlock();

			//Si c'est un ordre d'arret
			if(order->getType() == OrderType::STAY){
				m_body->lock();
				m_body->setSpeed(0.0);
				m_body->unlock();
			}
			else if(order->getType() == OrderType::MOVE){
				MoveOrder *morder = dynamic_cast<MoveOrder*>(order);

				//On récupère les coordonnées actuelles
				m_body->lock();
				double x = m_body->getX();
				double z = m_body->getZ();
				m_body->unlock();

				//On calcule la direction à prendre
				double dist = std::sqrt(std::pow(morder->getX() - x, 2.0) + std::pow(morder->getZ() - z, 2.0));
				double dx = (morder->getX() - x) / dist;
				double dz = (morder->getZ() - z) / dist;

				//On indique la nouvelle direction et qu'on se déplace
				m_body->lock();
				m_body->setDirection(dx, dz, 0.0);
				m_body->unlock();
				m_body->lock();
				m_body->setSpeed(1.0);
				m_body->unlock();
			}
		}

		//On effectue le déplacement, si on se déplace
		m_body->lock();
		double speed = m_body->getSpeed();
		m_body->unlock();
		if(speed > 0.0){
			//On récupère les coordonnées courante
			m_body->lock();
			double old_x = m_body->getX();
			double old_z = m_body->getZ();
			double old_y = m_body->getY();
			m_body->unlock();

			//On récupère la direction courante
			m_body->lock();
			double dx = m_body->getDX();
			double dz = m_body->getDZ();
			double dy = m_body->getDY();
			m_body->unlock();

			//On récupère la hauteur et la largeur de l'environnement
			m_body->lock();
			Environment* env = m_body->getEnvironment();
			m_body->unlock();

			int length = env->getLength();
        	int width = env->getWidth();

			//On calcule les nouvelles coordonnées
			double new_x = old_x + dx * speed;
			if(new_x >= length)
				new_x -= length;

			double new_z = old_z + dz * speed;
			if(new_z >= width)
				new_z -= width;

			double new_y = old_y; //TODO with height map

			//Si le déplacement est valide pour l'environnement
			if(env->validTravel(old_x, old_z, new_x, new_z)){
				m_body->lock();
				m_body->setCoordinates(new_x, new_z, new_y);
				m_body->unlock();
			}
		}

		//On attends un dixième de seconde
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
