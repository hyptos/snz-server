/**
 * File: stimulus.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 20, 2015, 10:06 PM
 */

#ifndef STIMULUS_HPP
#define STIMULUS_HPP

#include <iostream>

#include "Model/constantes.hpp"

//! Stimulus Class
/*!
 * \brief La classe Stimulus est la classe
 * abstraite mère de tout stimulus de l'environnement
 * sur les agents, qu'il soit sonore, visuel
 * ou olfactif.
 */
class Stimulus {

    public :

        ///Constructeur
        Stimulus(StimulusType);

        ///Constructeur par copie
        Stimulus(const Stimulus&);

        ///Destructeur
        virtual ~Stimulus();

        ///Retourne le type du Stimulus
        virtual StimulusType getType() const;

    protected :

        const StimulusType m_type;

};

#endif // STIMULUS_HPP

