#include "order.hpp"

//Constructeur
Order::Order(OrderType type) : m_type(type) {
}

//Constructeur par copie
Order::Order(const Order& order) 
	: m_type(order.getType()){
}

//Destructeur
Order::~Order(){
}

//Retourne le type de l'ordre
OrderType Order::getType() const{
	return m_type;
}
