#include "mesh_generator_system.hpp"

void MeshGeneratorSystem::SetMeshes(RenderingSystem* render_system, Coordinator* coordinator)
{
    for (auto const& e : entities)
    {
        auto& render    = coordinator->GetComponent<RenderingComponent>(e);
        auto& collision = coordinator->GetComponent<CollisionComponent>(e);

        render.mesh_id = render_system->CreateModel("../assets/rendering_test/cow.obj");
        render.scale = collision.radius;
    }
}