/**
 * File: agent.hpp
 * Author: Antoine "Avzgui" Richard
 *
 * Created on April 22, 2015, 11:18 AM
 */

#ifndef ZAGENT_HPP
#define ZAGENT_HPP

#include <iostream>
#include <thread>

#include "Model/module.hpp"
#include "Brains/zbrain.hpp"
#include "Model/environment.hpp"
#include "Bodies/body.hpp"
#include "agent.hpp"

class Environment;

class Body;

class ZAgent : public Agent{

    public :

        ZAgent(unsigned long long, Environment*, double, double, double, double, double, double);

        ~ZAgent();
};

#endif // ZAGENT_HPP

