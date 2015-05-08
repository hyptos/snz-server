#include "zbrain.hpp"

//Constructeur
ZBrain::ZBrain() : Brain(){
}

//Destructeur
ZBrain::~ZBrain(){
    m_stopped = true;
}

//Implémente les actions déclenchés par le Brain lorsque le Body indique un Son
void ZBrain::addSoundStimulus(SoundStimulus &sound){

    if(m_body != NULL)
        m_body->moveTo(sound.getX(), sound.getZ());
}

//Implémente la boucle d'action de l'agent
void ZBrain::operator ()(){
    m_stopped = false;

    while(!m_stopped){

        m_body->addActionTodo(BrainOrderType::MOVE);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


