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

extern char **environ;

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file
void cd(char* directory){
    int changestatus = chdir(directory);
    if (changestatus == 0){
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
    printf("%s ", currentpath);
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

}

void stop(void){

}