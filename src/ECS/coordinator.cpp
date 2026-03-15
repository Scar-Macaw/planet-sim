#include "coordinator.hpp"

void Coordinator::Init(){
    componentManager = std::make_unique<ComponentManager>();
    entityManager    = std::make_unique<EntityManager>();
    systemManager    = std::make_unique<SystemManager>();
}

Entity Coordinator::CreateEntity()
{
    return entityManager->CreateEntity();
}

void Coordinator::RemoveEntity(Entity e)
{
    entityManager->RemoveEntity(e);
    componentManager->EntityRemoved(e);
    systemManager->EntityRemoved(e);
}