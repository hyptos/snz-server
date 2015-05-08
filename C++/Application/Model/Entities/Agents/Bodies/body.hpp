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

#include "Model/Entities/Agents/Brains/brain.hpp"
#include "Model/constantes.hpp"
#include "Model/module.hpp"
#include "SensorModules/ear.hpp"
#include "Model/Stimuli/soundstimulus.hpp"
#include "Model/environment.hpp"

class Brain;

class Ear;

class Environment;

class Agent;


//! Body Class
/*!
 * La classe body regroupe tous les attributs
 * et méthodes communs aux Body des différents
 * Agents du SMA.
 */
class Body : public Module {

    public :

        ///Constructeur
        Body(Environment*, Agent*);

        ///Destructeur
        virtual ~Body();

        ///Retourne le lien vers le Module Ear du body
        virtual Ear* getEar() const;

        ///Connecte le Body de l'agent à son Brain
        virtual void connect_to_brain(Brain*);

        ///Function appellée lorsque que le Body "capte" un son
        virtual void catchSound(SoundStimulus&);

        ///Function appellée par le Brain pour définir une destination
        virtual void moveTo(double, double);

        ///Fonction appellée par le Brain pour définir une action à faire par le Body
        virtual void addActionTodo(BrainOrderType, unsigned long long = 0);

        ///Surchage de l'opérateur (), contient la boucle d'actions du Body
        virtual void operator()();

    protected :

        Environment* m_environment;         ///< Lien vers l'Environnement de déplacement du Body

        Agent*  m_agent;                    ///< Lien vers l'Agent

        Brain*  m_brain;                    ///< Lien vers le Brain de l'agent

        Ear* m_ear;                         ///< Module gérant l'ouïe de l'agent

        std::list<std::pair<BrainOrderType, unsigned long long>> m_todo;   ///< Liste d'actions à faire par le body (défini par le Brain)
        //TODO
        //double height;
        //double width;
};

#endif // BODY_HPP

