#pragma once

#include "../ecs/coordinator.hpp"

#include "rendering_system.hpp"

#include "../components/rendering_component.hpp"
#include "../components/collision_component.hpp"

class MeshGeneratorSystem : public System
{
public:
    void SetMeshes(RenderingSystem* render_system, Coordinator* coordinator);
};