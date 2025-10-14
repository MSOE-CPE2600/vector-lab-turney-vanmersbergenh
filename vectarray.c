/**********************************************************
* @file vectarray.c
* @brief 3D Vector array operations
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/09/25
* Compile: make
***********************************************************/
#include "vectarray.h"
#include <stdio.h>
#include <string.h>

#define MAX_VECTORS 10

vector vector_array[10];
int vector_count = 0;

/**
* Returns the vector stored at the index
* @param index the desired index
* @return the vector
*/
vector* get_vector(int index)
{
    if (index >= 0 && index < vector_count)
    {
        return &vector_array[index];
    }
    return NULL;
}

/**
* Clears the vectors stored in the list
*/
void clear_vectors()
{
    vector_count = 0;
    for (int i = 0; i < MAX_VECTORS; i++)
    {
        vector_array[i] = (vector){"", 0, 0, 0};
    }
    printf("All vectors cleared.\n");
}

/**
* Lists the currently stored vectors
*/
void list_vectors()
{
    if (vector_count == 0)
    {
        printf("No vectors stored.\n");
        return;
    }
    for (int i = 0; i < vector_count; i++)
    {
        printf("%s: (%.2f, %.2f, %.2f)\n", vector_array[i].name,
            vector_array[i].x, vector_array[i].y, vector_array[i].z);
    }
}

/**
* Prints the provided vector
* @param name name of the vector
*/
void print_vector(const char* name)
{
    int index = find_vector(name);
    if (index != -1)
    {
        printf("%s: (%.2f, %.2f, %.2f)\n", vector_array[index].name, 
            vector_array[index].x, vector_array[index].y, vector_array[index].z);
        return;
    }
    printf("Vector '%s' not found.\n", name);
}

/**
* Finds a vector by its name and returns the index
* @param name name of the vector
* @return index of the vector, -1 if not found
*/
int find_vector(const char* name)
{
    for (int i = 0; i < vector_count; i++)
    {
        if (strcmp(vector_array[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
* Creates or copies a vector
* @param name name of the vector
* @param x x value of the vector
* @param y y value of the vector
* @param z z value of the vector
* @param name2 name of the vector to copy, NULL if unused
*/
void new_vector(const char* name, double x, double y, double z, const char* name2)
{
    if (vector_count >= MAX_VECTORS)
    {
        printf("Error: Vector array full.\n");
        return;
    }

    if (strlen(name) <= 0 || strlen(name) >= 10)
    {
        printf("Error: Invalid vector name length (must be < 10 characters).\n");
        return;
    }

    if (name2 != NULL)
    {
        if (find_vector(name2) != -1)
        {
            if (strcmp(name, name2) == 0)
            {
                // vectors are the same
                return;
            }

            if (find_vector(name) != -1)
            {
                vector* existing = &vector_array[find_vector(name)];
                vector* copy = &vector_array[find_vector(name2)];
                existing->x = copy->x;
                existing->y = copy->y;
                existing->z = copy->z;
                printf("Vector '%s' updated by copying from '%s': (%.2f, %.2f, %.2f)\n",
                    name, name2, existing->x, existing->y, existing->z);
                return;
            }
            vector* copy = &vector_array[find_vector(name2)];
            vector_array[vector_count].x = copy->x;
            vector_array[vector_count].y = copy->y;
            vector_array[vector_count].z = copy->z;
            strcpy(vector_array[vector_count].name, name);
            vector_count++;
            printf("Vector '%s' created by copying from '%s': (%.2f, %.2f, %.2f)\n", 
                name, name2, copy->x, copy->y, copy->z);
            return;
        }
        else
        {
            printf("Error: Source vector '%s' not found for copying.\n", name2);
            return;
        }
    }

    if (find_vector(name) != -1)
    {
        vector* existing = &vector_array[find_vector(name)];
        existing->x = x;
        existing->y = y;
        existing->z = z;
        printf("Vector '%s' updated: (%.2f, %.2f, %.2f)\n", name, x, y, z);
        return;
    }

    vector_array[vector_count].x = x;
    vector_array[vector_count].y = y;
    vector_array[vector_count].z = z;
    strcpy(vector_array[vector_count].name, name);
    vector_count++;

    printf("Vector '%s' created: (%.2f, %.2f, %.2f)\n", name, x, y, z);
}



