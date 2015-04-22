/**
 * File: infoentity.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:06 PM
 */

#ifndef INFO_ENTITY_HPP
#define INFO_ENTITY_HPP

#include <iostream>

#include "../constante.hpp"

//! InfoEntity Class
/*!
 * La classe InfoEntity contient les données
 * concernant une entité. (à instant t non précisé)
 */
class InfoEntity{
    
    public :

        ///Constructeur par défaut
        InfoEntity();

        ///Constructeur avec paramètres
        InfoEntity(unsigned long long&, EntityType&, double&, double&, double&, double&, double&, double&);

        ///Constructeur par copie
        InfoEntity(const InfoEntity&);

        ///Destructeur
        virtual ~InfoEntity();




        ///Retourne l'id de l'entité
        virtual unsigned long long getEntity() const;

        ///Retourne le type de l'entité
        virtual EntityType getType() const;

        ///Retourne la coordonnée X de l'entité dans l'environnement
        virtual double getX() const;

        ///Retourne la coordonnée Z de l'entité dans l'environnement
        virtual double getZ() const;

        ///Retourne la coordonnée Y de l'entité dans l'environnement
        virtual double getY() const;

        ///Retourne la coordonnée X du vecteur direction de l'entité
        virtual double getDX() const;

        ///Retourne la coordonnée Z du vecteur direction de l'entité
        virtual double getDZ() const;

        ///Retourne la coordonnée Y du vecteur direction de l'entité
        virtual double getDY() const;




        ///Modifie l'ID de l'entité
        virtual void setEntity(unsigned long long);

        ///Modifie le Type de l'entité
        virtual void setType(EntityType);

        ///Modifie la coordonnée X
        virtual void setX(double);

        ///Modifie la coordonnée Z
        virtual void setZ(double);

        ///Modifie la coordonnée Y
        virtual void setY(double);

        ///Modifie la coordonnée DX
        virtual void setDX(double);

        ///Modifie la coordonnée DZ
        virtual void setDZ(double);

        ///Modifie la coordonnée DY
        virtual void setDY(double);

    protected :

        unsigned long long m_entity;  ///< Id de l'entité

        EntityType m_type;            ///< Type de l'entité

        double m_x;                   ///< Coordonnée X de l'entité dans l'environnement
        double m_z;                   ///< Coordonnée Z de l'entité dans l'environnement
        double m_y;                   ///< Coordonnée Y de l'entité dans l'environnement

        double m_dx;                  ///< Coordonnée X du vecteur direction de l'entité
        double m_dz;                  ///< Coordonnée Z du vecteur direction de l'entité
        double m_dy;                  ///< Coordonnée Y du vecteur direction de l'entité

};

#endif // INFO_ENTITY_HPP

