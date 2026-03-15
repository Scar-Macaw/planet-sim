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
    coordinator.RegisterComponent<VelocityComponent>();

    //Register debug draw system
    auto debug_draw_system = coordinator.RegisterSystem<DebugDrawSystem>();
    Signature debug_sig;
    debug_sig.set(coordinator.GetComponentType<TransformComponent>());
    debug_sig.set(coordinator.GetComponentType<VelocityComponent>());
    coordinator.SetSystemSignature<DebugDrawSystem>(debug_sig);
    
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
    TransformComponent camera_transform = {-5.0f, 1.0f, 0.0f};
    CameraComponent camera_settings = {};
    camera_settings.fovy = 70.0f;

    coordinator.AddComponent(camera_entity, camera_transform);
    coordinator.AddComponent(camera_entity, camera_settings);

    //Create sphere entities
    for(int i = 0; i < 50; i++)
    {
        Entity sphere_entity = coordinator.CreateEntity();
        TransformComponent sphere_transform = {float(rand()%40) - 20.0f, float(rand()%5), float(rand()%40) - 20.0f};
        VelocityComponent  sphere_velocity  = {(float(rand()%100) - 50.0f)/100, (float(rand()%100) - 50.0f)/100, (float(rand()%100) - 50.0f)/100};
        RenderingComponent sphere_rendering = {};
        coordinator.AddComponent(sphere_entity, sphere_transform);
        coordinator.AddComponent(sphere_entity, sphere_velocity);
        coordinator.AddComponent(sphere_entity, sphere_rendering);
    }

    rendering_system->Init();

    auto last = std::chrono::high_resolution_clock::now();

    //Main loop goes here
    while(rendering_system->is_running())
    {   
        float dt = rendering_system->GetFrameDifference();

        //Stuff for physics goes here


        //Stuff for rendering below

        camera_system->Update(dt, &coordinator);
        rendering_system->SetActiveCamera(camera_system->GetActiveCamera());

        rendering_system->BeginFrame();

        rendering_system->Update(dt, &coordinator);
        debug_draw_system->Update(dt, &coordinator);

        rendering_system->EndFrame();
        
    }

    rendering_system->Shutdown();
}