#pragma once

//For cameras doing the rendering
struct CameraComponent {
    //The target position (what position is the camera looking at)
    float target_x = 0.0f;
    float target_y = 0.0f;
    float target_z = 0.0f;

    //Camera field of view
    float fovy = 90.0f;
};
