/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define MAX_INPUT 16

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char input[MAX_INPUT][BUFFER_LEN];
    FILE * inputstream = NULL;
    const char s[3] = " \n";

    printf("Welcome to the shell! Type any command to get started\n");
    printdir();

    // If there is something else on the command line other than ./myshell
    if (argc > 1){
        //Open file stream
        inputstream = fopen(argv[1], "r");
        if (inputstream==NULL){
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }
    //Use stdin if no other command line inputs
    else{
        inputstream = stdin;
    }

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, inputstream) != NULL)
    {
        int i = 0;
        // Perform string tokenization and split them into an input array
        char *token = strtok(buffer, s);
        while (token != NULL) {
            sprintf (input[i], "%s", token);
            token = strtok(NULL, s);
            i++;
        }
        //Parse the command
        sprintf (command, "%s", input[0]);
        
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            cd(input[1]);
        }
        //clr command -- Clear screen
        else if (strcmp(command, "clr") == 0)
        {
            clr();
        }
        //dir command -- Display everyting under given directory
        else if (strcmp(command, "dir") == 0)
        {
            dir(input[1]);
        }
        //environ -- Display environment variables
        else if (strcmp(command, "environ") == 0)
        {
            environment();
        }
        //echo -- Print given message
        else if (strcmp(command, "echo") == 0)
        {
            for (int w=1; w < i; w++){
                printf("%s ", input[w]);
            }
            printf("\n");
        }
        //help -- Displays help menu
        else if (strcmp(command, "help") == 0)
        {
            help();
        }
        //pause -- Pauses until enter button is hit
        else if (strcmp(command, "pause") == 0)
        {
            stop();
        }
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }
        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
        printdir();
    }
    return EXIT_SUCCESS;
}
