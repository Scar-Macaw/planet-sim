#pragma once

#include "../ecs/coordinator.hpp"

#include "../components/transform_component.hpp"
#include "../components/rendering_component.hpp"
#include "../components/camera_component.hpp"

#include "../systems/rendering_system.cpp"

class Simulator {
    public:
        void begin_simulation();
    private:
        Coordinator coordinator;
};