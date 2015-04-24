/**
 * File: agent.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 21, 2015, 9:21 PM
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>

#include "Bodies/body.hpp"
#include "Brains/brain.hpp"
#include "Model/constantes.hpp"
#include "Model/Entities/entity.hpp"

class Environment;

class Body;

class Brain;


class Agent : public Entity {

    public :

        ///Constructeur
        Agent(unsigned long long, AgentType, Environment*, Body*, Brain*, double, double, double, double, double, double);

        ///Destructeur
        virtual ~Agent() = 0;



        ///Retourne le Type de L'Agent
        virtual AgentType getAgentType();

        ///Retourne le lien vers l'Environment
        virtual Environment* getEnvironment();

        ///Retourne le lien vers le Body
        virtual Body* getBody();

        ///Retourne le lien vers le Brain
        virtual Brain* getBrain();

        ///Retourne si l'Agent est "vivant" ou non
        virtual bool isAlive() const;

        ///Retourne l'état de la "vie" de l'Agent
        virtual AgentLifeState getLife() const;

        ///Retourne l'état de "santé" de l'Agent
        virtual AgentHealthState getHealth() const;

        ///Retourne l'état du mouvement de l'Agent
        /*!
         * Si il cours, marche, rampe, tout ça, tout ça.
         */
        virtual AgentMoveState getMoveState() const;

        ///Retourne la vitesse actuelle de l'Agent
        virtual double getSpeed() const;



        ///"Tue" l'agent
        virtual void kill();

        ///Modifie l'état de la "vie" de l'agent
        virtual void setLife(AgentLifeState);

        ///Modifie l'état de la "santé"
        virtual void setHealth(AgentHealthState);

        ///Modifie l'état du mouvement de l'Agent
        virtual void setMoveState(AgentMoveState);

        ///Modifie la vitesse actuelle de l'Agent
        virtual void setSpeed(double);

    protected :

        AgentType m_atype;    ///< Type de l'agent

        Environment* m_environment; ///< Lien vers l'Environnement

        Body* m_body;               ///< Lien vers le Body

        Brain* m_brain;             ///< Lien vers le Brain

        AgentLifeState m_life;      ///< Indique si l'agent est toujours "vivant"

        AgentHealthState m_health;  ///< Indique l'état de "santé" de l'agent

        AgentMoveState m_moveState; ///< Indique si l'agent marche, cours, et caetera

        double m_speed;             ///< Vitesse de l'Agent (0 si l'agent ne bouge pas)
};

#endif // AGENT_HPP

