/**
 * File: map_tree.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 24, 2015, 5:14 PM
 */

#ifndef MAP_TREE_HPP
#define MAP_TREE_HPP

#include <iostream>

//! MapTree Class
/*!
 * La classe MapTree est un arbre binaire
 * de recherche basé sur la map de l'environnement
 * qu"il divise en "zone" jusqu'à ce que l'aire
 * de chaque zone atteingne une certaine valeure.
 *
 * Il retourne l'élement T stocké dans la zone où se 
 * trouve un point (x,z) passé en paramètre.
 */
template<typename T>
class MapTree{

	public :

		///Constructeur par défaut
		MapTree();

		///Destructeur
		~MapTree();
};

#endif // MAP_TREE_HPP