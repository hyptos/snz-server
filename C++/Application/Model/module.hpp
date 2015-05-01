/**
 * File: module.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 19, 2015, 6:51 PM
 */

#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include <mutex>

//! Module Interface
/*!
 * \brief L'interface Module est une classe
 * abstraite implémentant les méthodes communes
 * à tous les modules d'un agent étant affecté
 * par le temps ou devant répeter une ou des actions.
 *
 * Le programmeur doit réimplémenter l'opérateur
 * () pour définir le fonctionnement d'un module
 * fille.
 */
class Module{

    public :

        ///Constructeur
        Module();

        ///Destructeur
        virtual ~Module() = 0;

        ///Operateur () à surchager dans les classes filles de Module pour préciser leur fonctionnement
        virtual void operator()() = 0;

        ///Fonction static permettant de lancer le processus de n'importe quel module dans un thread
        static void run(Module*);

        ///Permet d'arréter le processus d'un module
        virtual void stop();

        ///Retourne l'état du module
        virtual bool isRunning();

    protected :

        bool m_stopped;     ///< Booléen permettant de savoir si un module est actif ou non

        std::mutex m_mutex; ///< Mutex permettant de bloquer l'accés à une variable partagée
};

#endif // MODULE_HPP

