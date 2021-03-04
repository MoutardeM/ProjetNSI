#include <world/Chunk.h>

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

static float getHeight(int x, int y, unsigned char* img)
{
    if(img == NULL || x < 0 || y < 0 || x == CHUNK_SIZE || y == CHUNK_SIZE)
    {
        return 0;
    }

    unsigned int height = 0x00000000;
    height |= img[(y*CHUNK_SIZE+x)*3  ] << 16;
    height |= img[(y*CHUNK_SIZE+x)*3+1] << 8;
    height |= img[(y*CHUNK_SIZE+x)*3+2] << 0;
    return ((float)height/(float)0x00ffffff)*AMPLITUDE;
}

Chunk initChunk(int posX, int posY)
{
    Chunk chunk = {
        .posX = posX,
        .posZ = posY
    };
    float* vertex = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    float* normal = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    unsigned int* index = malloc((CHUNK_SIZE-1)*(CHUNK_SIZE-1)*6*sizeof(unsigned int));
    LoadableData info;
    info.index = index;     info.indexCount = (CHUNK_SIZE-1)*(CHUNK_SIZE-1)*6*sizeof(unsigned int);
    info.normal = normal;   info.normalCount = CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float);
    info.vertex = vertex;   info.vertexCount = CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float);

    char* imageName = malloc(strlen("res/height/carte_xxx_xxx.jpeg"));
    sprintf(imageName, "res/height/carte_%d_%d.jpeg", posX, -posY);
    int w, h, c;    // width, height, channel
    unsigned char* imageData = stbi_load(imageName, &w, &h, &c, 3);

    Vector3f normalVec;
    float norm;
    for(int x=0; x < CHUNK_SIZE; x++)
    {
        for(int y=0; y < CHUNK_SIZE; y++)
        {
            vertex[(x*CHUNK_SIZE+y)*3]   = (posX*(CHUNK_SIZE-1))+x;
            vertex[(x*CHUNK_SIZE+y)*3+1] = getHeight(x, y, imageData);
            vertex[(x*CHUNK_SIZE+y)*3+2] = (posY*(CHUNK_SIZE-1))+y;

            normalVec.x = getHeight(x-1, y, imageData) - getHeight(x+1, y, imageData);
            normalVec.y = 2;
            normalVec.z = getHeight(x, y-1, imageData) - getHeight(x, y+1, imageData);

            norm = sqrt(normalVec.x*normalVec.x + normalVec.y*normalVec.y + normalVec.z*normalVec.z);
            normalVec.x   /= norm;
            normalVec.y  /= norm;
            normalVec.z /= norm;

            normal[(x*CHUNK_SIZE+y)*3  ] = normalVec.x;
            normal[(x*CHUNK_SIZE+y)*3+1] = normalVec.y;
            normal[(x*CHUNK_SIZE+y)*3+2] = normalVec.z;
        }
    }

    stbi_image_free(imageData);
    unsigned int it=0;
    for(unsigned int x=0; x < (CHUNK_SIZE -1); x++)
    {
        for(unsigned int y=0; y < (CHUNK_SIZE-1); y++)
        {
            unsigned int topLeft = x*(CHUNK_SIZE)+y;
            unsigned int topRight = topLeft+1;
            unsigned int downLeft = topLeft+CHUNK_SIZE;
            unsigned int downRight = downLeft+1;

            index[it++] = topLeft;
            index[it++] = topRight;
            index[it++] = downRight;

            index[it++] = downRight;
            index[it++] = downLeft;
            index[it++] = topLeft;
        }
    }

    chunk.model = loadToVao(&info);
    free(vertex);
    free(normal);
    free(index);

    return chunk;
}

void deleteChunk(Chunk* chunk)
{
    deleteModel(&chunk->model);
}
