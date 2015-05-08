#include "brain.hpp"

//Constructeur
Brain::Brain()
    : m_body(NULL){
}

//Destructeur
Brain::~Brain(){
}

//Connecte le Brain à un Body
void Brain::connect_to_body(Body *body){
    m_body = body;
}
