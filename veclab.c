/**********************************************************
* @file veclab.c
* @brief 3D Vector operations with file saving and loading
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 10/14/25
* Compile: make
***********************************************************/
#include "vectarray.h"
#include "vecmath.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// use strtok()
int exit_program = 0;
char input[80] = {0};
char *token[5] = {NULL};

/**
* prints the commands list
*/
void print_help()
{
    printf("===Commands:\n");
    printf(">>  list                  - List all vectors\n");
    printf(">>  load <filename.csv>   - Load vectors from a csv file\n");
    printf(">>  <name> = x y z        - Create or change vector\n");
    printf(">>  <name> + <name>       - Add two vectors\n");
    printf(">>  <name> - <name>       - Subtract two vectors\n");
    printf(">>  <name> * scalar       - Multiply vector by scalar\n");
    printf(">>  <name> . <name>       - Dot product of two vectors\n");
    printf(">>  <name> x <name>       - Cross product of two vectors\n");
    printf(">>  <name> = <operation>  - Assignment after operation\n");
    printf(">>  clear                 - Clear all vectors\n");
    printf(">>  quit/exit             - Exit the program\n");
}

int main(int argc, char* argv[]) 
{
    if (argc > 1)
    {
        // check for -h flag
        if (strcmp(argv[1], "-h") == 0)
        {
            print_help();
        }
    }
    while (exit_program == 0)
    {
        token[0] = NULL;
        token[1] = NULL;
        token[2] = NULL;
        token[3] = NULL;
        token[4] = NULL;

        printf("input> ");
        fgets(input, 80, stdin);
        input[strcspn(input, "\n")] = 0;

        // tokenize the input
        token[0] = strtok(input, " ");
        for (int i = 1; i < 5; i++)
        {
            if (token[i - 1] != NULL)
            {
                token[i] = strtok(NULL, " ");
            }
            else
            {
                token[i] = NULL;
            }
        }

        if (token[0] != NULL)
        {
            if (strcmp(token[0], "list") == 0)
            {
                list_vectors();
            }
            else if (strcmp(token[0], "load") == 0)
            {
                if(token[1] != NULL)
                {
                    load(token[1]);
                }
                else
                {
                    printf("Error: Missing filename to load from. Example: load data.csv\n");
                }
            }
            else if (strcmp(token[0], "save") == 0)
            {
                if(token[1] != NULL)
                {
                    save(token[1]);
                }
                else
                {
                    printf("Error: Missing filename to save to. Example: save data.csv\n");
                }
            }
            else if (strcmp(token[0], "quit") == 0 || strcmp(token[0], "exit") == 0)
            {
                exit_program = 1;
                clear_vectors();
                printf("Exiting program.\n");
            }
            else if (strcmp(input, "clear") == 0)
            {
                clear_vectors();
            }
            else if (strcmp(input, "help") == 0 || strcmp(input, "") == 0)
            {
                print_help();
            }
            else if (is_number(token[0]))
            {
                if (token[1] != NULL && token[2] != NULL)
                {
                    if (strcmp(token[1], "=") == 0)
                    {
                        printf("Error: vector name cannot be a number\n");
                    }
                    else if (strcmp(token[1], "+") == 0)
                    {
                        if (is_number(token[2]))
                        {
                            printf("Result: %.2f\n", atof(token[0]) + atof(token[2]));
                        }
                        else 
                        {
                            printf("Error: cannot add a scalar by a vector\n");
                        }
                    }
                    else if (strcmp(token[1], "-") == 0)
                    {
                        if (is_number(token[2]))
                        {
                            printf("Result: %.2f\n", atof(token[0]) - atof(token[2]));
                        }
                        else
                        {
                            printf("Error: cannot add a scalar by a vector\n");
                        }
                    }
                    else if (strcmp(token[1], "*") == 0)
                    {
                        if (is_number(token[2]))
                        {
                            printf("Result: %.2f\n", atof(token[0]) * atof(token[2]));
                        }
                        else 
                        {
                            mult_vector(token[2], atof(token[0]), 0);
                        }
                    }
                } 
                else
                {
                    if (token[1] == NULL)
                    {
                        printf("Result: %.2f\n", atof(token[0]));
                    }
                    else
                    {
                        printf("Invalid command\n");
                    }
                }
            }
            else if (token[1] != NULL)
            {
                if (strcmp(token[1], "+") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: Invalid addition command. Usage: <name1> + <name2>\n");
                    }
                    else 
                    {
                        if (is_number(token[2]))    
                        {
                            add_scalar(token[0], atof(token[2]), 0);
                        }
                        else 
                        {
                            add_vector(token[0], token[2], 0);
                        }                    
                    }
                }
                else if (strcmp(token[1], "-") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: Invalid subtraction command. Usage: <name1> - <name2>\n");
                    }
                    else 
                    {
                        if (is_number(token[2]))
                        {
                            sub_scalar(token[0], atof(token[2]), 0);
                        }
                        else 
                        {
                            sub_vector(token[0], token[2], 0);
                        }
                    }
                }
                else if (strcmp(token[1], "*") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: missing second operand for multiplication\n");
                    }
                    else if (is_number(token[2]))
                    {
                        mult_vector(token[0], atof(token[2]), 0);
                    }
                    else
                    {
                        printf("Error: Must multiply vector by scalar only.\n");
                    }
                }
                else if (strcmp(token[1], ".") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: missing second operand for dot product\n");
                    }
                    else if (is_number(token[2]))
                    {
                        printf("Error: dot product must be between 2 vectors\n");
                    }
                    else
                    {
                        dot_vector(token[0], token[2]);
                    }
                }
                else if (strcmp(token[1], "x") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: missing second operand for cross product\n");
                    }
                    else if (is_number(token[2]))
                    {
                        printf("Error: cross product must be between 2 vectors\n");
                    }
                    else
                    {
                        cross_vector(token[0], token[2], 0);
                    }
                }
                else if (strcmp(token[1], "=") == 0)
                {
                    if (token[2] == NULL)
                    {
                        printf("Error: Invalid vector creation command. Usage: <name> = x y z\n");
                    } else {
                        if (token[3] == NULL)
                        {
                            if (is_number(token[2]))
                            {
                                new_vector(token[0], atof(token[2]), 0, 0, NULL);
                            }
                            else
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                            }
                        }
                        else if (strcmp(token[3], "*") == 0 && token[4] != NULL)
                        {
                            if (!is_number(token[2]) && (is_number(token[4])))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                mult_vector(token[0], atof(token[4]), 1);
                            }
                            else if (is_number(token[2]) && !is_number(token[4]))
                            {
                                new_vector(token[0], 0, 0, 0, token[4]);
                                mult_vector(token[0], atof(token[2]), 1);
                            }
                            else if (is_number(token[2]) && is_number(token[4]))
                            {
                                printf("Error: Cannot multiply two scalars to create a vector.\n");
                            }
                            else
                            {
                                printf("Error: Cannot multiply two vectors to create a vector.\n");
                            }
                        }
                        else if (strcmp(token[3], "-") == 0 && token[4] != NULL)
                        {
                            if (!is_number(token[2]) && !is_number(token[4]))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                sub_vector(token[0], token[4], 1);
                            }
                            else if (!is_number(token[2]) && is_number(token[4]))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                sub_scalar(token[0], atof(token[4]), 1);
                            }
                            else if ((is_number(token[2])) && (is_number(token[4])))
                            {
                                printf("Error: Cannot subtract two scalars to create a vector.\n");
                            }
                            else
                            {
                                printf("Error: Cannot subtract a scalar by a vector to create a vector.\n");
                            }
                        }
                        else if (strcmp(token[3], "+") == 0 && token[4] != NULL)
                        {
                            if (!is_number(token[2]) && !is_number(token[4]))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                add_vector(token[0], token[4], 1);
                            }
                            else if (!is_number(token[2]) && is_number(token[4]))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                add_scalar(token[0], atof(token[4]), 1);
                            }
                            else if ((is_number(token[2])) && (is_number(token[4])))
                            {
                                printf("Error: Cannot add two scalars to create a vector\n");
                            }
                            else
                            {
                                printf("Error: Cannot add a scalar by a vector to create a vector\n");
                            }
                        }
                        else if (strcmp(token[3], "x") == 0 && token[4] != NULL)
                        {
                            if (!is_number(token[2]) && (!is_number(token[4])))
                            {
                                new_vector(token[0], 0, 0, 0, token[2]);
                                cross_vector(token[0], token[4], 1);
                            }
                            else
                            {
                                printf("Error: cross product must include 2 vectors\n");
                            }
                        }
                        else 
                        {
                            if (token[4] != NULL)
                            {
                                if (is_number(token[2]) && is_number(token[3]) && is_number(token[4]))
                                {
                                    new_vector(token[0], atof(token[2]), atof(token[3]), atof(token[4]), NULL);
                                }
                                else
                                {
                                    printf("invalid command\n");
                                }
                            }
                            else
                            {
                                printf("invalid command\n");
                            }
                        }
                    }
                }
                else
                {
                    printf("invalid command\n");
                }
            }
            else
            {
                print_vector(token[0]);
            }
        }
    }
    return 0;
}