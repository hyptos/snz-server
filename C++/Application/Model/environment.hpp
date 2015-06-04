/**
 * File: environnement.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 20, 2015, 11:14 AM
 */

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cmath>

#include "Stimuli/soundstimulus.hpp"
#include "Stimuli/visualstimulus.hpp"
#include "constantes.hpp"
#include "Info/infoentity.hpp"

class Body;
class RABody;

//! Environment Class
/*!
 * \brief La classe Environment implémente l'environnement
 * de déplacement des entités.
 */
class Environment {

    public :

        ///Constructeur
        Environment(const int&, const int&);

        ///Destructeur
        ~Environment();

        ///Retourne la longueur de l'environnement
        int getLength();

        ///Retourne la largeur de l'environnement
        int getWidth();

        ///Retourne la hauteur de l'environnement
        int getHeight();

        ///Retourne si un déplacement entre un point (x1,z1) et un point (x2,z2) est valide ou non
        bool validTravel(double,double,double,double);

        ///Retourne les données autour d'un point (x,z), ex: la heightmap, les objets, les autres agents
        void getArea(double,double);

        ///Ajoute un lien vers un agent dans l'environnement
        void addEntity(EntityType, Body*);

        ///Emet un stimulus sonore à un point (x,z,y) dans l'environnement
        void emitSound(double,double,double,double);

        ///Retourne une liste d'info sur les corps présent dans un cone de vision
        VisualStimulus getVisualStimulus(double,double,double,double,double);

    private :

        const int m_length;         ///< Longueur de l'environnement (Axe X)
        const int m_width;          ///< Largeur de l'environnement (Axe Z)
        const int m_height;         ///< Hauteur de l'environnement (Axe Y)

        std::list<Body*> m_bodies;  ///< Liste des bodies simple reliés à l'environnement
        std::list<RABody*> m_agents;    ///< Liste des corps des agents
};

#endif // ENVIRONMENT_HPP

