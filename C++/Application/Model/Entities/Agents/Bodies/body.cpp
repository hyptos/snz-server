#include "body.hpp"
#include "Model/Entities/Agents/agent.hpp"

//Constructeur
Body::Body(Environment *env, Agent* agent)
    : Module(), m_environment(env), m_agent(agent), m_brain(NULL), m_ear(new Ear){
}

//Destructeur
Body::~Body(){

    //Arrêt des modules
    m_ear->stop();
    delete m_ear;
}

Ear* Body::getEar() const {
    return m_ear;
}

//Connecte le body et le brain
void Body::connect_to_brain(Brain *brain){
    m_brain = brain;
    m_ear->setBrain(brain);
}

//Attrape le son
void Body::catchSound(SoundStimulus &sound){
    m_mutex.lock();
    double dist = sqrt(pow(sound.getX() - m_agent->getX(), 2) + pow(sound.getZ() - m_agent->getZ(), 2));
    m_mutex.unlock();

    if(dist <= sound.getPower())
        m_ear->hear(sound);
}

//Modifie la direction de l'agent
void Body::moveTo(double x, double z){

    m_mutex.lock();
    double dist = sqrt(pow(x - m_agent->getX(), 2) + pow(z - m_agent->getZ(), 2));
    m_agent->setDirection((x - m_agent->getX()) / dist, (z - m_agent->getZ()) / dist, 0.0);
    m_agent->setSpeed(1.0);
    m_mutex.unlock();
}

//Ajoute une action à effectuer par le body
void Body::addActionTodo(BrainOrderType order, unsigned long long id){

    std::pair<BrainOrderType, unsigned long long> todo(order, id);
    m_mutex.lock();
    m_todo.push_back(todo);
    m_mutex.unlock();
}

//Fait les actions stocké dans la TODO List
void Body::operator ()(){

    //On lance les modules
    std::thread th_ear(Module::run, m_ear);
    th_ear.detach();

    m_stopped = false;
    while(!m_stopped){

        if(!m_todo.empty()){

            m_mutex.lock();
            std::pair<BrainOrderType, unsigned long long> todo = m_todo.front();
            m_todo.pop_front();
            m_mutex.unlock();

            if(todo.first == BrainOrderType::MOVE){

                m_mutex.lock();
                double old_x = m_agent->getX();
                double old_z = m_agent->getZ();
                double old_y = m_agent->getY();

                double new_x;
                double new_z;
                double new_y = old_y; //TODO

                if(old_x + m_agent->getDX()*m_agent->getSpeed() >= m_environment->getLength())
                    new_x = 0;
                else if(old_x + m_agent->getDX()*m_agent->getSpeed() <= 0)
                    new_x = m_environment->getLength();
                else
                    new_x = old_x + m_agent->getDX()*m_agent->getSpeed();

                if(old_z + m_agent->getDZ()*m_agent->getSpeed() >= m_environment->getLength())
                    new_z = 0;
                else if(old_z + m_agent->getDZ()*m_agent->getSpeed() <= 0)
                    new_z = m_environment->getLength();
                else
                    new_z = old_z + m_agent->getDZ()*m_agent->getSpeed();
                m_mutex.unlock();


                if((old_x != new_x || old_z != new_z || old_y != new_y) && m_environment->validTravel(old_x, old_z, new_x, new_z)){
                    m_mutex.lock();
                    m_agent->setCoordinates(new_x, new_z, new_y);
                    m_mutex.unlock();
                }

                //TODO : m_y
            }
            else if(todo.first == BrainOrderType::STAY){

                m_mutex.lock();
                m_agent->setSpeed(0.0);
                m_mutex.unlock();
            }

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}
