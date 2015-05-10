#include "moveorder.hpp"

//Constructeur par défaut
MoveOrder::MoveOrder() 
	: Order(OrderType::MOVE), m_x(0.0), m_z(0.0){
}

//Constructeur avec paramètre
MoveOrder::MoveOrder(double x, double z) 
	: Order(OrderType::MOVE), m_x(x), m_z(z){
}

//Constructeur par copie
MoveOrder::MoveOrder(const MoveOrder& order) 
	: Order(order.getType()), m_x(order.getX()), m_z(order.getZ()){	
}

//Destructeur
MoveOrder::~MoveOrder(){
}

//Retourne coordonnée x
double MoveOrder::getX() const{
	return m_x;
}

//Retourne coordonnée z
double MoveOrder::getZ() const{
	return m_z;
}
