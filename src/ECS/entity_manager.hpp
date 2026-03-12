//https://austinmorlan.com/posts/entity_component_system/#what-is-an-ecs
//Good reading material and ECS tutorial
#pragma once

#include "ecs_definitions.hpp"
#include <array>
#include <queue>

class EntityManager {
public:
    EntityManager();

    Entity CreateEntity();
    void   RemoveEntity(Entity e);

    void SetSignature(Entity e, Signature s);
    Signature GetSignature(Entity e);

private:
    std::queue<Entity> avaliableEntities{};

    std::array<Signature, MAX_ENTITIES> signatures{};

    std::uint32_t entity_count{};
};