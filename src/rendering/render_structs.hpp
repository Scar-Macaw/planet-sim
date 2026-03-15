#pragma once
#include <vector>

#include "../components/transform_component.hpp"
#include "../components/camera_component.hpp"

struct ActiveCamera {
    TransformComponent transform;
    CameraComponent camera;
};