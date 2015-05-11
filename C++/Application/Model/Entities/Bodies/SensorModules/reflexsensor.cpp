#include "reflexsensor.hpp"

//Constructeur par défaut
ReflexSensor::ReflexSensor(RABody* body) 
	: SensorModule(SensorType::REFLEX, body) {
}

//Constructeur avec paramètres
ReflexSensor::ReflexSensor(std::vector<MotorModule*> modules, RABody* body) 
	: SensorModule(SensorType::REFLEX, body) {
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
	m_motors.push_back(module);
}
