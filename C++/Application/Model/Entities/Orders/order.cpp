#include "order.hpp"

//Constructeur
Order::Order(OrderType type) : m_type(type) {
}

//Destructeur
Order::~Order(){
}

//Retourne le type de l'ordre
OrderType Order::getType(){
	return m_type;
}
