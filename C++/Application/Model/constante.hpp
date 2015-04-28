/**
 * File: constante.h
 * Author: Antoine
 *
 * Created on April 14, 2015, 3:07 PM
 */

#ifndef CONSTANTE_HPP
#define CONSTANTE_HPP

enum EntityType {
    ZOMBIE = 0,
    PLAYER = 1
};

enum EntityState {
    NORMAL = 2,
    ALIVE = 3,
    DEAD = 4,
    BREAK = 5,
    MOVE = 6,
    STAY = 7,
    JUMP = 8,
    SNAKE = 9
};

enum EntityAction {
    ATTACK = 10,
    CUT = 11,
    THROW = 12
};

#endif // CONSTANTE_HPP

