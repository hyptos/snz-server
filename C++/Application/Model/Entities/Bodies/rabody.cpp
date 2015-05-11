#include "rabody.hpp"

#include "Model/Entities/Agents/reactiveagent.hpp"
#include "SensorModules/reflexsensor.hpp"
#include "MotorModules/motormodule.hpp"

//Constructeur
RABody::RABody(Environment* env, double x, double z, double y, double dx, double dz, double dy, ReactiveAgent* ragent) 
	: Body(env, x, z, y, dx, dz, dy, ragent), m_speed(0.0) {
}

//Destructeur
RABody::~RABody(){
	//On delete tous les modules moteurs
	while(!m_motors.empty()){
		m_motors.back()->stop();
		delete m_motors.back();
		m_motors.pop_back();
	}

	//On delete tous les modules reflex senseur
	while(!m_reflexes.empty()){
		m_reflexes.back()->stop();
		delete m_reflexes.back();
		m_reflexes.pop_back();
	}
}

//Ajoute un module moteur au corps
void RABody::addMotor(MotorModule* motor){
	m_motors.push_back(motor);
}

//Ajoute un module senseur au corps
void RABody::addSensor(SensorModule* sensor){
	if(sensor->getType() == SensorType::REFLEX)
		m_reflexes.push_back(dynamic_cast<ReflexSensor*>(sensor));
}

//Retourne la vitesse de l'agent
double RABody::getSpeed(){
	return m_speed;
}

//Modifie la vitesse de l'agent
void RABody::setSpeed(double speed){
	m_speed = speed;
}

//Surcharge de l'opérateur <<
void RABody::operator<<(Stimulus* stimulus){
	
	//For each sensor
	for(std::vector<ReflexSensor*>::iterator it = m_reflexes.begin() ; it != m_reflexes.end() ; it++)
		*(*it) << stimulus;
}


