/*
 * pointers.h
 *
 *  Created on: May 15, 2014
 *      Author: Liam
 */

#ifndef POINTERS_H_
#define POINTERS_H_
#define MAXLINES 5000
#define MAXLEN 1000
#define NUM 1
#define DECR 2

char *alloc(int);
void afree(char*);
int strlenMine(char*);
void strcpyMine(char*, char*);
int strcmpMine(char*, char*);
void strcatMine(char*, char*);
int strend(char*, char*);
int getline(char*, int);
int readlines(char* [], int);
void writelines(char* [], int);
void writelinesreverse(char* [], int, int);
void qsortMine(void* [], int, int, int (*)(void*, void*));
void swap(void* [], int, int);
int numcmp(char*, char*);


#endif /* POINTERS_H_ */
