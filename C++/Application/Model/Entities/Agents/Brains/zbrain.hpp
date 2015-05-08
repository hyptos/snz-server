/**
 * File: zbrain.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 20, 2015, 4:11 PM
 */

#ifndef ZBRAIN_HPP
#define ZBRAIN_HPP

#include <iostream>

#include "brain.hpp"
#include "Model/Stimuli/soundstimulus.hpp"

//! ZBrain Class
/*!
 * La classe ZBrain implémente
 * le comportement d'un agent "Zombie".
 */
class ZBrain : public Brain {

    public :

        ///Constructeur
        ZBrain();

        ///Destructeur
        virtual ~ZBrain();

        ///Implémente les opérations faites lorsque le Body indique un son au Brain
        virtual void addSoundStimulus(SoundStimulus&);

        ///Implémente la boucle d'actions de l'agent
        virtual void operator ()();
};

#endif // ZBRAIN_HPP

