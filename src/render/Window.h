#pragma once
/**
 * \file Window.h
 * \author Marc MOUTARDE
 * \brief encapsulation de la fenetre GLFW
 */ 

#include <stdbool.h>

/**
 * \brief activation du test de profondeur
 */ 
static void setGlStates();

/**
 * \brief mise en place des callbacks glfw
 */ 
static void setGlfwCallback();

/**
 * \brief initialisation de la fenetre
 * \param width la largeur de la fenetre
 * \param height la hauteur de la fenetre
 * \param name le nom à donner à la fenetre
 */ 
bool initWindow(int width, int height, const char* name);

/**
 * \brief nétoyage du tampon de couleur et du tampon de profondeur
 */ 
void clearDisplay();

/**
 * \brief mise a jour de la fenetre, émission des évenements, échange des tampons
 */ 
void updateWindow();

/**
 * \brief vérifi si la fenetre est ouverte
 * \return true si la fenetre est ouverte, false sinon
 */ 
bool isWindowOpen();

/**
 * \brief détruit la fenetre
 */ 
void terminateWindow();
