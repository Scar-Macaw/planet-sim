#pragma once

#include <memory>
#include "component_manager.hpp"
#include "entity_manager.hpp"
#include "system_manager.hpp"

class Coordinator {
public:
    
    void Init();
    Entity CreateEntity();
    void RemoveEntity(Entity e);
    template<typename T>
    void RegisterComponent();
    template<typename T>
    void AddComponent(Entity e, T component);
    template<typename T>
    void RemoveComponent(Entity e);
    template<typename T>
    T& GetComponent(Entity e);
    template <typename T>
    ComponentType GetComponentType();
    template<typename T>
    std::shared_ptr<T> RegisterSystem();
    template<typename T>
    void SetSystemSignature(Signature sig);

private:
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<SystemManager> systemManager;
};