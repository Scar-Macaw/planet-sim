#pragma once

#include "ecs_definitions.hpp"
#include "system.hpp"
#include <memory>
#include <unordered_map>

class SystemManager
{
public:
    template<typename T>
    std::shared_ptr<T> RegisterSystem();

    template<typename T>
    void SetSignature(Signature sig);

    void EntityRemoved(Entity e);

    void EntitySignatureChanged(Entity e, Signature esig);

private:
    std::unordered_map<const char*, Signature> signatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> systems{};
};