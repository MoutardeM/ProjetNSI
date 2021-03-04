#pragma once
/**
 * \file Matrix4f.h
 * \author Marc MOUTARDE
 * \brief implementation d'une matrice carrée d'ordre 4
 */ 

#include <math/Vector3f.h>

typedef struct Matrix4f {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
} Matrix4f;

/**
 * \brief retourne une matrice d'ientité d'ordre 4 
 * \return une matrice d'identité
 */ 
Matrix4f getIdentityMatrix();

/**
 * \brief fonction d'ajout de matrices
 * \param to la matrice où ajouter l'autre matrice
 * \param add la matrice à ajouter à to
 */ 
void addMatrix(Matrix4f* to, Matrix4f* add);

/**
 * \brief fonction de soustraction de matrices
 * \param to la matrice où soustraire l'autre matrice
 * \param add la matrice à soustraire à to
 */ 
void subMatrix(Matrix4f* to, Matrix4f* sub);

/**
 * \brief fonction de multiplication de matrices
 * \param to la matrice ou stoquer le résultat de la multiplication de to par mull
 * \param mull la matrice par laquelle multiplier to
 */ 
void mulMatrix(Matrix4f* to, Matrix4f* mull);

/**
 * \brief translate la matrice to par le vecteur from
 * \param to la matrice à translater
 * \param from le vecteur indiquant comment la translater
 */ 
void translate(Matrix4f* to, Vector3f* from);

/**
 * \brief effectue une rotation de la matrice to de l'angle angle suivant l'axe (x, y, z)
 * \param to la matrice à transformer
 * \param angle l'angle dont faire tourner la matrice
 * \param x l'axe de rotation suivant x
 * \param y l'axe de rotation suivant y
 * \param z l'axe de rotation suivant z
 * TODO
 */ 
void rotate(Matrix4f* to, float angle, float x, float y, float z);

/**
 * \brief retourne une matrice de projection
 * \param fov l'angle de vue
 * \param aspect le ration longeur sur largeur de la fenetre
 * \param near le plan le plus proche visible
 * \param far le plan le plus loin visible
 * \return une matrice de projection
 */ 
Matrix4f genProjectionMatrix(float fov, float aspect, float near, float far);
