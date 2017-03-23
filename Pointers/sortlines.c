#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pointers.h"

int getline(char *s, int lim){
	int c;
	char *p = s;
	for( ;lim > 0 && (c = getchar()) != '\n'; lim--)
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';
	return s-p;
}

// nlines will be greater than the index that stored the last line but will equal number
// of lines read because of 0 index
// alloc changes p after every line is read, lineptr[] holds pointers to memory allocated
// by alloc, all the lines are in the buffer maintained by alloc not in line
// can't keep using line to store string in lineptr because then every pointer in lineptr
// would point to the same place.
int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getline(line, MAXLEN)) > 1)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len -1] = '\0';
			strcpyMine(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

// dereferencing lineptr will produce a pointer to the first character of a line.
// printf knows to print the subsequent elements
void writelines(char *lineptr[], int nlines){

	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void writelinesreverse(char *lineptr[], int nlines, int decr){
	int i;

	if(decr)
		for(i = nlines -1; i >= 0; i--)
			printf("%s\n", lineptr[i]);
	else
		writelines(lineptr, nlines);
}

/*
void qsort(char *v[], int left, int right){
	int i, last;

	swap(v, left, (left + right)/2);
	last = left;

	if(left >= right)
		return;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, last, left);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}
*/

void qsortMine(void *v[], int left, int right, int (*comp)(void *, void *)){
	int i, last;

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, last, left);
	qsortMine(v, left, last-1, comp);
	qsortMine(v, last+1, right, comp);
}

void swap(void *v[], int i, int j){
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int numcmp(char *s1, char *s2){
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}
