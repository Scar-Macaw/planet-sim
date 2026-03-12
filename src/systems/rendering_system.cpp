#include "../ecs/coordinator.cpp"

#include "../components/transform_component.hpp"
#include "../components/rendering_component.hpp"

#include "camera_system.cpp"

#include "raylib.h"

class RenderingSystem : public System{
public:
    void Init()
    {
        SetTargetFPS(60);
        InitWindow(800, 800, "Simulation");
    }

    void Shutdown()
    {
        CloseWindow();
    }

    void Update(Coordinator* coordinator, CameraSystem* camera_system)
    {
        
    }

    bool is_running()
    {
        return !WindowShouldClose();
    }
};