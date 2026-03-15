#include "simulator.hpp"
#include <chrono>
#include <iostream>

Coordinator coordinator;

void Simulator::begin_simulation() {

    //Initialize coordinator
    coordinator.Init();

    //Register all component structs
    coordinator.RegisterComponent<TransformComponent>();
    coordinator.RegisterComponent<RenderingComponent>();
    coordinator.RegisterComponent<CameraComponent>();
    
    //Register the rendering system
    auto rendering_system = coordinator.RegisterSystem<RenderingSystem>();
    Signature rendering_sig;
    rendering_sig.set(coordinator.GetComponentType<TransformComponent>());
    rendering_sig.set(coordinator.GetComponentType<RenderingComponent>());
    coordinator.SetSystemSignature<RenderingSystem>(rendering_sig);

    //Register the camera system
    auto camera_system = coordinator.RegisterSystem<CameraSystem>();
    Signature camera_sig;
    camera_sig.set(coordinator.GetComponentType<TransformComponent>());
    camera_sig.set(coordinator.GetComponentType<CameraComponent>());
    coordinator.SetSystemSignature<CameraSystem>(camera_sig);

    //Create the camera
    Entity camera_entity = coordinator.CreateEntity();
    TransformComponent camera_transform = {0.0f, 0.0f, 5.0f};
    CameraComponent camera_settings = {};
    camera_settings.fovy = 70.0f;

    coordinator.AddComponent(camera_entity, camera_transform);
    coordinator.AddComponent(camera_entity, camera_settings);

    //Create sphere entity
    Entity sphere_entity = coordinator.CreateEntity();
    TransformComponent sphere_transform = {};
    RenderingComponent sphere_rendering = {};
    coordinator.AddComponent(sphere_entity, sphere_transform);
    coordinator.AddComponent(sphere_entity, sphere_rendering);

    rendering_system->Init();

    auto last = std::chrono::high_resolution_clock::now();

    //Main loop goes here
    while(rendering_system->is_running())
    {   
        std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last);
        last = std::chrono::high_resolution_clock::now();

        double dt = milliseconds.count() / 1000.0;

        camera_system->Update(dt, &coordinator);
        rendering_system->SetActiveCamera(camera_system->GetActiveCamera());
        rendering_system->Update(dt, &coordinator);
    }

    rendering_system->Shutdown();
}