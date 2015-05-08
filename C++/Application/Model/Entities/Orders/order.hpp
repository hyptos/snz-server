/**
 * File: order.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 8, 2015, 1:37 PM
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>

#include <Model/constantes.hp>

//! Order class
/*!
 * La classe Order est la classe mère
 * de chaque classe définissant un ordre
 * du cerveau ou d'un senseur réflexe sur
 * un module moteur de l'agent (à spécialiser)
 * si besoin.
 */
class Order{

	public :

		///Constructeur
		Order(OrderType);

		///Destructeur
		virtual ~Order();

		///Retourne le type de l'ordre
		virtual OrderType getType();

	protected :

		const OrderType m_type;	///< Type de l'ordre
};

#endif // ORDER_HPP