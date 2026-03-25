#pragma once

#include "../ecs/coordinator.hpp"

#include "../systems/rendering_system.hpp"
#include "../systems/camera_system.hpp"
#include "../systems/debug_draw_system.hpp"
#include "../systems/mesh_generator_system.hpp"

class Simulator {
    public:
        void begin_simulation();
};