/**********************************************************
* @file vectarray.c
* @brief 3D Vector array operations
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/21/25
* Compile: make
***********************************************************/
#include "vectarray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

vector* vector_array;
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
* Allocates a space in memory for storing vectors
*/
void allocate()
{
    if (vector_count < 1)
    {
        vector_array = (vector*) malloc(sizeof(vector)*5);
    }
    else 
    {
        vector_array = (vector*) realloc(vector_array, sizeof(vector)*(vector_count+5));
    }
}

/**
* Clears the vectors stored in the list
*/
void clear_vectors()
{
    if (vector_count > 0)
    {
        free(vector_array);    
        printf("All vectors cleared.\n");
        vector_count = 0;
    }
    else
    {
        printf("No vectors to clear.\n");
    }
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
* @return 1 if the vector was added, 0 otherwise
*/
int new_vector(const char* name, double x, double y, double z, const char* name2)
{
    if (strlen(name) <= 0 || strlen(name) >= 10)
    {
        printf("Error: Invalid vector name length (must be < 10 characters).\n");
        return 0;
    }

    if (name2 != NULL)
    {
        if (find_vector(name2) != -1)
        {
            if (strcmp(name, name2) == 0)
            {
                // vectors are the same
                return 1;
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
                return 1;
            }
            if ((vector_count % 5) == 0)
            {
                allocate();
            }
            vector* copy = &vector_array[find_vector(name2)];
            vector_array[vector_count].x = copy->x;
            vector_array[vector_count].y = copy->y;
            vector_array[vector_count].z = copy->z;
            strcpy(vector_array[vector_count].name, name);
            vector_count++;
            printf("Vector '%s' created by copying from '%s': (%.2f, %.2f, %.2f)\n", 
                name, name2, copy->x, copy->y, copy->z);
            return 1;
        }
        else
        {
            printf("Error: Source vector '%s' not found for copying.\n", name2);
            return 0;
        }
    }

    if (find_vector(name) != -1)
    {
        vector* existing = &vector_array[find_vector(name)];
        existing->x = x;
        existing->y = y;
        existing->z = z;
        printf("Vector '%s' updated: (%.2f, %.2f, %.2f)\n", name, x, y, z);
        return 1;
    }
    if ((vector_count % 5) == 0)
    {
        allocate();
    }
    vector_array[vector_count].x = x;
    vector_array[vector_count].y = y;
    vector_array[vector_count].z = z;
    strcpy(vector_array[vector_count].name, name);
    vector_count++;

    printf("Vector '%s' created: (%.2f, %.2f, %.2f)\n", name, x, y, z);
    return 1;
}

/**
* Loads vectors from a csv file
* @param filename the name of the file
*/
void load(char* filename)
{
    printf("loading from file...\n");
    char name[10];
    float x;
    float y;
    float z;
    int count = 0;
    int errors = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s", filename);
        return;
    }
    while (fscanf(file, "%9[^,],%f,%f,%f ", name, &x, &y, &z) == 4)
    {
        if (new_vector(name, x, y, z, NULL)) 
        {
            count++;
        }
        else
        {
            errors++;
        }
    }
    printf("Loaded %d vectors successfully from %s.\n", count, filename);
    if (errors > 0)
    {
        printf("%d vectors not added due to errors\n", errors);
    }
    fclose(file);
    return;
}

/**
* Save the current vectors to a csv file
* @param filename the name of the file
*/
void save(char* filename)
{
    FILE *file = fopen(filename, "w");
    int count;
    for (int i = 0; i < vector_count; i++)
    {
        fprintf(file, "%s,%f,%f,%f\n", vector_array[i].name,
            vector_array[i].x, vector_array[i].y, vector_array[i].z);
        count++;
    }
    fclose(file);
    printf("Successfully saved %d vectors to %s.\n", count, filename);
    return;
}