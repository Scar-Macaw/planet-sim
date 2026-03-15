#pragma once

#include <memory>
#include "component_manager.hpp"
#include "entity_manager.hpp"
#include "system_manager.hpp"

class Coordinator 
{
public:
    
    void Init();

    Entity CreateEntity();

    void RemoveEntity(Entity e);

    template<typename T>
    void RegisterComponent()
    {
        componentManager->RegisterComponent<T>();
    }

    template<typename T>
    void AddComponent(Entity e, T component)
    {
        componentManager->AddComponent<T>(e, component);

        auto sig = entityManager->GetSignature(e);
        sig.set(componentManager->GetComponentType<T>(), true);
        entityManager->SetSignature(e, sig);
        systemManager->EntitySignatureChanged(e, sig);
    }

    template<typename T>
    void RemoveComponent(Entity e)
    {
        componentManager->RemoveComponent<T>(e);

        auto sig = entityManager->GetSignature(e);
        sig.set(componentManager->GetComponentType<T>(), false);
        entityManager->SetSignature(e, sig);
        systemManager->EntitySignatureChanged(e, sig);
    }

    template<typename T>
    T& GetComponent(Entity e)
    {
        return componentManager->GetComponent<T>(e);
    }

    template <typename T>
    ComponentType GetComponentType()
    {
        return componentManager->GetComponentType<T>();
    }

    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        return systemManager->RegisterSystem<T>();
    }

    template<typename T>
    void SetSystemSignature(Signature sig)
    {
        systemManager->SetSignature<T>(sig);
    }

private:
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<SystemManager> systemManager;
};