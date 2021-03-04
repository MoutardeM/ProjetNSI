#pragma once
/**
 * \file World.h
 * \author Marc MOUTARDE
 * \brief Implementation du monde
 */ 

//!\brief le nombre de tronçons ç projeter dans la vue de l'utilisateur
#define RENDER_DISTANCE 2

//!\brief initialisation du monde
void initWorld();

//!\brief déchargement des tronçons inutiles, chargement des nouveaux
void updateWorld();
//!\brief rendu de l'ensemble des tronçons chargés
void renderWorld();
//!\brief destruction de l'ensemble des tronçons chargés
void deleteWorld();
