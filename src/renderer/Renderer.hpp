#pragma once

//Desired FPS
const int TARGET_FPS = 60;

//Handles rendering
class Renderer {
    public:

        //Start up and shut down the window and renderer
        static void Init(int width, int height);
        static void Shutdown();

        static void BeginFrame();
        static void EndFrame();
        static void Clear();
        static bool ShouldClose();

};