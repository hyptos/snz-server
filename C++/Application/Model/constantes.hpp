/**
 * File: constante.h
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:07 PM
 */

#ifndef CONSTANTE_HPP
#define CONSTANTE_HPP

//Détermine le type d'une Entité
enum EntityType {
    AGENT,
    OBJECT,
    PLAYER
};

//Détermine le type d'un agent
enum AgentType {
    ZOMBIE,
    DOG,    //TODO first after zombie
    COW,
    CHICKEN,
    RABBIT,
    TREE    //Why not ?
};

//Détermine le type d'un Objet
enum ObjectType {
    MOVABLE,
    STATIC
};

//Détermine l'état du mouvement d'un Agent (ou d'un Player)
enum AgentMoveState {
    WALK,
    RUN,
    SNAKE
};

//Détermine l'état de la "vie" d'un Agent (ou d'un Player)
enum AgentLifeState {
    ALIVE,
    DEAD
};

//Détermine l'état de "santé" d'un Agent (ou d'un Payer)
enum AgentHealthState {
    NORMAL,
    SICK
};

//Détermine le type d'une action (faite par un Agent ou un Player)
enum ActionType {
    HIT,
    SHOOT,
    BITE,
    CUT,
    CATCH,
    THROW,
};

//Détermine le type d'ordre donné par le Brain d'un Agent sur son Body
enum BrainOrderType {
    MOVE,
    STAY,
    ATTACK,
    FLEE,
    FOLLOW
};

//Détermine le type d'un stimulus
enum StimulusType {
    SOUND,
    VISUAL
};

#endif // CONSTANTE_HPP

