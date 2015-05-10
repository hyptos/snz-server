#include "sensormodule.hpp"

//Constructeur
SensorModule::SensorModule(SensorType type, Body* body) 
	: Module(), m_type(type), m_body(body) {
}

//Destructeur
SensorModule::~SensorModule(){
}

//Retourne le type du senseur
SensorType SensorModule::getType() const{
	return m_type;
}

//Retourne l'acuité du senseur
double SensorModule::getAcuity() const{
	return m_acuity;
}

//Modifie l'acuité du senseur
void SensorModule::setAcuity(double acuity){
	m_acuity = acuity;
}

//Surchage opérateur 
void SensorModule::operator<<(Stimulus stimulus){
	m_mutex.lock();
	m_stimuli.push_back(stimulus);
	m_mutex.unlock();
}
