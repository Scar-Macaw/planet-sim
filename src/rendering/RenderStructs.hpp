#pragma once
#include <vector>

//Vector 3 for rendering
struct Vec3R {
    float x, y, z;
};

//Vector 2 with integers
struct Vec2i {
    int x, y;
};

//Mesh
struct RenderModel {
    int id = 0;
};

//Camera
struct Cam {
    Vec3R position;
    Vec3R target;
    Vec3R up;
    float fov;
};