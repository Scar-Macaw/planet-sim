//https://austinmorlan.com/posts/entity_component_system/#what-is-an-ecs
//Good reading material and ECS tutorial

#include <cstdint>
#include <bitset>
#include <array>
#include <queue>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

class Registry {
public:
    Registry();

    Entity CreateEntity();
    void   RemoveEntity(Entity e);

    void SetSignature(Entity e, Signature s);
    Signature GetSignature(Entity e);

private:
    std::queue<Entity> avaliableEntities{};

    std::array<Signature, MAX_ENTITIES> signatures{};

    std::uint32_t entity_count{};
};