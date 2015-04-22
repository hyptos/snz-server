#include "stimulus.hpp"

//Constructeur
Stimulus::Stimulus(StimulusType type)
    : m_type(type){
}

//Destructeur
Stimulus::~Stimulus(){
}

//Retourne le type du Stimulus
StimulusType Stimulus::getType(){
    return m_type;
}
