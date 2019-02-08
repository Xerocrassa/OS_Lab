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

#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

extern char **environ;

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file
void cd(char* directory){
    int changestatus = chdir(directory);
    if(strcmp(directory, "")==0){
        char currentpath[256];
        getcwd(currentpath, sizeof(currentpath));
        printf("You didnt enter a path. Your current path is: %s\n", currentpath);
    }
    else if (changestatus == 0){
        printf("Path changed to ");
        printdir();
        printf("\n");
    }
    else
    {
        printf("Unable to change directory due to error. The path has not been changed.\n");
    }

}

void clr(void){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

void printdir(void){
    char currentpath[256];
    getcwd(currentpath, sizeof(currentpath));
    printf(BLUE "%s: " RESET, currentpath);
}

void dir(char* directory){
    DIR *dir = NULL;
    struct dirent *dp;
    if ((dir=opendir(directory))==NULL){
        printf("Error, Cannot open directory");
    }
    while((dp=readdir(dir))!=NULL){
        printf("%s\n", dp->d_name);
    }
}


void environment(void){
    int i=0;
    while(environ[i]){
        printf("%s\n", environ[i]);
        i++;
    }
}

void help(void){
    printf("Welcome to the help menu. Here are the functions you can use:\n");
    printf("cd <path>. Changes the directory you are in.\n");
    printf("clr. Clears the screen\n");
    printf("dir <path>. Lists the contents of the given path\n");
    printf("environ. Lists the environment variables\n");
    printf("echo <sentence>. Prints the sentence to the comman line\n");
    printf("help. Lists this menu\n");
    printf("pause. Pauses the program until the enter key is hit\n");
    printf("quit. Quits the shell\n");
}

void stop(void){
    printf("Program paused. Hit Enter to resume.");
    getchar();
}