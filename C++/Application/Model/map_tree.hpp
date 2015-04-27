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

//! TreeNode Class
/*!
 * La classe TreeNode sont les noeuds 
 * du MapTree. Elle possède un attribut
 * size qui est la taille de la zone à diviser,
 * deux TreeNodes filles, un pointeur sur un
 * élément de type T (NULL par défaut).
 * 
 * Un objet TreeNode créé lui meme ses nodes filles
 * tant que les size n'ont pas atteint une certaine
 * taille minimum.
 */
template<typename T>
class MapTreeNode{
	
	public :

		///Constructeur
		/*!
		 * \param size1 : taille à diviser pour le noeud courant
		 * \param size2 : taille à diviser pour le prochain noeud
		 * \param min : taille minimal, ne pas faire de fille si size1 <= min
		 * \param detph : profondeur du noeud dans l'arbre
		 */
		MapTreeNode(int size1, int size2, int min, int depth) 
			: m_depth(depth), m_size(size1), m_right(NULL), m_left(NULL), m_element(NULL){

				std::cout << "MapTreeNode Constructeur, depth : " << m_depth << " size : " << m_size << std::endl;

				//Si on a atteint la taille minimum
				if(size1 <= min){
					std::cout << "Feuille" << std::endl;
					m_element = new T;
				}
				else{ //Si il faut encore diviser la zone
					std::cout << "Divisions en deux nodes" << std::endl;
					//Si impair
					if(size1 % 2)
						m_left = new MapTreeNode<T>(size2, (size1 / 2) + 1, min, m_depth+1);
					else //Si pair
						m_left = new MapTreeNode<T>(size2, size1 / 2, min, m_depth+1);

					m_right = new MapTreeNode<T>(size2, size1 / 2, min, m_depth+1);
				}
		}

		///Destructeur
		virtual ~MapTreeNode(){
			std::cout << "MapTreeNode ~Destructeur" << std::endl;
			if(m_element != NULL)
				delete m_element;

			if(m_right != NULL)
				delete m_right;

			if(m_left != NULL)
				delete m_left;
		}

		//Retourne la profondeur de l'arbre à partir du noeud
		virtual int getDepth() const{
			std::cout << "MapTreeNode getDepth" << std::endl;
			int rdepth = 0;
			int ldepth = 0;
			
			if(m_right != NULL)
				rdepth = m_right->getDepth();

			if(m_left != NULL)
				ldepth = m_left->getDepth();

			return m_depth + std::max(rdepth, ldepth);
		}

		//Retourne la taille de la zone
		virtual int getSize() const{
			return m_size;
		}

		///Retourne le noeuds fils de droite
		virtual MapTreeNode<T>* getRight(){
			return m_right;
		}

		///Retourne le noeuds fils de gauche
		virtual MapTreeNode<T>* getLeft(){
			return m_left;
		}

		///Retourne l'élément stocké dans le noeud ou dans un ses noeuds fils
		virtual T* getElement(int pos1, int pos2){

			std::cout << "MapTreeNode getElement, depth : " << m_depth << std::endl;

			//Si l'élément n'est pas NULL, on est arrivé
			if(m_element != NULL){

				std::cout << "Element trouvé" << std::endl;
				return m_element;
			}

			//Sinon on recherche chez les noeuds fils
			
			//Fils de droite si pos1 <= size / 2 (on oublie pas d'inverser pos2 et pos1)
			if(pos1 <= m_size / 2){
				std::cout << "Element dans la zone de droite" << std::endl;
				return m_right->getElement(pos2, pos1);
			}

			std::cout << "Element dans la zone de gauche" << std::endl;
			return m_left->getElement(pos2, pos1);
		}


		///Modifie l'élement qui se trouve en position (pos1, pos2)
		virtual void setElement(T element, int pos1, int pos2){

			//Si on arrive sur une fauille
			if(m_element != NULL){
				*m_element = element; //On recopie la valeur
			}
			else{ //Si on cherche l'emplacement de l'élement dans les noeuds fils

				if(pos1 <= m_size / 2)
					m_right->setElement(element, pos2, pos1);
				else
					m_left->setElement(element, pos2, pos1);
			}
		}

	protected :

		int m_depth;			///< Profondeur du noeud dans l'arbre

		int m_size;				///< Taille de la zone à diviser pour aller faire un noeud fille ou non.

		MapTreeNode<T>* m_right; 	///< Noeud pour la zone <= size / 2

		MapTreeNode<T>* m_left;  	///< Noeud pour la zone > size / 2

		T* m_element;			///< Element stocké par le noeud "feuille"
};

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
		MapTree(int length, int width, int min_size) 
			: m_tree(new MapTreeNode<T>(length, width, min_size, 0)) {

				std::cout << "MapTree Constructeur" << std::endl;
		}

		///Destructeur
		virtual ~MapTree(){
			std::cout << "MapTree ~Destructeur" << std::endl;
			delete m_tree;
		}

		///Retourne la profondeur de l'arbre
		virtual int getDepth(){
			std::cout << "MapTree getDepth" << std::endl;
			return m_tree->getDepth();
		}

		///Retourne l'élément stocké dans la zone où se trouve un point (x, z)
		virtual T* getZone(double x, double z){
			std::cout << "MapTree getZone" << std::endl;
			return m_tree->getElement(x, z);
		}

		///Retourne la liste des élements stocké dans une zone et les zones voisine
		virtual void getNeighborhood(double x, double z){
		}


		///Modifie l'élément d'une zone de la map
		virtual void setZone(T element, double x, double z){
			std::cout << "MapTree setZone" << std::endl;
			m_tree->setElement(element, x, z);
		}

	protected :

		MapTreeNode<T>* m_tree;		///< Pointeur sur la cime de l'arbre (le premier noeud)
};

#endif // MAP_TREE_HPP