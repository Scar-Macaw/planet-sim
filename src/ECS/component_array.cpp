#include "component_array.hpp"

template <typename T>
void ComponentArray<T>::InsertData(Entity e, T component){
    size_t new_index = component_size;
    entityToIndexMap[e] = new_index;
    indexToEntityMap[new_index] = e;
    componentArray[new_index] = component;
    component_size++;
}

template <typename T>
void ComponentArray<T>::RemoveData(Entity e){
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

template <typename T>
T& ComponentArray<T>::GetData(Entity e){
    return componentArray[entityToIndexMap[e]];  
}

template <typename T>
void ComponentArray<T>::EntityRemoved(Entity e) {
    if (entityToIndexMap.find(e) != entityToIndexMap.end())
		{
			RemoveData(e);
		}
}