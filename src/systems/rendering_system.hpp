#pragma once

#include "../ecs/coordinator.hpp"

#include "../components/transform_component.hpp"
#include "../components/rendering_component.hpp"

#include "raylib.h"

#include "../rendering/render_structs.hpp"

class RenderingSystem : public System 
{
public:
    void Init();

    void Shutdown();

    void BeginFrame();
    void EndFrame();

    void Update(float delta, Coordinator* coordinator);
    bool is_running();

    void SetActiveCamera(ActiveCamera cam);

    float GetFrameDifference();
private:
    ActiveCamera current_cam;
};