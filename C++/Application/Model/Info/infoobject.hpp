/**
 * File: infoobject.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May the 4th be with you, 2015, 6:15 PM
 */

#ifndef INFO_OBJECT_HPP
#define INFO_OBJECT_HPP

#include <iostream>

#include "Model/constantes.hpp"
#include "infoentity.hpp"


//! InfoObject Class
/*!
 * La classe InfoObject contient les données
 * concernant un objet. (à instant t non précisé)
 */
class InfoObject : public InfoEntity {

	public : 

		///Constructeur par défaut
		InfoObject();

		///Constructeur avec paramètres
		InfoObject(unsigned long long, ObjectType, double, double, double, double, double, double);

		///Constructeur par copie
		InfoObject(const InfoObject&);

		///Destructeur
		virtual ~InfoObject();

		///Retourne le type de l'objet
		virtual ObjectType getObjectType() const;

		///Modifie le type de l'objet
		virtual void setObjectType(ObjectType);

	protected : 

		ObjectType m_otype;		///< Type de l'objet
};

#endif