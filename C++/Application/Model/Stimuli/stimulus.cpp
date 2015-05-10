#include "stimulus.hpp"

//Constructeur
Stimulus::Stimulus(StimulusType type)
    : m_type(type){
}

//Constructeur par copie
Stimulus::Stimulus(const Stimulus& stimulus) 
	: m_type(stimulus.getType()){
}

//Destructeur
Stimulus::~Stimulus(){
}

//Retourne le type du Stimulus
StimulusType Stimulus::getType() const{
    return m_type;
}
