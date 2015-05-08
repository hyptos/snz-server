/**
 * File: map_tree.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 24, 2015, 5:14 PM
 */

#ifndef MAP_TREE_HPP
#define MAP_TREE_HPP

#include <iostream>
#include <algorithm>
#include <vector>

//! MapTree Class
/*!
 * La classe MapTree est un arbre binaire
 * de recherche basé sur la map de l'environnement
 * qu"il divise en "zone" jusqu'à ce que l'aire
 * de chaque zone atteigne une certaine valeure.
 *
 * Il retourne l'élement T stocké dans la zone où se 
 * trouve un point (x,z) passé en paramètre.
 */
template<typename T>
class MapTree{
	
	public :

		///Constructeur
		/*!
		 * \param length : longueur de la zone
		 * \param width : largeur de la zone
		 * \param max : taille maximum d'une zone (length et width <= max)
		 * \param detph : profondeur du noeud dans l'arbre
		 */
		MapTree(double length, double width, double max, int depth) 
			: m_depth(depth), m_length(length), m_width(width), m_right(NULL), m_left(NULL), m_element(NULL){

			std::cout << "MapTree Constructeur, depth : " << m_depth << " size : (" << m_length << ", " << m_width << ")" << std::endl;

			//Si on a atteint la taille minimum
			if(m_length <= max && m_width <= max){
				std::cout << "Feuille" << std::endl;
				m_element = new T;
			}
			else{ //Si il faut encore diviser la zone
				std::cout << "Divisions en deux nodes" << std::endl;
				
				//Si profondeur est impair, on divise la largeur
				if(m_depth % 2){
					//Si impair, le fils gauche aura une largeur plus grande
					m_left = new MapTree<T>(m_length, m_width / 2.0, max, m_depth+1);
					m_right = new MapTree<T>(m_length, m_width / 2.0, max, m_depth+1);
				}
				else // Sinon, on divise la longueur
				{
					m_left = new MapTree<T>(m_length / 2.0, m_width, max, m_depth+1);
					m_right = new MapTree<T>(m_length / 2.0, m_width, max, m_depth+1);
				}
			}
		}

		///Destructeur
		virtual ~MapTree(){
			std::cout << "MapTree ~Destructeur" << std::endl;
			if(m_element != NULL)
				delete m_element;

			if(m_right != NULL)
				delete m_right;

			if(m_left != NULL)
				delete m_left;
		}

		//Retourne la profondeur de l'arbre à partir du noeud
		virtual int getDepth() const{
			std::cout << "MapTree getDepth" << std::endl;
			
			if(m_element != NULL)
				return m_depth;

			int rdepth = 0;
			int ldepth = 0;
		

			if(m_right != NULL)
				rdepth = m_right->getDepth();

			if(m_left != NULL)
				ldepth = m_left->getDepth();

			return std::max(rdepth, ldepth);
		}

		///Retourne le nombre de feuilles de l'arbre
		virtual int getNbLeaf() const{

			std::cout << "MapTree getNbLeaf" << std::endl;

			if(m_element != NULL)
				return 1;

			int right = 0;
			int left = 0;

			if(m_right != NULL)
				right = m_right->getNbLeaf();

			if(m_left != NULL)
				left = m_left->getNbLeaf();

			return right + left;
		}

		///Retourne la longueur d'une zone
		virtual double getLength(double x, double z) const{
			std::cout << "MapTree getLength, depth : " << m_depth << std::endl;

			//Si l'élément n'est pas NULL, on est arrivé
			if(m_element != NULL){

				std::cout << "Zone trouvée dans feuille length : " << m_length << std::endl;
				return m_length;
			}

			//Sinon on recherche chez les noeuds fils en fonction de la profondeur
			
			//Si la profondeur est impair celà veut dire que c'est la largeur qui a été divisé
			if(m_depth % 2)
			{
				//Fils de droite si Z <= Width / 2
				if(z <= m_width / 2.0){
					std::cout << "Fils de droite" << std::endl;
					return m_right->getLength(x, z);
				}
			}
			else{ // Sinon c'est la longueur qui a été divisé
				//Fils de droite si X <= Length / 2
				if(x <= m_length / 2.0){
					std::cout << "Fils de droite" << std::endl;
					return m_right->getLength(x, z);
				}
			}

			//Fils de gauche sinon
			std::cout << "Fils de gauche" << std::endl;
			return m_left->getLength(x, z);
		}

