#pragma once

struct PhysicsComponent {
    float mass = 1.0f;
    float force_x = 0.0f;
    float force_y = 0.0f;
    float force_z = 0.0f;
    float vel_x = 0.0f;
    float vel_y = 0.0f;
    float vel_z = 0.0f;
};