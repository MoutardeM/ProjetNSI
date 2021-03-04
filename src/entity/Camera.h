#pragma once
/**
 * \file Camera.h
 * \author Marc MOUTARDE
 * \brief fichier d'entête de la camera
 */ 
#include <math/Vector3f.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/**
 * \brief callback GLFW
 */ 
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

/**
 * \brief fonction de mise a jour de la caméra
 */ 
void updateCamera();

/**
 * \brief fonction permetant de récupérer la position de la camera
 * \return position de la caméra dans le monde 3D suivant les coordonnées OpenGL
 */ 
Vector3f getCameraPosition();
