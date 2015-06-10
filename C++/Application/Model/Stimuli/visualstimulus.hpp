/**
 * File: visualstimulus.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on June 2, 2015, 9:20 PM
 */

#ifndef VISUAL_STIMULUS_HPP
#define VISUAL_STIMULUS_HPP

#include <iostream>
#include <list>
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
		VisualStimulus(std::list<std::pair<EntityType, 
			std::pair<std::pair<double, double>, std::pair<double, double>>>>);

		/// Destructeur
		virtual ~VisualStimulus();


		/// Retourne la listes des positions
		virtual std::list<std::pair<EntityType, 
		std::pair<std::pair<double, double>, 
		std::pair<double, double>>>>	getDatum() const;

		/// Retourne le nombre de positions stockées
		virtual int getSize() const;


		//Ajoute un élement à la liste
		virtual void pushData(EntityType, 
			std::pair<double, double>, std::pair<double, double>);

	private :

		std::list<std::pair<EntityType, 
			std::pair<std::pair<double, double>, 
			std::pair<double, double>>>> m_datum; ///< Liste de positions

};

#endif // VISUAL_STIMULUS_HPP