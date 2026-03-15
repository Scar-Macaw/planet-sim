#include "system_manager.hpp"

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
