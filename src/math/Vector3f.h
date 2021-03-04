#pragma once
/**
 * \file Vector3f.h
 * \author Marc MOUTARDE
 * \brief implementation d'un vecteur 3
 */ 

typedef struct Vector3f {
    float x, y, z;
} Vector3f;

/**
 * \brief fonction d'ajout de deux vecteur
 * \param to le vecteur sur lequel ajouter
 * \param toAdd le vecteur à ajouter
 */ 
void addVector(Vector3f* to, Vector3f* toAdd);
/**
 * \brief fonction de soustraction de deux vecteur
 * \param to le vecteur sur lequel soustraire
 * \param toSub le vecteur à soustraire
 */ 
void subVector(Vector3f* to, Vector3f* toSub);

/**
 * \brief fonction de multiplication d'un vecteur par un scalaire
 * \param to le vecteur à multiplier
 * \param info la valeur par laquelle multiplier
 */ 
void mulVectorByScallaire(Vector3f* to, float* info);

/**
 * \brief fonction de division d'un vecteur par un scalaire
 * \param to le vecteur à diviser
 * \param info la valeur par laquelle diviser
 */ 
void divVectorByScallaire(Vector3f* to, float* info);

/**
 * \brief fonction retournant le cosinus de l'angle entre deux vecteur
 * \param one le premier vecteur
 * \param two le second vecteur
 * \return le cosinus de l'angle entre les deux
 */ 
float dotProduct(Vector3f* one, Vector3f* two);

/**
 * \brief fonction retournant un vecteur ortogonal aux deux vecteur passer en arg
 * \param one le premier vecteur
 * \param two le second vecteur
 * \return le vecteur ortogonal aux deux cités ci desssus.
 */ 
Vector3f crossProduct(Vector3f* one, Vector3f* two);
