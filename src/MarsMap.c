#include <stdio.h>

#include <render/Window.h>
#include <render/OpenGL.h>

#include <entity/Camera.h>

#include <world/Chunk.h>
#include <world/World.h>

int main()
{
    if(!initWindow(1024, 768, "Carte de Mars"))
    {
        return -1;
    }

    Shader shader;
    if(!loadShader(&shader, "res/shader/main.vert", "res/shader/main.frag"))
    {
        terminateWindow();
        return -1;
    }

    useShader(&shader);
    unsigned int projection = getUniformLocation(&shader, "projection");
    unsigned int view = getUniformLocation(&shader, "view");
    Matrix4f mat = genProjectionMatrix(70.f, 4.f/3.f, 1.f, (float)RENDER_DISTANCE*(float)CHUNK_SIZE);
    Vector3f vec;
    loadUniformMatrix4f(projection, &mat);
    mat = getIdentityMatrix();

    initWorld();
    while (isWindowOpen())
    {
        updateCamera();
        updateWorld();

        vec = getCameraPosition();
        mat.m03 = vec.x;
        mat.m13 = vec.y;
        mat.m23 = vec.z;
        loadUniformMatrix4f(view, &mat);

        clearDisplay();
        renderWorld();
        updateWindow();
    }

    deleteWorld();
    deleteShader(&shader);
    terminateWindow();
    return 0;
}
