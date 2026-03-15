#include "rendering_system.hpp"

void RenderingSystem::Init()
{
    SetTargetFPS(30);
    InitWindow(800, 600, "Simulation");
}

void RenderingSystem::Shutdown()
{
    CloseWindow();
}

void RenderingSystem::BeginFrame()
{
    ClearBackground(BLACK);

    Camera3D cam    = {};
    cam.position    = {current_cam.transform.x, current_cam.transform.y, current_cam.transform.z};
    cam.target      = {current_cam.camera.target_x, current_cam.camera.target_y, current_cam.camera.target_z};
    cam.fovy        = current_cam.camera.fovy;
    cam.up          = {0.0f, 1.0f, 0.0f};
    cam.projection  = CAMERA_PERSPECTIVE;

    BeginDrawing();

    DrawFPS(0, 0);

    BeginMode3D(cam);
}

void RenderingSystem::EndFrame()
{
    EndMode3D();
    EndDrawing();
}

void RenderingSystem::Update(float delta, Coordinator* coordinator)
{

    for (auto const& e : entities)
    {
        auto& transform = coordinator->GetComponent<TransformComponent>(e);
        auto& render    = coordinator->GetComponent<RenderingComponent>(e);

        Vector3 mesh_pos = {transform.x, transform.y, transform.z};

        DrawSphere(mesh_pos, 0.1f, WHITE);
    }

    DrawGrid(20, 2.0f);

}

bool RenderingSystem::is_running()
{
    return !WindowShouldClose();
}

void RenderingSystem::SetActiveCamera(ActiveCamera cam)
{
    current_cam = cam; 
}

float RenderingSystem::GetFrameDifference()
{
    return GetFrameTime();
}
