/**
 * File: model.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 21, 2015, 8:10 PM
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <climits>

#include "Entities/Agents/zombie.hpp"
#include "Entities/player.hpp"
#include "environment.hpp"
#include "constantes.hpp"
#include "Info/infoentity.hpp"
#include "Info/infoagent.hpp"
#include "Model/modelview.hpp"

class ModelView;
class Entity;

class SNZ_Model {

    public :

        ///Constructeur
        SNZ_Model(int,int);

        ///Destructeur
        virtual ~SNZ_Model();

        ///Connection à la "vue"
        void connect_to_view(ModelView*);

        ///Notifie un changement d'une entité à la "vue" ou à l'environnement
        void notifyEntity(InfoEntity*);

        ///Retourne le lien vers l'Environnement
        virtual Environment* getEnvironment();

        ///Retourne le nombre d'Entités présentes dans l'environnement
        virtual unsigned long long getNbEntities();

        ///Ajoute une Entité au modèle
        /*!
         * \return l'ID que le modèle a donné à l'entité ajouté
         */
        virtual unsigned long long addEntity(InfoEntity*);

        ///Supprime une Entité du modèle
        virtual void removeEntity(unsigned long long);

        //TODO notifyAction

    protected :

        Environment* m_environment;         ///< Pointeur sur l'environnement des entités

        std::map<unsigned long long, Entity*> m_entities;    ///< Map de liens vers les entités

        unsigned long long m_nbEntities;    ///< Nombre d'entités présentes dans le modèle


        ModelView* m_view;                  ///< lien vers le model
};

#endif // MODEL_HPP

