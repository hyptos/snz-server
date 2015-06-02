/**
 * File: visualstimulus.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on June 2, 2015, 9:20 PM
 */

#ifndef VISUAL_STIMULUS_HPP
#define VISUAL_STIMULUS_HPP

#include <iostream>
#include <map>
#include <utility>

#include "stimulus.hpp"
#include "Model/constantes.hpp"

//! VisualStimulus
/*!
 * La classe VisualStimulus contient une liste
 * de position de corps dans l'environnement.
 */
class VisualStimulus : public Stimulus {

	public :

		/// Constructeur par défaut
		VisualStimulus();

		/// Constructeur par Copie
		VisualStimulus(const VisualStimulus&);

		/// Constructeur avec Paramètres
		VisualStimulus(std::map<EntityType, std::pair<double, double>>);



		/// Retourne la listes des positions
		std::map<EntityType, std::pair<double, double>>	getDatum() const;

		/// Retourne le nombre de positions stockées
		int getSize() const;



		//Ajoute un élement à la liste
		void insertData(EntityType, std::pair<double, double>);

	private :

		std::map<EntityType, 
			std::pair<double, double>> m_datum;	///< Liste de positions

};

#endif // VISUAL_STIMULUS_HPP