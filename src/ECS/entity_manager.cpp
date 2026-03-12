#include "entity_manager.hpp"

EntityManager::EntityManager(){
    for(Entity e = 0; e < MAX_ENTITIES; e++){
        avaliableEntities.push(e);
    }
}

Entity EntityManager::CreateEntity(){

    Entity e = avaliableEntities.front();
    avaliableEntities.pop();
    entity_count++;

    return e;
}

void EntityManager::RemoveEntity(Entity e){

    signatures[e].reset();

    avaliableEntities.push(e);
    --entity_count;
}

void EntityManager::SetSignature(Entity e, Signature s){
    signatures[e] = s;
}

Signature EntityManager::GetSignature(Entity e){
    return signatures[e];
}