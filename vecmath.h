/**********************************************************
* @file vecmath.h
* @brief 3D Vector math operations header
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/05/25
* Compile: gcc -o veclab veclab.c vecmath.c
***********************************************************/
#ifndef VECMATH_H
#define VECMATH_H

vector add_vector(const vector* a, const vector* b);
vector sub_vector(const vector* a, const vector* b);
vector mult_vector(const vector* a, double scalar);
double dot_vector(const vector* a, const vector* b);
vector cross_vector(const vector* a, const vector* b);
vector new_vector(const char* name, double x, double y, double z);
void print_vector(const vector* v);
void clear_vectors();

#endif // VECMATH_H