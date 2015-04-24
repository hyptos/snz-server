/**
 * File: entity.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 21, 2015, 5:09 PM
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <thread>

#include "Model/constantes.hpp"
#include "Model/Info/infoentity.hpp"

class Agent;

//! Entity Class
/*!
 * \brief La classe Entity regroupe les
 * attributs et méthodes de toutes entitées
 * faisant parties du modèle (agents, objets,
 * joueurs, etc..)
 */
class Entity {

    public :

        ///Constructeur
        Entity(unsigned long long, EntityType, double, double, double, double, double, double);

        ///Destructeur
        virtual ~Entity() = 0;

        ///Retourne l'ID de l'Entité
        virtual unsigned long long getId() const;

        ///Retourne le Type de l'Entité
        virtual EntityType getType() const;

        ///Retourne la Coordonnée X de l'Entité dans l'Environnement
        virtual double getX() const;

        ///Retourne la Coordonnée Z de l'Entité dans l'Environnement
        virtual double getZ() const;

        ///Retourne la Coordonnée Y de l'Entité dans l'Environnement
        virtual double getY() const;

        ///Retourne la Coordonnée X du vecteur direction de l'Entité
        virtual double getDX() const;

        ///Retourne la Coordonnée Z du vecteur direction de l'Entité
        virtual double getDZ() const;

        ///Retourne la Coordonnée Y du vecteur direction de l'Entité
        virtual double getDY() const;

        ///Retourne les informations concernant l'Entité
        virtual InfoEntity getInfo() const;



        //Modifie l'ID de l'Entité
        virtual void setId(unsigned long long);

        //Modifie le Type de l'Entité
        virtual void setType(EntityType);

        ///Modifie la Coordonnée X de l'Entité dans l'Environnement
        virtual void setX(double);

        ///Modifie la Coordonnée Z de l'Entité dans l'Environnement
        virtual void setZ(double);

        ///Modifie la Coordonnée Y de l'Entité dans l'Environnement
        virtual void setY(double);

        ///Modifie la Coordonnée X du vecteur direction de l'Entité
        virtual void setDX(double);

        ///Modifie la Coordonnée Z du vecteur direction de l'Entité
        virtual void setDZ(double);

        ///Modifie la Coordonnée Y du vecteur direction de l'Entité
        virtual void setDY(double);


        ///Retourne si deux Entités sont égales ou non
        /*!
         * Le test se fait juste sur l'ID
         */
        virtual bool operator ==(const Entity&);

    protected :

        unsigned long long m_id;  ///< Id de l'entité

        EntityType m_type;        ///< Type de l'entité

        double m_x;                     ///< Coordonnée X de l'entité dans l'environnement
        double m_z;                     ///< Coordonnée Z de l'entité dans l'environnement
        double m_y;                     ///< Coordonnée Y de l'entité dans l'environnement

        double m_dx;                    ///< Coordonnée X du vecteur direction de l'entité
        double m_dz;                    ///< Coordonnée Z du vecteur direction de l'entité
        double m_dy;                    ///< Coordonnée Y du vecteur direction de l'entité
};

#endif // ENTITY_HPP

