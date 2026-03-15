#include "../ecs/coordinator.hpp"

#include "../rendering/render_structs.hpp"

#include "raylib.h"

class CameraSystem : public System {
public:
    void Update(float delta, Coordinator* coordinator);
    ActiveCamera GetActiveCamera();
private:
    ActiveCamera current_cam;
    const double SENSITIVITY = 1.75;
    const double SPEED = 7.0;

    const double PITCH_CLAMP = 1.0;
};