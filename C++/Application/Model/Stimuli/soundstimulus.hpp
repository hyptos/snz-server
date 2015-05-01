/**
 * File: soundstimulus.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 20, 2015, 10:12 PM
 */

#ifndef SOUNDSTIMULUS_HPP
#define SOUNDSTIMULUS_HPP

#include <iostream>

#include "stimulus.hpp"
#include "Model/constantes.hpp"

class SoundStimulus : public Stimulus {

    public :

        ///Constructeur
        SoundStimulus(const double&,const double&,const double&,const double&);

        ///Constructeur par copie
        SoundStimulus(const SoundStimulus&);

        ///Destructeur
        ~SoundStimulus();

        ///Retourne la coordonnée X du Son dans l'Environnment
        double getX() const;

        ///Retourne la coordonnée Z du Son dans l'Environnment
        double getZ() const;

        ///Retourne la coordonnée Y du Son dans l'Environnment
        double getY() const;

        ///Retourne la Puissance du Son
        /*!
         * Plus un son a de puissance, plus il a de chance de s'entendre de loin.
         */
        double getPower() const;

    protected :

        const double m_x;       ///< Coordonnée X du Son dans l'Environnement
        const double m_z;       ///< Coordonnée Z du Son dans l'Environnement
        const double m_y;       ///< Coordonnée Y du Son dans l'Environnement

        const double m_power;   ///< Puissance du Son
};

#endif // SOUNDSTIMULUS_HPP

