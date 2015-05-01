/**
 * File: brain.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 20, 2015, 8:46 AM
 */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <list>
#include <thread>
#include <chrono>

#include "Model/module.hpp"
#include "Model/Entities/Agents/Bodies/body.hpp"
#include "Model/Stimuli/soundstimulus.hpp"

class Body;

//! Brain Class
/*!
 * \brief La classe Brain est une
 * classe mère abstraite contenant
 * les attributs et méthodes communes
 * à toutes ses classes filles.
 *
 * l'opérateur () défini la "boucle d'actions"
 * fait par l'agent. Il doit être surchagé par
 * le programmeur dans une classe fille.
 */
class Brain : public Module {

    public :

        ///Constructeur
        Brain();

        ///Destructeur (virtuel pur)
        virtual ~Brain() = 0;

        ///Relit le Brain à un Body
        /*!
         * \brief par défaut le lien entre
         * le Brain et le Body est à null,
         * il faut utiliser cette fonction
         * pour relier le Brain au Body
         */
        virtual void connect_to_body(Body*);

        ///Indique au Brain un Stimulus sonore capté par le Body
        /*!
         * \brief Les actions faites lors de la réception d'un
         * stimulus difère d'un Brain à l'autre, c'est donc au
         * programmeur de réimplémenter cette fonction
         */
        virtual void addSoundStimulus(SoundStimulus&) = 0;

    protected :

        Body* m_body;   ///< Lien vers le Body de l'agent
};

#endif // BRAIN_HPP

