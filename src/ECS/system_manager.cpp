#include "system_manager.hpp"

template<typename T>
std::shared_ptr<T> SystemManager::RegisterSystem(){
    const char* typeName = typeid(T).name();

    auto system = std::make_shared<T>();
    systems.insert({typeName, system});
    return system;
}

template<typename T>
void SystemManager::SetSignature(Signature sig){
    const char* typeName = typeid(T).name();

    signatures.insert(typeName, sig);
}

void SystemManager::EntityRemoved(Entity e){
    for (auto const& pair : systems)
    {
        auto const& system = pair.second;
        
        system->entities.erase(e);
    }
}

void SystemManager::EntitySignatureChanged(Entity e, Signature esig){
    for (auto const& pair : systems)
    {
        auto const& type = pair.first;
        auto const& system = pair.second;
        auto const& systemSignature = signatures[type];

        if ((esig & systemSignature) == systemSignature)
        {
            system->entities.insert(e);
        } 
        else
        {
            system->entities.erase(e);
        }
    }
}
