/**
 * File: moveorder.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May 8, 2015, 1:37 PM
 */

#ifndef MOVE_ORDER_HPP
#define MOVE_ORDER_HPP

#include <iostream>

#include "order.hpp"

//! MoveOrder Class
/*!
 * La classe MoveOrder indique une action
 * move et le point (x, z) à atteindre.
 */
class MoveOrder : public Order {
	
	public :

		///Constructeur par défaut
		MoveOrder();

		///Constructeur avec paramètres
		/*!
		 * \param x
		 * \param z
		 */
		MoveOrder(double, double);

		///Constructeur par copie
		MoveOrder(const MoveOrder&);

		///Destructeur
		virtual ~MoveOrder();

		///Retourne la coordonnée x du point à atteindre
		virtual double getX();

		///Retourne la coordonnée z du point à atteindre
		virtual double getZ();		

	protected :

		const double m_x;	///< coordonnée x du point à atteindre
		const double m_z;	///< coordonnée z du point à atteindre
};

#endif //MOVE_ORDER_HPP
