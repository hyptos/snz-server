#include "environment.hpp"

//Constructeur
Environment::Environment(int length, int width, int height = INT_MAX)
    : m_length(length), m_width(width), m_height(height) {
}

//Destructeur
Environment::~Environment(){}

//Retourne la longueur de l'environnement
int Environment::getLength() const{
	return m_length;
}

//Retourne la largeur de l'environnement
int Environment::getWidth() const{
	return m_width;
}

int Environment::getHeight() const{
    return m_height;
}

//Retourne si un emplacement est valide par rapport à l'environnement
int Environment::validePosition(double x, double z, double y) const{

    //X+ : 1
    //X+ Z+ : 2
    //X+ Z- : 3

    //X- : 4
    //X- Z+ : 5
    //X- Z- : 6

    //Z+ : 7
    //Z- : 8

    //TODO : gérer la hauteur

    if(x < 0){

        if(z < 0)
            return 2;
        else if(z > m_width)
            return 3;

        return 1;
    }
    else if(x > m_length){
        if(z < 0)
            return 5;
        else if(z > m_width)
            return 6;

        return 4;
    }

    if(z < 0)
        return 7;
    else if(z > m_width)
        return 8;

    return 0;
}

//Retourne des info sur l'environnement autour d'un point (TODO)
void Environment::getArea(double x, double z, double dist) const{
}
