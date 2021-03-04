#include <render/OpenGL.h>

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

static float* matrix = NULL;

bool compileShader(unsigned int id, const char* file)
{
    FILE* shaderFile = fopen(file, "r");
    if(shaderFile == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier: %s\n", shaderFile);
    }

    fseek(shaderFile, 0, SEEK_END);
    unsigned long shaderSize = ftell(shaderFile);
    rewind(shaderFile);

    char* source = malloc(shaderSize);
    for(unsigned long it=0; it < shaderSize; it++)
    {
        source[it] = fgetc(shaderFile);
    }

    glShaderSource(id, 1, &source, 0);  // ne pas tenir compte de l'avertissement
    glCompileShader(id);

    free(source);
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char* log = malloc(512);
        glGetShaderInfoLog(id, 512, NULL, log);
        fprintf(stderr, "Erreur compilation shader:\n%s\n", log);
        free(log);
        return false;
    }

    return true;
}

bool loadShader(Shader* shader, const char* vertexFile, const char* fragmentFile)
{
    shader->vertexID = glCreateShader(GL_VERTEX_SHADER);
    shader->fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    shader->programID = glCreateProgram();

    if(!compileShader(shader->vertexID, vertexFile) || !compileShader(shader->fragmentID, fragmentFile))
    {
        return false;
    }

    glAttachShader(shader->programID, shader->vertexID);
    glAttachShader(shader->programID, shader->fragmentID);

    glLinkProgram(shader->programID);

    matrix = malloc(16*sizeof(float));
    return true;    
}

void useShader(Shader* shader)
{
    glUseProgram(shader->programID);
}

unsigned int getUniformLocation(Shader* shader, const char* name)
{
    return glGetUniformLocation(shader->programID, name);
}

void loadUniformMatrix4f(unsigned int location, Matrix4f* mat)
{
    matrix[0] = mat->m00;
    matrix[1] = mat->m10;
    matrix[2] = mat->m20;
    matrix[3] = mat->m30;

    matrix[4] = mat->m01;
    matrix[5] = mat->m11;
    matrix[6] = mat->m21;
    matrix[7] = mat->m31;

    matrix[8]  = mat->m02;
    matrix[9]  = mat->m12;
    matrix[10] = mat->m22;
    matrix[11] = mat->m32;

    matrix[12] = mat->m03;
    matrix[13] = mat->m13;
    matrix[14] = mat->m23;
    matrix[15] = mat->m33;
    glUniformMatrix4fv(location, 1, GL_FALSE, matrix);
}

void loadUniformVector3f(unsigned int location, Vector3f* vec)
{
    glUniform3f(location, vec->x, vec->y, vec->z);
}

void deleteShader(Shader* shader)
{
    glDeleteShader(shader->vertexID);
    glDeleteShader(shader->fragmentID);
    glDeleteProgram(shader->programID);
    
    free(matrix);
}
