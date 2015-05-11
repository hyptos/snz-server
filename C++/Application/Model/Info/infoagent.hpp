/**
 * File: infoagent.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on May the 4th be with you, 2015, 4:48 PM
 */

#ifndef INFO_AGENT_HPP
#define INFO_AGENT_HPP

#include <iostream>

#include "Model/constantes.hpp"
#include "infoentity.hpp"


//! InfoAgent Class
/*!
 * La classe InfoAgent contient les données
 * concernant un agent. (à instant t non précisé)
 */
class InfoAgent : public InfoEntity{

    public :

    	///Constructeur par défaut
    	InfoAgent();

    	///Constructeur avec paramètres
        InfoAgent(unsigned long long, AgentType, double, double, double, double, double, double, AgentMoveState, AgentHealthState);

        ///Constructeur par copie
        InfoAgent(const InfoAgent&);

        ///Destructeur
        virtual ~InfoAgent();

        ///Retourne le type de l'agent
        virtual AgentType getAgentType() const;

        ///Modifie le type de l'agent
        virtual void setAgentType(AgentType atype);

        ///Retourne l'état du mouvement de l'agent
        virtual AgentMoveState getMoveState() const;

        ///Modifie l'état du mouvement de l'agent
        virtual void setMoveState(AgentMoveState moveState);
        
        ///Retourne l'état de "santé" de l'agent
        virtual AgentHealthState getHealth() const;

        ///Modifie l'état de "santé" de l'agent
        virtual void setHealth(AgentHealthState health);


    protected :

    	AgentType m_atype;            ///< Type de l'agent

    	AgentMoveState m_moveState;   ///< Etat du mouvement de l'agent

    	AgentHealthState m_health;    ///< Etat de "santé" de l'agent
};

#endif // INFO_AGENT_HPP