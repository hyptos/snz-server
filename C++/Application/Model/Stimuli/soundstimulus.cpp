#include "soundstimulus.hpp"

//Constructeur
SoundStimulus::SoundStimulus(const double &x, const double &z, const double &y, const double &power)
    : Stimulus(StimulusType::SOUND), m_x(x), m_z(z), m_y(y), m_power(power){
}

//Constructeur par copie
SoundStimulus::SoundStimulus(const SoundStimulus &sound)
    : Stimulus(StimulusType::SOUND), m_x(sound.getX()), m_z(sound.getZ()), m_y(sound.getY()), m_power(sound.getPower()){
}

//Destructeur
SoundStimulus::~SoundStimulus(){
}

//Retourne la coordonnée X du son
double SoundStimulus::getX() const{
    return m_x;
}

//Retourne la coordonnée Z du son
double SoundStimulus::getZ() const{
    return m_z;
}

//Retourne la coordonnée Y du son
double SoundStimulus::getY() const{
    return m_y;
}

//Retourne la puissance du son
double SoundStimulus::getPower() const{
    return m_power;
}
