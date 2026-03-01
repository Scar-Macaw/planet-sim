#include "Renderer.hpp"
#include "raylib.h"

void Renderer::Init(int width, int height){
    InitWindow(width, height, "Window");
    SetTargetFPS(TARGET_FPS);
}

void Renderer::Shutdown(){
    CloseWindow();
}

void Renderer::BeginFrame(){
    BeginFrame();
}

void Renderer::EndFrame(){
    EndFrame();
}

bool Renderer::ShouldClose(){
    return WindowShouldClose();
}