#include "motormodule.hpp"

//Constructeur
MotorModule::MotorModule(RABody* body) 
	: Module(), m_body(body) {
}

//Destructeur
MotorModule::~MotorModule(){
	stop();

	while(!m_orders.empty()){
		delete m_orders.back();
		m_orders.pop_back();
	}
}

//Surchage opérateur <<
void MotorModule::operator<<(Order* order){

	Order *cpy = new Order(*order);

	m_mutex.lock();
	m_orders.push_back(cpy);
	m_mutex.unlock();
}
