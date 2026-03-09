#include <registry.hpp>

Registry::Registry(){
    for(Entity e = 0; e < MAX_ENTITIES; e++){
        avaliableEntities.push(e);
    }
}

Entity Registry::CreateEntity(){

    Entity e = avaliableEntities.front();
    avaliableEntities.pop();
    entity_count++;

    return e;
}

void Registry::RemoveEntity(Entity e){

    signatures[e].reset();

    avaliableEntities.push(e);
    --entity_count;
}

void Registry::SetSignature(Entity e, Signature s){
    signatures[e] = s;
}

Signature Registry::GetSignature(Entity e){
    return signatures[e];
}