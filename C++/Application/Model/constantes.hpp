/**
 * File: constante.h
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 14, 2015, 3:07 PM
 */

#ifndef CONSTANTE_HPP
#define CONSTANTE_HPP

//Détermine le type d'une Entité
enum EntityType {   
    AGENT = 0,
    OBJECT = 1,
    PLAYER = 2
};

//Détermine le type d'un agent
enum AgentType {
    ZOMBIE = 3,
    DOG = 4,    //TODO first after zombie
    COW = 5,
    CHICKEN = 6,
    RABBIT = 7,
    TREE = 8    //Why not ?
};

//Détermine le type d'un Objet
enum ObjectType {
    CHAIR = 9,
    SWORD = 10,
    BUILDING = 30,
    HOUSE = 31
};

//Détermine l'état du mouvement d'un Agent (ou d'un Player)
enum AgentMoveState {
    WALK = 11,
    RUN = 12,
    SNAKE = 13
};

//Détermine l'état de "santé" d'un Agent (ou d'un Payer)
enum AgentHealthState {
    NORMAL = 14,
    SICK = 15,
    DEAD = 16
};

//Détermine le type d'une action (faite par un Agent ou un Player)
enum ActionType {
    HIT = 17,
    SHOOT = 18,
    BITE = 19,
    CUT = 20,
    CATCH = 21,
    THROW = 22,
};

//Détermine le type d'ordre donné par le Brain d'un Agent sur son Body
enum BrainOrderType {
    MOVE = 23,
    STAY = 24,
    ATTACK = 25,
    FLEE = 26,
    FOLLOW = 27
};

//Détermine le type d'un stimulus
enum StimulusType {
    SOUND = 28,
    VISUAL = 29
};

#endif // CONSTANTE_HPP

