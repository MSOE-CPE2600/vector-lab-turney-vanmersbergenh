/**********************************************************
* @file veclab.c
* @brief 3D Vector operations
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/05/25
* Compile: gcc -o veclab veclab.c vecmath.c
***********************************************************/
#include "vector.h"
#include <stdio.h>
#include <string.h>
// use strtok()
int exit_program = 0;
char input[80] = {0};

double x, y, z;
char user_input1[50];
char user_input2[50];
char user_input3[50];
char user_input4[50];
char user_input5[50];
char *token
char *token2;
char *token3;
char *token4;
char *token5;

int main(void) 
{
    //clear_vectors();
    while (exit_program == 0)
    {
        fgets(input, 80, stdin);
        token1 = strtok(input, " ");
        token2 = strtok(NULL, " ");
        token3 = strtok(NULL, " ");
        token4 = strtok(NULL, " ");
        token5 = strtok(NULL, " ");
        printf("%s, %s, %s, %s, %s\n", token1, token2, token3, token4, token5);

        if (strcmp(token1, "list") == 0)
        {
            //list_vectors();
        }
        else if (strcmp(token1, "quit") == 0 || strcmp(token1, "exit") == 0)
        {
            exit_program = 1;
            printf("Exiting program.\n");
        }
        // else if (strcmp(input, "clear") == 0)
        // {
        //     clear_vectors();
        // }
        // else if (strcmp(input, "help") == 0 || strcmp(input, "") == 0)
        // {
        //     display_help();
        // }
        // else
        // {
        //     strtok(NULL, " ");
        //     if (strcmp(input, "+") == 0)
        //     {
        //         add_vector(name, input, strtok(NULL, " "), z);
        //     }
        //     else if (strcmp(input, "-") == 0)
        //     {
        //         sub_vector(name, name);
        //     }
        //     else if (strcmp(input, "*") == 0)
        //     {
        //         mult_vector(name, x);
        //     }
        //     else if (strcmp(input, ".") == 0)
        //     {
        //         dot_vector(name, x, y, z);
        //     }
        //     else if (strcmp(input, "x") == 0)
        //     {
        //         cross_vector(name, x, y, z);
        //     }
        //     else if (strcmp(input, "=") == 0)
        //     {
        //         new_vector(name, atof(strtok(NULL, " ")), atof(strtok(NULL, " ")), atof(strtok(NULL, " ")));
        //     }
        //     else
        //     {
        //         print_vector(name);
        //     }
        // }
    }

    return 0;
}