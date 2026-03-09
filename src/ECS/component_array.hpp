#include <registry.hpp>
#include <unordered_map>

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void EntityRemoved(Entity e) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
public:
    void InsertData(Entity e, T component);
    void RemoveData(Entity e);
    T& GetData(Entity e);
    void EntityRemoved() override;
private:
    std::array<T, MAX_ENTITIES> componentArray;

    std::unordered_map<Entity e, size_t> entityToIndexMap;
    std::unordered_map<size_t, Entity e> indexToEntityMap;

    size_t component_size;
};