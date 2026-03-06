#include "EntityManager.hpp"

unsigned long EntityManager::CreateEntityID(){
    unsigned long new_id = next_id;

    next_id++;

    return new_id;
}
