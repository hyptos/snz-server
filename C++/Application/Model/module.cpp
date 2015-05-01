#include "module.hpp"

//Constructeur
Module::Module() : m_stopped(true) {
}

//Destructeur
Module::~Module(){
}

//Fonction static pour lancer les opérations d'un module dans un thread
void Module::run(Module *mod){
    (*mod)();
}

//Retourne l'état du module
bool Module::isRunning(){
    return !m_stopped;
}

//Arrête le processus du module
void Module::stop(){
    m_stopped = true;
}
