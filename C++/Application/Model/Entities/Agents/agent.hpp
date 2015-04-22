/**
 * File: agent.hpp
 * Author: Antoine
 *
 * Created on April 14, 2015, 5:13 PM
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>

#include <QObject>

#include "../entity.hpp"
#include "Bodies/body.hpp"
#include "Brains/brain.hpp"

//! Agent Class
/*!
 * La classe Agent implémente toutes les données
 * communes de tous les agents.
 *
 * Hérite de Entity
 */
class Agent : public Entity{

    Q_OBJECT

    public :

        ///Constructeur
        Agent(unsigned long long, EntityType, EntityState, double, double, double, double, double, double, Body*, Brain*);

        ///Destructeur
        virtual ~Agent() = 0;

        ///Retourne la vitesse de l'agent
        virtual double getSpeed() const;

        ///Retourne un pointeur sur le Body de l'agent
        virtual Body* getBody();

        ///Retourne un pointeur sur le Brain de l'agent
        virtual Brain* getBrain();

    public slots :

        ///Modifie la coordonnée X de l'entité
        virtual void setX(double);

        ///Modifie la coordonnée Z de l'entité
        virtual void setZ(double);

        ///Modifie la coordonnée Y de l'entité
        virtual void setY(double);

        ///Modifie les coordonnées X, Z et Y de l'entité
        virtual void setCoordinates(double, double, double);

        ///Modifie la vitesse
        virtual void setSpeed(double speed);
        
    protected :

        double m_speed;     ///< Vitesse de l'agent
        Body* m_body;       ///< Pointeur vers le corps de l'agent
        Brain*  m_brain;    ///< Pointeur vers le cerveau de l'agent
};

#endif // AGENT_HPP

