#pragma once
/**
 * \file OpenGL.h
 * \author Marc MOUTARDE
 * \brief fichier renferment l'ensemble des fonction pour simplier les appels OpenGL
 */ 

#include <stdbool.h>

#include <math/Matrix4f.h>
#include <math/Vector3f.h>

/**
 * \brief représentation sous forme de structure d'un shader opengl
 */ 
typedef struct Shader {
    //!\brief Identifiant du vertex shader
    unsigned int vertexID;
    //!\brief Identifiant du fragment shader (ou pixel shader)
    unsigned int fragmentID;
    //!\brief Identifiant du program shader (càd l'executable)
    unsigned int programID;
} Shader;

/**
 * \brief représentation sous forme de structure d'un model OpenGL
 */ 
typedef struct Model {
    //!\brief nombre de sommets du model
    unsigned int vertexCount;
    //!\brief identifiant de l'Element Buffer Object
    unsigned int ebo;
    //!\brief identifiant du Vertex Array Object
    unsigned int vao;
    //!\brief identifiant du Vertex Buffer Object contenant les somments
    unsigned int vertexVbo;
    //!\brief identifiant du Vertex Buffer Object contenant les normals
    unsigned int normalVbo;
} Model;

//!\brief structure permetant de réduire le nombre d'argument de la fonction de chargment de model
typedef struct LoadableData {
    //!\brief nombre de sommet dans le model multiplié par la taille d'un float
    unsigned int vertexCount;
    //!\brief nombre de normal dans le model multiplié par la taille d'un float
    unsigned int normalCount;
    //!\brief nombre d'index dans le model multiplié par la taille d'un int non signé
    unsigned int indexCount;

    //!\brief pointeur sur le tableau de sommets
    float* vertex;
    //!\brief pointeur sur le tableau de normals
    float* normal;
    //!\brief pointeur sur le tableau d'index
    unsigned int* index;
} LoadableData;

#define NO_GL_OBJECT 0

// definition des fonctions dans VaoManagement.c

/**
 * \brief Charge un model dans la mémoire graphique de l'ordinateur
 * \param data les données à charger en mémoire
 * \return structure représentant un model
 */ 
Model loadToVao(LoadableData* data);

/**
 * \brief fait un rendu du model passer en argument
 * \param model le model à render
 */ 
void renderModel(Model* model);

/**
 * \brief detruit le model passer en argument pour éviter de le laisser dans la mémoire graphique
 * \param model le model à détruire
 */ 
void deleteModel(Model* model);

// definition des fonction dans ShaderManagement.c

/**
 * \brief fonction de compilation d'un shader
 * \param id l'identifiant du shader à compiler
 * \param file le fichier contenant le shader à compiler
 */ 
static bool compileShader(unsigned int id, const char* file);

/**
 * \brief charge le shader passer en argument à l'aide des deux fichiers passer en argument
 * \param shader le shader à charger en mémoire
 * \param vertexFile le fichier contenant les sources du vertex shader
 * \param fragmentFile le fichier contenant les source du fragment shader
 * \return true si la compilation s'est bien passée false sinon
 */ 
bool loadShader(Shader* shader, const char* vertexFile, const char* fragmentFile);

/**
 * \brief active le shader passer en argument
 * \param shader le shader à activer
 */ 
void useShader(Shader* shader);

/**
 * \brief recupère l'emplacement de la variable uniforme demandée
 * \param shader le shader a qui demander l'emplacement
 * \param name le nom de la variable à demander
 * \return l'adresse de la variable uniforme
 */ 
unsigned int getUniformLocation(Shader* shader, const char* name);

/**
 * \brief charge un matrice carrée d'ordre 4
 * \param location la variable uniforme ou stoquer la matrice
 * \param mat la matrice à charger en mémoire
 */ 
void loadUniformMatrix4f(unsigned int location, Matrix4f* mat);

/**
 * \brief charge un vecteur à 3 composantes
 * \param location la variable uniforme ou stoquer le vecteur
 * \param vec le vecteur à charger en mémoire
 */ 
void loadUniformVector3f(unsigned int location, Vector3f* vec);

/**
 * \brief détruit le shader passer en argument
 * \param shader le shader à détruire
 */ 
void deleteShader(Shader* shader);
