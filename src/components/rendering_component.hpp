#pragma once

#include "../rendering/render_structs.hpp"

//Handles what will be rendered to the screen
struct RenderingComponent {
    //ID's are passed to renderer
    ModelID mesh_id = 0;
    float scale = 1.0f;
};