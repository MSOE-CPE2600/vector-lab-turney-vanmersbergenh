/**********************************************************
* @file vecmath.c
* @brief 3D Vector math operations
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/14/25
* Compile: gcc -o veclab veclab.c vecmath.c
***********************************************************/
#include "vectarray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Returns a non 0 number if the token is a number or '.' or '-', 0 otherwise
* @param token the token to check
* @return a non 0 number if the token is a number, 0 otherwise
*/
int is_number(const char* token)
{
    return ((*token >= '0' && *token <= '9') || *token == '.' || *token == '-');
}

/**
* Adds 2 vectors together
* @param name name of the first vector
* @param name2 name of the second vector
* @param stored 1 if the result should be stored in the first vector, 0 otherwise
*/
void add_vector(const char* name, const char* name2, int stored)
{
    vector* a = get_vector(find_vector(name));
    vector* b = get_vector(find_vector(name2));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    if (b == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name2);
        return;
    }
    vector result;
    result.x = a->x + b->x;
    result.y = a->y + b->y;
    result.z = a->z + b->z;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}

/**
* Subtracts a vector from another vector
* @param name name of the first vector
* @param name2 name of the second vector
* @param stored 1 if the result should be stored in the first vector, 0 otherwise
*/
void sub_vector(const char* name, const char* name2, int stored)
{
    vector* a = get_vector(find_vector(name));
    vector* b = get_vector(find_vector(name2));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    if (b == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name2);
        return;
    }
    vector result;
    result.x = a->x - b->x;
    result.y = a->y - b->y;
    result.z = a->z - b->z;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}

/**
* Multiplies a vector by a scalor
* @param name name of the vector
* @param scalar the scalar
* @param stored 1 if the result should be stored in the vector, 0 otherwise
*/
void mult_vector(const char* name, double scalar, int stored)
{
    vector* a = get_vector(find_vector(name));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    vector result;
    result.x = a->x * scalar;
    result.y = a->y * scalar;
    result.z = a->z * scalar;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}

/**
* Prints the dot product of 2 vectors
* @param name name of the first vector
* @param name2 name of the second vector
*/
void dot_vector(const char* name, const char* name2)
{
    vector* a = get_vector(find_vector(name));
    vector* b = get_vector(find_vector(name2));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    if (b == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name2);
        return;
    }
    float result = a->x * b->x + a->y * b->y + a->z * b->z;
    printf("Result: %.2f\n", result);
}

/**
* Prints the cross product of 2 vectors
* @param name name of the first vector
* @param name2 name of the second vector
* @param stored 1 if the result should be stored in the first vector, 0 otherwise
*/
void cross_vector(const char* name, const char* name2, int stored)
{
    vector* a = get_vector(find_vector(name));
    vector* b = get_vector(find_vector(name2));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    if (b == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name2);
        return;
    }
    vector result;
    result.x = a->y * b->z - a->z * b->y;
    result.y = a->z * b->x - a->x * b->z;
    result.z = a->x * b->y - a->y * b->x;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}

/**
* Adds a scalar to a vector
* @param name name of the vector
* @param scalar the scalar
* @param stored 1 if the result should be stored in the vector, 0 otherwise
*/
void add_scalar(const char* name, float scalar, int stored)
{
    vector* a = get_vector(find_vector(name));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    vector result;
    result.x = a->x + scalar;
    result.y = a->y + scalar;
    result.z = a->z + scalar;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}

/**
* Subtracts a scalar from a vector
* @param name name of the vector
* @param scalar the scalar
* @param stored 1 if the result should be stored in the vector, 0 otherwise
*/
void sub_scalar(const char* name, float scalar, int stored)
{
    vector* a = get_vector(find_vector(name));
    if (a == NULL) 
    {
        printf("Error: Vector '%s' not found.\n", name);
        return;
    }
    vector result;
    result.x = a->x - scalar;
    result.y = a->y - scalar;
    result.z = a->z - scalar;
    if (stored > 0) 
    {
        new_vector(name, result.x, result.y, result.z, NULL);
    }
    else 
    {
        printf("Result: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    }
}