/**********************************************************
* @file vecmath.h
* @brief 3D Vector math operations header
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/09/25
***********************************************************/
#ifndef VECMATH_H
#define VECMATH_H

int is_number(const char* token);
void add_vector(const char* name, const char* name2, int stored);
void sub_vector(const char* name, const char* name2, int stored);
void mult_vector(const char* name, double scalar, int stored);
void dot_vector(const char* name, const char* name2);
void cross_vector(const char* name, const char* name2, int stored);
void add_scalar(const char* name, float scalar, int stored);
void sub_scalar(const char* name, float scalar, int stored);

#endif