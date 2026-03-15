#pragma once

#include "../ecs/coordinator.hpp"

#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"

#include "raylib.h"

#include "../rendering/render_structs.hpp"

class DebugDrawSystem : public System 
{
public:
    void Update(float delta, Coordinator* coordinator);
private:
    bool enabled = false;
};