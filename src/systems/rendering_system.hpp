#pragma once

#include "../ecs/coordinator.hpp"

#include "../components/transform_component.hpp"
#include "../components/rendering_component.hpp"

#include "raylib.h"

#include <unordered_map>
#include <queue>

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

    ModelID CreateModel(const char* path);

    void RemoveModel(ModelID);

private:
    ActiveCamera current_cam;
    std::unordered_map<ModelID, Model> models = {};
    std::queue<ModelID> avaliableIDs = {};
    std::uint32_t model_count = 0;
};