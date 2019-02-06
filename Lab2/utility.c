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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file
void cd(char* directory){

}

void clr(void){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

void printdir(void){
    //broken
    char currentpath[256];
    getcwd(currentpath, sizeof(currentpath));
    printf("%s", currentpath);
}

void dir(void){

}

void echo(char* sentence){

}

void environ(void){

}

void help(void){

}

void stop(void){

}

void quit(void){

}