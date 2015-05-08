#include "reflexsensor.hpp"

//Constructeur par défaut
ReflexSensor::ReflexSensor(){
}

//Constructeur avec paramètres
ReflexSensor::ReflexSensor(std::vector<MotorModule*> modules){
	for(std::vector<MotorModule*>::iterator it = modules.begin() ; it != modules.end() ; it++){
		m_motors.push_back(*it);
	}
}

//Destructeur
ReflexSensor::~ReflexSensor(){
	m_motors.clear();
}


//Ajoute un module moteur
void ReflexSensor::addMotor(MotorModule* module){
	bool ok = true;

	for(std::vector<MotorModule*>::iterator it = m_motors.begin() ; it != m_motors.end() && ok ; it++){
		if(*it == module)
			ok = false;
	}

	if(ok)
		m_motors.push_back(module);
}
