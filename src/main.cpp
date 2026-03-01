#include <iostream>
#include "rendering/Renderer.hpp"
#include "rendering/RenderStructs.hpp"

int main() {
    Renderer renderer = Renderer();

    Cam camera   = {};
    camera.position = Vec3R(0.0f, 0.0f,  15.0f);
    camera.target   = Vec3R(0.0f, 0.0f,  0.0f);
    camera.up       = Vec3R(0.0f, 1.0f,  0.0f);
    camera.fov      = 90.0f;

    Vec2i size = {};
    size.x = 800;
    size.y = 600;

    renderer.Init(size);

    RenderModel cow = renderer.CreateRenderModel("../../assets/rendering_test/cow.obj");
    RenderModel teapot = renderer.CreateRenderModel("../../assets/rendering_test/teapot.obj");

    while(renderer.IsRunning()) {
        camera.position.z -= 0.25;

        renderer.ClearScreen();
        
        renderer.StartFrame();

        renderer.SetCamera(camera);

        Vec3R position = {-10.0f, 0.0f, 0.0f};
        Vec3R position_2 = {10.0f, 0.0f, 0.0f};

        renderer.DrawRenderModel(cow, position);
        renderer.DrawRenderModel(teapot, position_2);

        renderer.FinishFrame();
    }

    renderer.Shutdown();
}
