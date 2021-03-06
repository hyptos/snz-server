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


//! SoundStimulus class
/*!
 * La classe SoundStimulus contient les informations
 * concernant un son propagé dans l'envrionnement et
 * capté par un ou plusieurs corps.
 */
class SoundStimulus : public Stimulus {

    public :

        ///Constructeur
        SoundStimulus(const double&,const double&,const double&,const double&);

        ///Constructeur par copie
        SoundStimulus(const SoundStimulus&);

        ///Destructeur
        virtual ~SoundStimulus();

        ///Retourne la coordonnée X du Son dans l'Environnment
        virtual double getX() const;

        ///Retourne la coordonnée Z du Son dans l'Environnment
        virtual double getZ() const;

        ///Retourne la coordonnée Y du Son dans l'Environnment
        virtual double getY() const;

        ///Retourne la Puissance du Son
        /*!
         * Plus un son a de puissance, plus il a de chance de s'entendre de loin.
         */
        virtual double getPower() const;

    protected :

        const double m_x;       ///< Coordonnée X du Son dans l'Environnement
        const double m_z;       ///< Coordonnée Z du Son dans l'Environnement
        const double m_y;       ///< Coordonnée Y du Son dans l'Environnement

        const double m_power;   ///< Puissance du Son
};

#endif // SOUNDSTIMULUS_HPP

