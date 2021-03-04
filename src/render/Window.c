#include <render/Window.h>

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <entity/Camera.h>

static GLFWwindow* window = NULL;
static double lastTime;
static unsigned int fps = 0;

void setGlStates()
{
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void setGlfwCallback()
{
    glfwSetKeyCallback(window, keyCallback);
}

bool initWindow(int width, int height, const char* name)
{
    if(!glfwInit())
    {
        printf("Erreur initialisation GLFW\n");
        return false;
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, name, NULL, NULL);

    if(window == NULL)
    {
        printf("Erreur ouverture fenetre\n");
        return false;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
    {
        printf("Erreur initialisation OpenGL\n");
        return false;
    }

    glfwSwapInterval(0);

    setGlStates();
    setGlfwCallback();

    lastTime = glfwGetTime();
    return true;
}

void clearDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void updateWindow()
{
    fps++;
    if(glfwGetTime() - lastTime >= 1.0)
    {
        fprintf(stdout, "FPS: %d\n", fps);
        fps = 0;
        lastTime += 1.0;
    }
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool isWindowOpen()
{
    return !glfwWindowShouldClose(window);
}

void terminateWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
