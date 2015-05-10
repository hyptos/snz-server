/**
 * File: body.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 19, 2015, 11:21 AM
 */

#ifndef BODY_HPP
#define BODY_HPP

#include <iostream>
#include <cmath>
#include <list>
#include <utility>
#include <thread>
#include <chrono>

#include "Model/constantes.hpp"
#include "Model/environment.hpp"
#include "Model/Entities/entity.hpp"
#include "Model/Info/infoaction.hpp"

class Environment;

class Entity;


//! Body Class
/*!
 * La classe body regroupe tous les attributs
 * et méthodes communs aux Body des différents
 * Agents du SMA.
 */
class Body : Module {

    public :

        ///Constructeur
        /*!
         * Initialise les données d'un corps dans l'environment
         */
        Body(Environment*, double, double, double, double, double, double, Entity*);

        ///Destructeur
        virtual ~Body();

        

        ///Retourne un pointeur sur l'environnement
        virtual Environment* getEnvironment();

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

        ///Modifie les Coordonnées X, Z et Y de l'entité dans l'environnement
        virtual void setCoordinates(double, double, double);

        ///Modifie les Coordonnées X, Z et Y du vecteur direction de l'entité
        virtual void setDirection(double, double, double);


        ///Indique au corps une action faite sur lui
        virtual void operator<<(InfoAction);

        ///Surchage de l'operateur ()
        /*!
         * par défaut ne fait rien.
         */
        virtual void operator()();


        ///Vérouille le mutex du body
        virtual void lock();

        ///Dévérouille le mutex du body
        virtual void unlock();

    protected :

        Environment* m_environment;     ///< Lien vers l'Environnement de déplacement du Body

        double m_x;                     ///< Coordonnée X de l'entité dans l'environnement
        double m_z;                     ///< Coordonnée Z de l'entité dans l'environnement
        double m_y;                     ///< Coordonnée Y de l'entité dans l'environnement

        double m_dx;                    ///< Coordonnée X du vecteur direction de l'entité
        double m_dz;                    ///< Coordonnée Z du vecteur direction de l'entité
        double m_dy;                    ///< Coordonnée Y du vecteur direction de l'entité

        Entity*  m_entity;              ///< Lien vers l'Agent
};

#endif // BODY_HPP

