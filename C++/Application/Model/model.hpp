/**
 * File: model.hpp
 * Author: Antoine
 *
 * Created on April 13, 2015, 2:24 PM
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include <QObject>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <climits>

#include "environment.hpp"
#include "Entities/entity.hpp"
#include "Entities/Agents/agent.hpp"
#include "Entities/Agents/zagent.hpp"
#include "Info/infoagent.hpp"
#include "Info/infoentity.hpp"
#include "Info/infoaction.hpp"


//! SNZ_Model Class
/*!
 * La classe SNZ_Model implémente le model de l'application
 * contenant les informations sur les agents, l'environnement,
 * les users, et les données à envoyer.
 */
class SNZ_Model : public QObject{

    //Macro pour signaux et slots
    Q_OBJECT

    public :

        ///Conctructeur
        SNZ_Model(int, int);

        ///Destructeur
        ~SNZ_Model();

    public slots :

        ///Function de reception d'une action faite par une entité
        void entity_action(InfoAction);

        ///Function de reception d'une modification d'une entité (position, état...)
        void entity_maj(InfoEntity);

        ///Function pour demander au model d'envoyer l'état de ses entités
        void ask_maj();

        ///Déclenche un son
        void do_sound(double, double);

    signals :

        ///Signal du son
        void sound(double,double,double,double);

        ///Signal envoyé pour indiquer un changement pour une entité (position, état...)
        void maj_entity(InfoEntity);

        ///Signal envoyé pour indiquer une action faite par une entité
        void maj_action(InfoAction);

    private :

        std::vector<Entity*> m_entities;    ///< Liste des entités
        unsigned long long m_nbEntities;    ///< Nombres d'entités présent dans le modèle

        Environment *m_environment;          //< Environnement de déplacement des entités

};

#endif // MODEL_HPP

