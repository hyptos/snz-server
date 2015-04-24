/**
 * File: ear.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 19, 2015, 4:47 PM
 */

#ifndef EAR_HPP
#define EAR_HPP

#include <iostream>
#include <list>
#include <thread>
#include <chrono>

#include "../../../../module.hpp"
#include "../../Brains/brain.hpp"
#include "../../../../Stimuli/soundstimulus.hpp"

class Brain;

//! Ear Class
/*!
 * \brief La classe Ear est un module
 * du body, il implémente le sens l'ouïe
 * de l'agent. Sans ce module, un agent
 * ne peut capter les stimuli sonore de
 * l'environnement.
 */
class Ear : public Module{

    public :

        ///Constructeur
        Ear();

        ///Destructeur
        virtual ~Ear();

        ///Fonction d'ajout à la liste
        virtual void hear(SoundStimulus&);

        ///Surchage de l'opérateur ()
        /*!
         * Les modules composant une couche d'un agent,
         * ici le body, est un foncteur qui sera lancé
         * dans une thread.
         *
         * remarque : le mieux serait de faire un héritage
         * de la classe thread comme on peut le faire en JAVA
         */
        virtual void operator()();

        ///Retourne le lien vers le Brain de l'agent
        virtual Brain* getBrain();

        ///Modifie le lien vers le Brain de l'agent
        virtual void setBrain(Brain*);

    protected :

        Brain*  m_brain;

        std::list<SoundStimulus> m_thingsHeard;   ///< Liste des sons perçut par le body à traiter
};

#endif // EAR_HPP

