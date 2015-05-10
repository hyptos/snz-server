#include "sensormodule.hpp"

//Constructeur
SensorModule::SensorModule() 
	: Module() {
}

//Destructeur
SensorModule::~SensorModule(){
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
