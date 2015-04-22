/**
 * File: model.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 21, 2015, 8:10 PM
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

#include "Entities/Agents/zagent.hpp"
#include "environment.hpp"
#include "constantes.hpp"
#include "Info/infoentity.hpp"

class SNZ_Model {

    public :

        ///Constructeur
        SNZ_Model(int,int);

        ///Destructeur
        virtual ~SNZ_Model();

        ///Retourne le lien vers l'Environnement
        virtual Environment* getEnvironment();

        ///Retourne le nombre d'Entités présentes dans l'environnement
        virtual unsigned long long getNbEntities();

        ///Retourne des informations sur une entité
        virtual InfoEntity getInfo(unsigned long long);

        ///Retourne une liste d'informations (A améliorer)
        virtual std::list<InfoEntity> getInfos();

        ///Modifie les données d'une entité
        virtual void setInfo(InfoEntity);

        ///Ajoute une Entité au modèle
        /*!
         * \return l'ID que le modèle a donné à l'entité ajouté
         */
        virtual unsigned long long addEntity(InfoEntity);

        //TODO setAction

    protected :

        Environment* m_environment;         ///< Pointeur sur l'environnement des entités

        std::vector<Entity*> m_entities;    ///< Vecteur de liens vers les entités

        unsigned long long m_nbEntities;    ///< Nombre d'entités présentes dans le modèle
};

#endif // MODEL_HPP

