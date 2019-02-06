/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// Include your relevant functions declarations here they must start with the
// extern keyword such as in the following example:
// extern void display_help(void);
extern void cd(char*);

extern void clr(void);

extern void dir(void);

extern void echo(char*);

extern void environ(void);

extern void help(void);

extern void stop(void);

extern void quit(void);

extern void printdir(void);

#endif /* UTILITY_H_ */