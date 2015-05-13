#include "sensormodule.hpp"

//Constructeur
SensorModule::SensorModule(SensorType type, Body* body) 
	: Module(), m_type(type), m_acuity(1.0), m_body(body) {
}

//Destructeur
SensorModule::~SensorModule(){
	while(!m_stimuli.empty()){
		delete m_stimuli.back();
		m_stimuli.pop_back();
	}
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
void SensorModule::operator<<(Stimulus* stimulus){

	Stimulus *cpy = new Stimulus(*stimulus);

	m_mutex.lock();
	m_stimuli.push_back(cpy);
	m_mutex.unlock();
}
