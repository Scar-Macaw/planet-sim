#include "renderer.hpp"
#include "raylib.h"
/*
std::unordered_map<int, Model> models = {};
int ID_count = 0;

void Renderer::Init(Vec2i size) {
    SetTargetFPS(60);
    InitWindow(size.x, size.y, "Window");
}

void Renderer::Shutdown() {
    CloseWindow();
}

void Renderer::StartFrame() {
    BeginDrawing();
}

void Renderer::FinishFrame() {
    EndMode3D();
    EndDrawing();
}

void Renderer::ClearScreen() {
    ClearBackground(BLACK);
}

RenderModel Renderer::CreateRenderModel(const char* path) {
    RenderModel rm = {};
    Model model = LoadModel(path);
    models[ID_count] = model;
    rm.id = ID_count;
    ID_count++;
    return rm;
}

/*void Renderer::DrawRenderModel(RenderModel render_model, Vec3R pos) {
    Model model = models[render_model.id];
    Vector3 position = {};
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;
    DrawModel(model, position, 1.0f, WHITE);
}

void Renderer::RemoveRenderModel(RenderModel render_model) {
    
}

/*void Renderer::SetCamera(Cam& camera) {
    Camera3D rlcam = {};
    rlcam.position = {camera.position.x, camera.position.y, camera.position.z};
    rlcam.target   = {camera.target.x, camera.target.y, camera.target.z};
    rlcam.up       = {camera.up.x, camera.up.y, camera.up.z};
    rlcam.fovy     = camera.fov;
    rlcam.projection = CameraProjection::CAMERA_PERSPECTIVE;

    BeginMode3D(rlcam);
}

bool Renderer::IsRunning() {
    return !WindowShouldClose();
}*/