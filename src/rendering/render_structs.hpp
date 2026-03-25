#pragma once
#include <vector>

#include "../components/transform_component.hpp"
#include "../components/camera_component.hpp"

using ModelID = std::uint32_t;
const int MAX_MODELS = 10000;

struct ActiveCamera {
    TransformComponent transform;
    CameraComponent camera;
};
