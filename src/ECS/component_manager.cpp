#include "component_manager.hpp"

template<typename T>
void ComponentManager::RegisterComponent(){
    const char* typeName = typeid(T).name();

    componentTypes.insert({typeName, nextComponentType});

    componentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

    nextComponentType++;
}

template<typename T>
ComponentType ComponentManager::GetComponentType(){
    const char* typeName = typeid(T).name();

    return componentTypes[typeName];
}

template<typename T>
void ComponentManager::AddComponent(Entity e, T component){
    GetComponentArray<T>()->InsertData(e, component);
}

template<typename T>
void ComponentManager::RemoveComponent(Entity e){
    GetComponentArray<T>()->RemoveData(e);
}

template<typename T>
T& ComponentManager::GetComponent(Entity e){
    return GetComponentArray<T>()->GetData(e);
}

void ComponentManager::EntityRemoved(Entity e){
    for (auto const& pair : componentArrays)
    {
        auto const& component = pair.second;

        component->EntityRemoved(e);
    }
}

template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::GetComponentArray(){
    const char* typeName = typeid(T).name();

    return std::static_pointer_cast<ComponentArray>>(componentArrays[typeName]);
}
