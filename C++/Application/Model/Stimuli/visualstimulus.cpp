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
	m_datum.clear();
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
void VisualStimulus::pushData(EntityType type, std::pair<double, double> pos){
	std::pair<EntityType, std::pair<double, double>> data;
	data.first = type;
	data.second.first = pos.first;
	data.second.second = pos.second;
	m_datum.push_back(data);
}