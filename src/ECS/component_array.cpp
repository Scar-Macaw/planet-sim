#include <component_array.hpp>

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

}

template <typename T>
T& ComponentArray<T>::GetData(Entity e){

}

template <typename T>
void ComponentArray<T>::EntityRemoved() {

}