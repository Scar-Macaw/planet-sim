#include "debug_draw_system.hpp"

void DebugDrawSystem::Update(float delta, Coordinator* coordinator)
{
    if (IsKeyPressed(KEY_F1))
    {
        enabled = !enabled;
    }

    if (!enabled) { return; }

    for (auto const& e : entities)
    {
        auto& transform = coordinator->GetComponent<TransformComponent>(e);
        auto& velocity  = coordinator->GetComponent<VelocityComponent>(e);
        
        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x + velocity.x, transform.y + velocity.y, transform.z + velocity.z},
        WHITE
        );

        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x + velocity.x, transform.y, transform.z},
        RED
        );

        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x, transform.y + velocity.y, transform.z},
        GREEN
        );
        
        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x, transform.y, transform.z + velocity.z},
        BLUE
        );
        
        DrawGrid(40, 1.0f);
    }

}