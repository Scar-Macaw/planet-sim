/*This is for ECS components

    Examples of entities and the components they use:
        Celestial Body:
            Transform Component
            Physics Component
            Rendering Component
        Camera:
            Transform Component
            Camera Component
        UI:
            Transform Component
            Rendering Component
            UI Component
*/

//Base component class
class Component {
    int id = 0;
};

//Transform (Position and Rotation)
class TransformComponent : Component {
    //Position Information
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    //Rotation Information
    float rx = 0.0f;
    float ry = 0.0f;
    float rz = 0.0f;
};

//Physics stuff goes here
class PhysicsComponent : Component {
    //I dont know what to put here yet
    float mass = 1.0f;
};

//Handles what will be rendered to the screen
class RenderingComponent : Component {
    //ID's are passed to renderer
    int mesh_id = 0;
    int texture_id = 0;
};

//For cameras doing the rendering
class CameraComponent : Component {
    //Up direction of the camera
    const float UP_X = 0.0f;
    const float UP_Y = 1.0f;
    const float UP_Z = 0.0f;

    //The target position (what position is the camera looking at)
    float target_x = 0.0f;
    float target_y = 0.0f;
    float target_z = 0.0f;

    //Camera field of view
    float fovy = 90.0f;

};

//TBD if neccessary
class UIComponent : Component {
    //Blank for now
};