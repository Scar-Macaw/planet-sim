#pragma once

#include "../ecs/coordinator.hpp"

class ForceIntegrator : public System 
{
public:
    void Update(float delta, Coordinator* coordinator);
};