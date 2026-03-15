#include "camera_system.hpp"
#include <iostream>

void CameraSystem::Update(float delta, Coordinator* coordinator)
{
    for (auto const& e : entities)
    {
        auto& transform = coordinator->GetComponent<TransformComponent>(e);
        auto& cam       = coordinator->GetComponent<CameraComponent>(e);

        if (IsKeyDown(KEY_RIGHT))
        {
            cam.yaw = cam.yaw + (SENSITIVITY * delta);
        }
        if (IsKeyDown(KEY_LEFT))
        {
            cam.yaw = cam.yaw - (SENSITIVITY * delta);
        }

        if (IsKeyDown(KEY_UP))
        {
            cam.pitch = cam.pitch + (SENSITIVITY * delta);
        }
        if (IsKeyDown(KEY_DOWN))
        {
            cam.pitch = cam.pitch - (SENSITIVITY * delta);
        }

        if (cam.pitch >  PITCH_CLAMP){ cam.pitch =  PITCH_CLAMP; }
        if (cam.pitch < -PITCH_CLAMP){ cam.pitch = -PITCH_CLAMP; }

        float dir_x = cos(cam.pitch) * cos(cam.yaw);
        float dir_y = sin(cam.pitch);
        float dir_z = cos(cam.pitch) * sin(cam.yaw);

        if (IsKeyDown(KEY_W))
        {
            transform.x += dir_x * SPEED * delta;
            transform.z += dir_z * SPEED * delta;
        }
        if (IsKeyDown(KEY_S))
        {
            transform.x -= dir_x * SPEED * delta;
            transform.z -= dir_z * SPEED * delta;
        }
        if (IsKeyDown(KEY_D))
        {
            transform.x += cos(cam.yaw + PI/2) * SPEED * delta;
            transform.z += sin(cam.yaw + PI/2) * SPEED * delta;
        }
        if (IsKeyDown(KEY_A))
        {
            transform.x -= cos(cam.yaw + PI/2) * SPEED * delta;
            transform.z -= sin(cam.yaw + PI/2) * SPEED * delta;
        }

        if (IsKeyDown(KEY_SPACE))
        {
            transform.y += SPEED * delta;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT))
        {
            transform.y -= SPEED * delta;
        }
        
        cam.target_x = transform.x + dir_x;
        cam.target_y = transform.y + dir_y;
        cam.target_z = transform.z + dir_z;

        current_cam.transform = transform;
        current_cam.camera = cam;
    }

}

ActiveCamera CameraSystem::GetActiveCamera(){
    return current_cam;
}