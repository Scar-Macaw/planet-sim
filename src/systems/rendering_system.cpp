#include "rendering_system.hpp"

void RenderingSystem::Init()
{
    SetTargetFPS(60);
    InitWindow(800, 600, "Simulation");
}

void RenderingSystem::Shutdown()
{
    CloseWindow();
}

float test = 0.0f;

void RenderingSystem::Update(double delta, Coordinator* coordinator)
{
    ClearBackground(BLACK);

    Camera3D cam    = {};
    cam.position    = {current_cam.transform.x, current_cam.transform.y, current_cam.transform.z};
    cam.target      = {current_cam.camera.target_x, current_cam.camera.target_y, current_cam.camera.target_z};
    cam.fovy        = current_cam.camera.fovy;
    cam.up          = {0.0f, 1.0f, 0.0f};
    cam.projection  = CAMERA_PERSPECTIVE;
    
    test += 0.01f;

    BeginDrawing();
    BeginMode3D(cam);

    for (auto const& e : entities)
    {
        auto& transform = coordinator->GetComponent<TransformComponent>(e);
        auto& render    = coordinator->GetComponent<RenderingComponent>(e);

        transform.x = cos(test) * 10.0f;
        transform.z = sin(test) * 10.0f;

        Vector3 mesh_pos = {transform.x, transform.y, transform.z};

        DrawSphere(mesh_pos, 1, BLUE);
    }

    DrawGrid(20, 2.0f);

    EndMode3D();
    EndDrawing();
}

bool RenderingSystem::is_running()
{
    return !WindowShouldClose();
}

void RenderingSystem::SetActiveCamera(ActiveCamera cam)
{
    current_cam = cam;   
}