#include "ear.hpp"

//Constructeur
Ear::Ear()
    : Module(), m_brain(NULL){
}

//Destructeur
Ear::~Ear(){

    m_stopped = true;

    m_thingsHeard.clear();
}

//Ajout dans la liste
void Ear::hear(SoundStimulus &sound){

    m_mutex.lock();
    m_thingsHeard.push_back(sound);
    m_mutex.unlock();
}

//Boucle d'écoute
void Ear::operator ()(){
    m_stopped = false;
    while(!m_stopped){

        if(!m_thingsHeard.empty()){
            m_mutex.lock();
            SoundStimulus sound = m_thingsHeard.front();
            m_thingsHeard.pop_front();
            m_mutex.unlock();

            if(m_brain != NULL)
                m_brain->addSoundStimulus(sound);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

//Retourne le lien vers le Brain
Brain* Ear::getBrain(){
    return m_brain;
}

//Modifie le lien vers le brain
void Ear::setBrain(Brain *brain){
    m_brain = brain;
}

