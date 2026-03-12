#include "ecs_definitions.cpp"
#include "component_array.hpp"
#include <memory>

class ComponentManager {
public:
    template<typename T>
    void RegisterComponent();

    template<typename T>
    ComponentType GetComponentType();

    template<typename T>
    void AddComponent(Entity e, T component);

    template<typename T>
    void RemoveComponent(Entity e);

    template<typename T>
    T& GetComponent(Entity e);

    void EntityRemoved(Entity e);
private:
    std::unordered_map<const char*, ComponentType> componentTypes{};
    std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};

    ComponentType nextComponentType{};

    template<typename T>
    std::shared_ptr<ComponentArray<T>> GetComponentArray();
};