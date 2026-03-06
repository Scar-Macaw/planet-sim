#include "Components.hpp"
#include <unordered_map>

/*
The idea is that essentially, we want to create a unique ID for every single entity
whenever we want an entities component, we call that unique ID
If we have a component and want an entity we can get the components key
*/

class EntityManager {

    public:
        unsigned long CreateEntityID();
        void AddTransformComponent(TransformComponent component, unsigned long id);
        TransformComponent GetTransformComponent(unsigned long id);
    
    private:
        unsigned long next_id = 0;
        std::unordered_map<unsigned long, TransformComponent> component;
};