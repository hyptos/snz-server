#include "moveorder.hpp"

//Constructeur par défaut
MoveOrder::MoveOrder() 
	: Order(OrderType::MOVE), m_x(0.0), m_z(0.0){
}

//Constructeur avec paramètre
MoveOrder::MoveOrder(double x, double z) 
	: Order(OrderType::MOVE), m_x(x), m_z(z){
}

//Destructeur
MoveOrder::~MoveOrder(){
}

//Retourne coordonnée x
double MoveOrder::getX(){
	return m_x;
}

//Retourne coordonnée z
double MoveOrder::getZ(){
	return m_z;
}
