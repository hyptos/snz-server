#include "motormodule.hpp"

//Constructeur
MotorModule::MotorModule(Body* body) 
	: Module(), m_body(body) {
}

//Destructeur
MotorModule::~MotorModule(){
}

//Surchage opérateur <<
void MotorModule::operator<<(Order order){
	m_mutex.lock();
	m_orders.push_back(order);
	m_mutex.unlock();
}
