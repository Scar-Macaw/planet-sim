#include "simulator.hpp"

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

    //Create sphere entity
    Entity sphere_entity = coordinator.CreateEntity();
    TransformComponent sphere_transform = {};
    RenderingComponent sphere_rendering = {};
    coordinator.AddComponent(sphere_entity, sphere_transform);
    coordinator.AddComponent(sphere_entity, sphere_rendering);

    //Create camera entity
    Entity camera_entity = coordinator.CreateEntity();
    TransformComponent camera_transform = {0.0f, 0.0f, 5.0f};
    CameraComponent camera_camera = {};
    coordinator.AddComponent(camera_entity, camera_transform);
    coordinator.AddComponent(camera_entity, camera_camera);

    while(rendering_system->is_running())
    {
        //camera_system->Update(&coordinator);
        rendering_system->Update(&coordinator, camera_system.get());
    }

    rendering_system->Shutdown();
}