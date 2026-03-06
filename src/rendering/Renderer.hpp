#pragma once
#include "RenderStructs.hpp"
#include <string>
#include <unordered_map>

//Desired FPS
const int TARGET_FPS = 60;

//Handles rendering
class Renderer {
    public:
        void Init(Vec2i size);
        void Shutdown();

        void StartFrame();
        void FinishFrame();

        void ClearScreen();

        RenderModel CreateRenderModel(const char* path);
        //void DrawRenderModel(RenderModel render_model, Vec3R pos);
        void RemoveRenderModel(RenderModel render_model);

        //void SetCamera(Cam& camera);

        bool IsRunning();
};