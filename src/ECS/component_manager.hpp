#pragma once

#include "ecs_definitions.hpp"
#include "component_array.hpp"
#include <memory>

class ComponentManager {
public:

    template<typename T>
    void RegisterComponent()
    {
        const char* typeName = typeid(T).name();

        componentTypes.insert({typeName, nextComponentType});

        componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

        nextComponentType++;
    }

    template<typename T>
    ComponentType GetComponentType()
    {
        const char* typeName = typeid(T).name();

        return componentTypes[typeName];
    }

    template<typename T>
    void AddComponent(Entity e, T component)
    {
        GetComponentArray<T>()->InsertData(e, component);
    }

    template<typename T>
    void RemoveComponent(Entity e)
    {
        GetComponentArray<T>()->RemoveData(e);
    }

    template<typename T>
    T& GetComponent(Entity e)
    {
        return GetComponentArray<T>()->GetData(e);
    }

    void EntityRemoved(Entity e)
    {
        for (auto const& pair : componentArrays)
        {
            auto const& component = pair.second;

            component->EntityRemoved(e);
        }
    }


private:
    std::unordered_map<const char*, ComponentType> componentTypes{};
    std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};

    ComponentType nextComponentType{};

    template<typename T>
    std::shared_ptr<ComponentArray<T>> GetComponentArray()
    {
        const char* typeName = typeid(T).name();

        return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
    }
};