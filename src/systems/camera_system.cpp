#include "../ecs/coordinator.hpp"

#include "../components/transform_component.hpp"
#include "../components/camera_component.hpp"

#include "raylib.h"

class CameraSystem : public System {
public:

    Camera3D current_cam = {};

    void Update(Coordinator* coordinator)
    {
        for (auto const& e : entities)
        {
            auto& transform = coordinator->GetComponent<TransformComponent>(e);
            auto& cam       = coordinator->GetComponent<CameraComponent>(e);

            current_cam.position = {transform.x, transform.y, transform.z};
            current_cam.target   = {cam.target_x, cam.target_y, cam.target_z};

            current_cam.projection = CAMERA_FIRST_PERSON;
            current_cam.fovy = cam.fovy;
            current_cam.up = {0.0f, 1.0f, 0.0f};
        }

    }

    Camera3D getCamera()
    {
        return current_cam;
    }
};