		///Retourne la largeur de la zone
		virtual double getWidth(double x, double z) const{
			std::cout << "MapTree getWidth, depth : " << m_depth << std::endl;

			//Si l'élément n'est pas NULL, on est arrivé
			if(m_element != NULL){

				std::cout << "Zone trouvée, width : " << m_width << std::endl;
				return m_width;
			}

			//Sinon on recherche chez les noeuds fils en fonction de la profondeur
			
			//Si la profondeur est impair celà veut dire que c'est la largeur qui a été divisé
			if(m_depth % 2)
			{
				//Fils de droite si Z <= Width / 2
				if(z <= m_width / 2.0){
					std::cout << "Fils de droite" << std::endl;
					return m_right->getWidth(x, z);
				}
			}
			else{ // Sinon c'est la longueur qui a été divisé
				//Fils de droite si X <= Length / 2
				if(x <= m_length / 2.0){
					std::cout << "Fils de droite" << std::endl;
					return m_right->getWidth(x, z);
				}
			}
			
			//Fils de gauche sinon
			std::cout << "Fils de gauche" << std::endl;
			return m_left->getWidth(x, z);
		}

		///Retourne le noeuds fils de droite
		virtual MapTree<T>* getRight(){
			return m_right;
		}

		///Retourne le noeuds fils de gauche
		virtual MapTree<T>* getLeft(){
			return m_left;
		}

		///Retourne l'élément stocké dans le noeud ou dans un ses noeuds fils
		virtual T* getElement(double x, double z){

			std::cout << "MapTree getElement, depth : " << m_depth << std::endl;

			//Si l'élément n'est pas NULL, on est arrivé
			if(m_element != NULL){

				std::cout << "Element trouvé" << std::endl;
				return m_element;
			}

			//Sinon on recherche chez les noeuds fils en fonction de la profondeur
			
			//Si la profondeur est impair celà veut dire que c'est la largeur qui a été divisé
			if(m_depth % 2)
			{
				//Fils de droite si Z <= Width / 2
				if(z <= m_width / 2.0){
					std::cout << "Element dans la zone de droite" << std::endl;
					return m_right->getElement(x, z);
				}
			}
			else{ // Sinon c'est la longueur qui a été divisé
				//Fils de droite si X <= Length / 2
				if(x <= m_length / 2.0){
					std::cout << "Element dans la zone de droite" << std::endl;
					return m_right->getElement(x, z);
				}
			}
			
			//Fils de gauche sinon
			std::cout << "Element dans la zone de gauche" << std::endl;
			return m_left->getElement(x, z);
		}


		///Modifie l'élement qui se trouve en position (pos1, pos2)
		virtual void setElement(T element, double x, double z){

			
			//Si l'élément n'est pas NULL, on est arrivé
			if(m_element != NULL){

				std::cout << "Element trouvé" << std::endl;
				*m_element = element; //On recopie la valeur
			}

			//Sinon on recherche chez les noeuds fils en fonction de la profondeur
			
			//Si la profondeur est impair celà veut dire que c'est la largeur qui a été divisé
			if(m_depth % 2)
			{
				//Fils de droite si Z <= Width / 2
				if(z <= m_width / 2.0){
					std::cout << "Element dans la zone de droite" << std::endl;
					return m_right->setElement(element, x, z);
				}

				//Fils de gauche sinon
				std::cout << "Element dans la zone de gauche" << std::endl;
				return m_left->setElement(element, x, z);
			}
			else{ // Sinon c'est la longueur qui a été divisé
				//Fils de droite si X <= Length / 2
				if(x <= m_length / 2.0){
					std::cout << "Element dans la zone de droite" << std::endl;
					return m_right->setElement(element, x, z);
				}

				//Fils de gauche sinon
				std::cout << "Element dans la zone de gauche" << std::endl;
				return m_left->setElement(element, x, z);
			}
		}

	protected :

		int m_depth;			///< Profondeur du noeud dans l'arbre

		double m_length;		///< Longueur de la zone (X).

		double m_width;			///< Largeur de la zone (Z).

		MapTree<T>* m_right; 	///< Noeud pour la zone <= size / 2

		MapTree<T>* m_left;  	///< Noeud pour la zone > size / 2

		T* m_element;			///< Element stocké par le noeud "feuille"
};

#endif // MAP_TREE_HPP