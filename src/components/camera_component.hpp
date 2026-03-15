#pragma once

//For cameras doing the rendering
struct CameraComponent {

    //Rotation, will be converted to target position by system
    double yaw   = 0.0;
    double pitch = 0.0;

    //The target position (what position is the camera looking at)
    float target_x = 0.0f;
    float target_y = 0.0f;
    float target_z = 0.0f;

    //Camera field of view
    float fovy = 70.0f;
};
