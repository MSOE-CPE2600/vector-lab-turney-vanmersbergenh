/**********************************************************
* @file vectarray.h
* @brief 3D Vector array operations header
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/09/25
***********************************************************/
#ifndef VECTARRAY_H
#define VECTARRAY_H

typedef struct
{
    char name[10];
    double x;
    double y;
    double z;
} vector;

vector* get_vector(int index);
void clear_vectors();
void list_vectors();
void print_vector(const char* name);
int find_vector(const char* name);
void new_vector(const char* name, double x, double y, double z, const char* name2);

#endif