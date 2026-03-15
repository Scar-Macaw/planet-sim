#pragma once

#include "ecs_definitions.hpp"
#include <unordered_map>

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void EntityRemoved(Entity e) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {

public:

    void InsertData(Entity e, T component)
    {
        size_t new_index = component_size;
        entityToIndexMap[e] = new_index;
        indexToEntityMap[new_index] = e;
        componentArray[new_index] = component;
        component_size++;
    }

    void RemoveData(Entity e)
    {
        size_t indexOfRemovedEntity = entityToIndexMap[e];
        size_t indexOfLastElement = component_size - 1;
        componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

        Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
        entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
        indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

        entityToIndexMap.erase(e);
        indexToEntityMap.erase(indexOfLastElement);

        component_size--;
    }

    T& GetData(Entity e)
    {
        return componentArray[entityToIndexMap[e]];  
    }

    void EntityRemoved(Entity e) 
    {
        if (entityToIndexMap.find(e) != entityToIndexMap.end())
            {
                RemoveData(e);
            }
    }
private:
    std::array<T, MAX_ENTITIES> componentArray;

    std::unordered_map<Entity, size_t> entityToIndexMap;
    std::unordered_map<size_t, Entity> indexToEntityMap;

    size_t component_size;
};