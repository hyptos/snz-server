#include "zbody.hpp"

#include "MotorModules/leg.hpp"
#include "SensorModules/zear.hpp"
#include "SensorModules/zeye.hpp"
#include "Model/environment.hpp"
#include "Model/Entities/Agents/reactiveagent.hpp"

//Constructeur
ZBody::ZBody(Environment* env, double x, double z, double y, double dx, double dz, double dy, ReactiveAgent* agent)
	: RABody(env, x, z, y, dx, dz, dy, agent) {

		//Création du module Leg
		Leg *leg = new Leg(this);
		addMotor(leg);

		//Création du module ZEar
		ZEar *ear = new ZEar(this);
		ear->addMotor(leg);
		addSensor(ear);

		//Création du module ZEye
		ZEye *eye = new ZEye(this);
		eye->addMotor(leg);
		addSensor(eye);

		//Lancement des threads
		std::thread th_leg(Module::run, leg);
		th_leg.detach();
		
		std::thread th_ear(Module::run, ear);
		th_ear.detach();

		std::thread th_eye(Module::run, eye);
		th_eye.detach();
}

ZBody::~ZBody(){
}
