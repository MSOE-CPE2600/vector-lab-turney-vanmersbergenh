/**********************************************************
* @file vecmath.c
* @brief 3D Vector math operations
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/05/25
* Compile: gcc -o veclab veclab.c vecmath.c
***********************************************************/
#include "vector.h"
#include <stdio.h>

vector add_vector(const vector* a, const vector* b)
{
    vector result;
    snprintf(result.name, sizeof(result.name), "%s+%s",a.name, b.name);
    result.x =a.x + b.x;
    result.y =a.y + b.y;
    result.z =a.z + b.z;
    return result;
}

vector sub_vector(const vector* a, const vector* b)
{
    vector result;
    snprintf(result.name, sizeof(result.name), "%s-%s",a.name, b.name);
    result.x =a.x - b.x;
    result.y =a.y - b.y;
    result.z =a.z - b.z;
    return result;
}

vector mult_vector(const vector* a, double scalar)
{
    vector result;
    snprintf(result.name, sizeof(result.name), "%.2f*%s",scalar, a.name);
    result.x =a.x * scalar;
    result.y =a.y * scalar;
    result.z =a.z * scalar;
    return result;
}

double dot_vector(const vector* a, const vector* b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector cross_vector(const vector* a, const vector* b)
{
    vector result;
    snprintf(result.name, sizeof(result.name), "%s x %s",a.name, b.name);
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

vector new_vector(const char* name, double x, double y, double z)
{
    vector v;
    snprintf(v.name, sizeof(v.name), "%s", name);
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void print_vector(const vector* v)
{
    printf("%s: (%.2f, %.2f, %.2f)\n", v->name, v->x, v->y, v->z);
}
