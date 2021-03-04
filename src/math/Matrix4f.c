#include <math/Matrix4f.h>

#include <math.h>

#define PI 3.14159265359

Matrix4f getIdentityMatrix()
{
    Matrix4f mat;

    mat.m00 = mat.m11 = mat.m22 = mat.m33 = 1.f;
    mat.m01 = mat.m02 = mat.m03 = mat.m10 = 0.f;
    mat.m12 = mat.m13 = mat.m20 = mat.m21 = 0.f;
    mat.m23 = mat.m30 = mat.m31 = mat.m32 = 0.f;

    return mat;
}

void addMatrix(Matrix4f* to, Matrix4f* add)
{
    to->m00 += add->m00;to->m01 += add->m01;to->m02 += add->m02;to->m03 += add->m03;
    to->m10 += add->m10;to->m11 += add->m11;to->m12 += add->m12;to->m13 += add->m13;
    to->m20 += add->m20;to->m21 += add->m21;to->m22 += add->m22;to->m23 += add->m23;
    to->m30 += add->m30;to->m31 += add->m31;to->m32 += add->m32;to->m33 += add->m33;
}

void subMatrix(Matrix4f* to, Matrix4f* sub)
{
    to->m00 -= sub->m00;to->m01 -= sub->m01;to->m02 -= sub->m02;to->m03 -= sub->m03;
    to->m10 -= sub->m10;to->m11 -= sub->m11;to->m12 -= sub->m12;to->m13 -= sub->m13;
    to->m20 -= sub->m20;to->m21 -= sub->m21;to->m22 -= sub->m22;to->m23 -= sub->m23;
    to->m30 -= sub->m30;to->m31 -= sub->m31;to->m32 -= sub->m32;to->m33 -= sub->m33;
}

void mulMatrix(Matrix4f* to, Matrix4f* mull)
{
    Matrix4f mat = getIdentityMatrix();
    mat = *to;

    to->m00 = mat.m00*mull->m00 + mat.m01*mull->m10 + mat.m02*mull->m20 + mat.m03*mull->m30;
    to->m01 = mat.m00*mull->m01 + mat.m01*mull->m11 + mat.m02*mull->m21 + mat.m03*mull->m31;
    to->m02 = mat.m00*mull->m02 + mat.m01*mull->m12 + mat.m02*mull->m22 + mat.m03*mull->m32;
    to->m03 = mat.m00*mull->m03 + mat.m01*mull->m13 + mat.m02*mull->m23 + mat.m03*mull->m33;

    to->m10 = mat.m10*mull->m00 + mat.m11*mull->m10 + mat.m12*mull->m20 + mat.m13*mull->m30;
    to->m11 = mat.m10*mull->m01 + mat.m11*mull->m11 + mat.m12*mull->m21 + mat.m13*mull->m31;
    to->m12 = mat.m10*mull->m02 + mat.m11*mull->m12 + mat.m12*mull->m22 + mat.m13*mull->m32;
    to->m13 = mat.m10*mull->m03 + mat.m11*mull->m13 + mat.m12*mull->m23 + mat.m13*mull->m33;

    to->m20 = mat.m20*mull->m00 + mat.m21*mull->m10 + mat.m22*mull->m20 + mat.m23*mull->m30;
    to->m21 = mat.m20*mull->m01 + mat.m21*mull->m11 + mat.m22*mull->m21 + mat.m23*mull->m31;
    to->m22 = mat.m20*mull->m02 + mat.m21*mull->m12 + mat.m22*mull->m22 + mat.m23*mull->m32;
    to->m23 = mat.m20*mull->m03 + mat.m21*mull->m13 + mat.m22*mull->m23 + mat.m23*mull->m33;

    to->m30 = mat.m30*mull->m00 + mat.m31*mull->m10 + mat.m32*mull->m20 + mat.m33*mull->m30;
    to->m31 = mat.m30*mull->m01 + mat.m31*mull->m11 + mat.m32*mull->m21 + mat.m33*mull->m31;
    to->m32 = mat.m30*mull->m02 + mat.m31*mull->m12 + mat.m32*mull->m22 + mat.m33*mull->m32;
    to->m33 = mat.m30*mull->m03 + mat.m31*mull->m13 + mat.m32*mull->m23 + mat.m33*mull->m33;
}

void translate(Matrix4f* to, Vector3f* from)
{
    Matrix4f mat = getIdentityMatrix();
    mat.m30 = from->x;
    mat.m31 = from->y;
    mat.m32 = from->z;

    mulMatrix(to, &mat);
}

void rotate(Matrix4f* to, float angle, float x, float y, float z)
{

}

Matrix4f genProjectionMatrix(float fov, float aspect, float near, float far)
{
    Matrix4f mat = getIdentityMatrix();
    float tanFovOver2 = tan(((fov/2)*PI)/180);

    mat.m00 = 1.f/(aspect*tanFovOver2);
    mat.m11 = 1.f/tanFovOver2;
    mat.m22 = -(far+near)/(far-near);
    mat.m23 = -1.f;
    mat.m32 = -(2.f*far*near)/(far-near);
    mat.m33 = 0;
    return mat;
}
