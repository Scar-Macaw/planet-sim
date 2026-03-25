#pragma once

#include "../ecs/coordinator.hpp"

class GravitySystem : public System 
{
public:
    void Update(float delta, Coordinator* coordinator);
};