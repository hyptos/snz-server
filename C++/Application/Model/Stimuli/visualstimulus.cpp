#include "visualstimulus.hpp"

// Contructeur par défaut
VisualStimulus::VisualStimulus() 
	: Stimulus(StimulusType::VISUAL){
}

// Constructeur par copie
VisualStimulus::VisualStimulus(const VisualStimulus& stimulus) 
	: Stimulus(StimulusType::VISUAL), m_datum(stimulus.getDatum()){
}

// Constructeur avec arguments
VisualStimulus::VisualStimulus(
	std::list<std::pair<EntityType, std::pair<double, double>>> datum)
	: Stimulus(StimulusType::VISUAL), m_datum(datum){
}

// Destructeur
VisualStimulus::~VisualStimulus(){
}



// Retourne la map des body
std::list<std::pair<EntityType, std::pair<double, double>>>
VisualStimulus::getDatum() const {
	return m_datum;
}

// Retourne la taille de la liste
int VisualStimulus::getSize() const {
	return m_datum.size();
}


// Ajoute une donnée à la liste de donnée
void VisualStimulus::pushData(EntityType, std::pair<double, double>){
}
