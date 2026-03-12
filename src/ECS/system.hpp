#include <set>
#include "ecs_definitions.cpp"

class System {

public:
    std::set<Entity> entities;
};

/*
EXAMPLE:
for (auto const& entity : mEntities)
{
	auto& transform = GetComponent<Transform>(entity);

	transform.position.x += 1;
}
*/