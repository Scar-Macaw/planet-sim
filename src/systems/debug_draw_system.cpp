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
        auto& physics  = coordinator->GetComponent<PhysicsComponent>(e);
        
        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x + physics.vel_x, transform.y + physics.vel_y, transform.z + physics.vel_z},
        WHITE
        );

        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x + physics.vel_x, transform.y, transform.z},
        RED
        );

        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x, transform.y + physics.vel_y, transform.z},
        GREEN
        );
        
        DrawLine3D(
        {transform.x, transform.y, transform.z},
        {transform.x, transform.y, transform.z + physics.vel_z},
        BLUE
        );
        
        DrawGrid(20, 4.0f);
    }

}