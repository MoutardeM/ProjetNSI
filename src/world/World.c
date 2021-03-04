#include <world/World.h>

#include <stdlib.h>

#include <math/Vector3f.h>
#include <entity/Camera.h>
#include <world/Chunk.h>

static Chunk* chunks;
static const unsigned int visibleChunk = ((2*RENDER_DISTANCE)+1)*((RENDER_DISTANCE)+1);

void initWorld()
{
    chunks = malloc(sizeof(Chunk)*visibleChunk);
    unsigned int iteration = 0;
    Vector3f pos = getCameraPosition();
    int posX = pos.x / CHUNK_SIZE;
    int posY = pos.z / CHUNK_SIZE;
    for(int x= posX-RENDER_DISTANCE; x <= posX+(RENDER_DISTANCE); x++)
    {
        for(int y=posY-RENDER_DISTANCE; y <= posY; y++)
        {
            chunks[iteration++] = initChunk(x, y);
        }
    }
}

void updateWorld()
{
    Vector3f pos = getCameraPosition();
    int posX = -pos.x / CHUNK_SIZE;
    int posY = -pos.z / CHUNK_SIZE;

    unsigned int iteration = 0;
    for(int x= posX-RENDER_DISTANCE; x <= posX+(RENDER_DISTANCE); x++)
    {
        for(int y=posY-RENDER_DISTANCE; y <= posY; y++)
        {
            if(chunks[iteration].posX != x || chunks[iteration].posZ != y)
            {
                deleteChunk(&chunks[iteration]);
                chunks[iteration] = initChunk(x, y);
            }
            iteration++;
        }
    }
}

void renderWorld()
{
    for(unsigned int it=0; it < visibleChunk; it++)
    {
        renderModel(&chunks[it].model);
    }
}

void deleteWorld()
{
    for(unsigned int it=0; it < visibleChunk; it++)
    {
        deleteModel(&chunks[it].model);
    }
}
