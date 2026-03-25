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
    coordinator.RegisterComponent<PhysicsComponent>();
    coordinator.RegisterComponent<CollisionComponent>();

    //Register debug draw system
    auto debug_draw_system = coordinator.RegisterSystem<DebugDrawSystem>();
    Signature debug_sig;
    debug_sig.set(coordinator.GetComponentType<TransformComponent>());
    debug_sig.set(coordinator.GetComponentType<PhysicsComponent>());
    coordinator.SetSystemSignature<DebugDrawSystem>(debug_sig);
    
    //Register the rendering system
    auto rendering_system = coordinator.RegisterSystem<RenderingSystem>();
    Signature rendering_sig;
    rendering_sig.set(coordinator.GetComponentType<TransformComponent>());
    rendering_sig.set(coordinator.GetComponentType<RenderingComponent>());
    coordinator.SetSystemSignature<RenderingSystem>(rendering_sig);

    //Register mesh generator system
    auto mesh_generator_system = coordinator.RegisterSystem<MeshGeneratorSystem>();
    Signature mesh_generator_sig;
    rendering_sig.set(coordinator.GetComponentType<RenderingComponent>());
    rendering_sig.set(coordinator.GetComponentType<CollisionComponent>());
    coordinator.SetSystemSignature<RenderingSystem>(mesh_generator_sig);

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

    //Create Body 1
    Entity body1 = coordinator.CreateEntity();
    TransformComponent body1_transform = {};
    RenderingComponent body1_rendering = {};
    PhysicsComponent   body1_physics   = {0.5f};
    CollisionComponent body1_collision = {0.5f};
    coordinator.AddComponent(body1, body1_transform);
    coordinator.AddComponent(body1, body1_rendering);
    coordinator.AddComponent(body1, body1_physics);
    coordinator.AddComponent(body1, body1_collision);

    //Create Body 2
    Entity body2 = coordinator.CreateEntity();
    TransformComponent body2_transform = {0.0f, 5.0f, 0.0f};
    RenderingComponent body2_rendering = {};
    PhysicsComponent   body2_physics   = {0.1f};
    CollisionComponent body2_collision = {0.1f};
    coordinator.AddComponent(body2, body2_transform);
    coordinator.AddComponent(body2, body2_rendering);
    coordinator.AddComponent(body2, body2_physics);
    coordinator.AddComponent(body2, body2_collision);

    rendering_system->Init();

    mesh_generator_system->SetMeshes(rendering_system.get(), &coordinator);

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