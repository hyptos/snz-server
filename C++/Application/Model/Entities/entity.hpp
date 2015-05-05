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
#include "Model/Info/infoaction.hpp"
#include "Bodies/body.hpp"
#include "Model/model.hpp"

class SNZ_Model;


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
        Entity(InfoEntity*, Body*, SNZ_Model*);

        ///Destructeur
        virtual ~Entity() = 0;



        ///Retourne les informations concernant l'Entité
        virtual InfoEntity getInfo() const;

        ///Retourne un pointeur sur le corps de l'entité
        virtual Body* getBody() const;



        ///Modifie les Infos de l'Entité
        virtual void setInfo(InfoEntity*);

        ///Modifie le pointeur sur le corps de l'entité
        virtual void setBody(Body *);



        ///Indique un action extérieur sur l'entité
        virtual void notifyAction(InfoAction);

        ///Indique une modification des coordonnées du corps à l'entité
        virtual void notifyCoordinates(double, double, double);

        ///Indique une modification de la direction du corps à l'entité
        virtual void notifyDirection(double, double, double);



        ///Retourne si deux Entités sont égales ou non
        /*!
         * Le test se fait juste sur l'ID
         */
        virtual bool operator ==(const Entity&);

    protected :

        InfoEntity *m_info;       ///< Informations sur l'entité

        Body *m_body;             ///< Corps de l'entité dans l'environnement

        SNZ_Model *m_model;       ///< Lien vers le modèle pour notifier des changements
};

#endif // ENTITY_HPP

