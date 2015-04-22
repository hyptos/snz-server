#include "zagent.hpp"

ZAgent::ZAgent(unsigned long long id, Environment *env, double x, double z, double y, double dx, double dz, double dy)
    : Agent(id, AgentType::ZOMBIE, env, new Body(env, this), new ZBrain, x, z, y, dx, dz, dy){

    m_body->connect_to_brain(m_brain);
    m_brain->connect_to_body(m_body);

    std::thread th_body(Module::run, m_body);
    th_body.detach();

    std::thread th_brain(Module::run, m_brain);
    th_brain.detach();
}

ZAgent::~ZAgent(){
    m_body->stop();
    m_brain->stop();

    delete m_brain;
    delete m_body;
}


