#include <entity/Camera.h>

#include <stdbool.h>

typedef enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    TOP,
    DOWN
} Direction;

static bool directions[6] = {false, false, false, false, false, false};
static Vector3f position = {.x = 0, .y = 0, .z = 0};
static const Vector3f forward = {.x = 0, .y = 0, .z = 1};
static const Vector3f right = {.x = 1, .y = 0, .z = 0};
static const Vector3f top = {.x = 0, .y = 1, .z = 0};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            directions[FORWARD] = true;
            break;
        case GLFW_KEY_S:
            directions[BACKWARD] = true;
            break;
        case GLFW_KEY_A:
            directions[LEFT] = true;
            break;
        case GLFW_KEY_D:
            directions[RIGHT] = true;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            directions[DOWN] = true;
            break;
        case GLFW_KEY_SPACE:
            directions[TOP] = true;
            break;        
        default:
            break;
        }
    }
    else if(action == GLFW_RELEASE)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            directions[FORWARD] = false;
            break;
        case GLFW_KEY_S:
            directions[BACKWARD] = false;
            break;
        case GLFW_KEY_A:
            directions[LEFT] = false;
            break;
        case GLFW_KEY_D:
            directions[RIGHT] = false;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            directions[DOWN] = false;
            break;
        case GLFW_KEY_SPACE:
            directions[TOP] = false;
            break;        
        default:
            break;
        }
    }
}

void updateCamera()
{
    if(directions[FORWARD]) {
        position.x += forward.x;
        position.y += forward.y;
        position.z += forward.z;        
    }
    else if(directions[BACKWARD]) {
        position.x -= forward.x;
        position.y -= forward.y;
        position.z -= forward.z;        
    }

    if(directions[LEFT]) {
        position.x += right.x;
        position.y += right.y;
        position.z += right.z;        
    }
    else if(directions[RIGHT]) {
        position.x -= right.x;
        position.y -= right.y;
        position.z -= right.z;        
    }

    if(directions[TOP]) {
        position.x -= top.x;
        position.y -= top.y;
        position.z -= top.z;        
    }
    else if(directions[DOWN]) {
        position.x += top.x;
        position.y += top.y;
        position.z += top.z;        
    }
}

Vector3f getCameraPosition()
{
    return position;
}
