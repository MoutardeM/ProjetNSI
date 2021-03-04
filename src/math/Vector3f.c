#include <math/Vector3f.h>

void addVector(Vector3f* to, Vector3f* toAdd)
{
    to->x += toAdd->x;
    to->y += toAdd->y;
    to->z += toAdd->z;
}

void subVector(Vector3f* to, Vector3f* toSub)
{
    to->x -= toSub->x;
    to->y -= toSub->y;
    to->z -= toSub->z;
}

void mulVectorByScallaire(Vector3f* to, float* info)
{
    to->x *= *info;
    to->y *= *info;
    to->z *= *info;
}

void divVectorByScallaire(Vector3f* to, float* info)
{
    to->x /= *info;
    to->y /= *info;
    to->z /= *info;
}

float dotProduct(Vector3f* one, Vector3f* two)
{
    return (one->x*two->x)+(one->y*two->y)+(one->z*two->z);
}

Vector3f crossProduct(Vector3f* one, Vector3f* two)
{
    Vector3f vec;
    vec.x = one->y*two->z - one->z*two->y;
    vec.y = one->z*two->x - one->x*two->z;
    vec.z = one->x*two->y - one->y*two->x;

    return vec;
}
