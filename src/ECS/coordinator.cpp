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

template<typename T>
void Coordinator::RegisterComponent()
{
    componentManager->RegisterComponent<T>();
}

template<typename T>
void Coordinator::AddComponent(Entity e, T component)
{
    componentManager->AddComponent<T>(e, component);

    auto sig = entityManager->GetSignature(e);
    sig.set(componentManager->GetComponentType<T>(), true);
    entityManager->SetSignature(e, sig);
    systemManager->EntitySignatureChanged(e, sig);
}

template<typename T>
void Coordinator::RemoveComponent(Entity e)
{
    componentManager->RemoveComponent<T>(e);

    auto sig = entityManager->GetSignature(e);
    sig.set(componentManager->GetComponentType<T>(), false);
    entityManager->SetSignature(e, sig);
    systemManager->EntitySignatureChanged(e, sig);
}

template<typename T>
T& Coordinator::GetComponent(Entity e)
{
    return componentManager->GetComponent<T>(e);
}

template <typename T>
ComponentType Coordinator::GetComponentType()
{
    return componentManager->GetComponentType<T>();
}

template<typename T>
std::shared_ptr<T> Coordinator::RegisterSystem()
{
    return systemManager->RegisterSystem<T>();
}

template<typename T>
void Coordinator::SetSystemSignature(Signature sig)
{
    systemManager->SetSignature<T>(sig);
}
