#pragma once
/**
 * \file Chunk.h
 * \author Marc MOUTARDE
 * \brief implementation des tronçons
 */ 

#include <render/OpenGL.h>

//!\brief coté d'un tronçon
#define CHUNK_SIZE 64
//!\brief plage de hauteur d'un tronçon
#define AMPLITUDE 20.f

//!\brief structure représentant un tronçon
typedef struct Chunk
{
    //!\brief la position x dans la carte des tronçons
    int posX;
    //!\brief la position z dans la carte des tronçons
    int posZ;

    //!\brief le model du tronçon
    Model model;
} Chunk;

/**
 * \brief initialisation d'un tronçon
 * \param posX la position en X du tronçon dans la carte
 * \param posY la position en Z du tronçon dans la carte
 * \return le tronçon generé
 */ 
Chunk initChunk(int posX, int posY);

/**
 * \brief destruction d'un tronçon
 * \param chunk le tronçon à détruire
 */ 
void deleteChunk(Chunk* chunk);
