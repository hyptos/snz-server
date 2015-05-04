/**
 * File: entity.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 21, 2015, 5:09 PM
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <thread>

#include "Model/constantes.hpp"
#include "Model/Info/infoentity.hpp"

class SNZ_Model;

class Agent;

//! Entity Class
/*!
 * \brief La classe Entity regroupe les
 * attributs et méthodes de toutes entitées
 * faisant parties du modèle (agents, objets,
 * joueurs, etc..)
 */
class Entity {

    public :

        ///Constructeur
        Entity(unsigned long long, EntityType, Body*, SNZ_Model*);

        ///Destructeur
        virtual ~Entity() = 0;

        ///Retourne l'ID de l'Entité
        virtual unsigned long long getId() const;

        ///Retourne le Type de l'Entité
        virtual EntityType getType() const;

        ///Retourne les informations concernant l'Entité
        virtual InfoEntity getInfo() const;



        //Modifie l'ID de l'Entité
        virtual void setId(unsigned long long);

        //Modifie le Type de l'Entité
        virtual void setType(EntityType);



        ///Retourne si deux Entités sont égales ou non
        /*!
         * Le test se fait juste sur l'ID
         */
        virtual bool operator ==(const Entity&);

    protected :

        unsigned long long m_id;  ///< Id de l'entité

        EntityType m_type;        ///< Type de l'entité

        Body *m_body;             ///< Corps de l'entité dans l'environnement

        SNZ_Model *m_model;       ///< Lien vers le modèle pour notifier des changements
};

#endif // ENTITY_HPP

