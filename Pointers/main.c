/*
unary operators associate right to left
pointers can be compared if they point to same array, the comparison is undefined for pointers
pointing to different arrays
the address of the first element past the end of an array can be used in pointer arithmetic
adding an integer to a pointer results in the integer being scaled to the size of the type
the pointer is pointing to

*/
#include "pointers.h"
#include <stdio.h>
#include <string.h>

/*functions have location in memory, they are not variables but a pointer can point to a function.
passing a function pointer to a function is like a design pattern of decoupling an algorithm so
that different ones can be substituted.  it is also kind of like overriding in object oriented
programming, it is not necessary in these languages because of polymorphism as long as the
class matches the interface expected by the algorithm that classes specific ordering method
can be used.*/
int main(int argc, char *argv[]){
	int nlines, option = 0, c;
	/*the characters in each line are placed somewhere, and a pointer to them is stored in
	the array.  the pointer stored points to the first character in the line but it also
	has knowledge of how many characters are in the line
	lineptr is a pointer that points to pointers.*/
	char *lineptr[MAXLINES];

	// increments to point to second argument and get first character
	while(--argc > 0 && (*++argv)[0] == '-')
		// gets first character of string specified above, increments past '-', dereferences
		while(c = *++argv[0])
			switch(c){
			case 'n':
				option |= NUM;
				break;
			case 'r':
				option |= DECR;
				break;
			default:
				printf("sort illegal option %c\n", c);
				argc = 1;
				break;
			}
	if(argc)
		printf("Usage: sort -nr \n");
	else
		if((nlines = readlines(lineptr, MAXLINES)) >= 0){
			if(option & NUM)
				qsortMine((void **)lineptr, 0, nlines -1,
					(int (*)(void *, void*))(numcmp));
			else
				qsortMine((void **)lineptr, 0, nlines -1,
					(int (*)(void *, void*))(strcmp));
			writelinesreverse(lineptr, nlines, option & DECR);
			return 0;
		}else{
			printf("error: too big to sort\n");
			return 1;
		}
	return 1;
}


// find pattern in lines from standard input with -x and -n optional arguments
/*int main(int argc, char *argv[]){
	char line[MAXLEN];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;


	 (*++argv)[0] increments the pointer argv is pointing to in the pointer array.
	 * ++argv[0] is equivalent to *++(argv[0]), this will dereference and increment the string
	 * argv is pointing to.  the string it is pointing to is incremented in the outer while
	 * loop, the string is walked through in the inner while loop.
	 * prefix increment in outer while loop because the first pointer in the pointer array
	 * is pointing to the name of the program which is always the first argument.
	 * prefix increment in the inner while loop to skip the '-'.
	 * the [0] in the inner while loop indicates 0 offset in the array, the current position
	 * in the array as maneuvered by the outer while loop.


	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c){
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if(argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while(getline(line, MAXLEN) > 1){
			lineno++;
			strstr(s,t) returns a pointer to the first occurrence of t in s.  if it is found
			and except is 1, don't print the line.  if it is not found and except is 1,
			expression evaluates to 0 != 1 and the line is printed.
			if((strstr(line, *argv) != NULL) != except){
				if(number)
					printf("%ld", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}*/

// tail: prints last 10 lines of input unless optional argument is entered
/*int main(int argc, char *argv[]){
	int n = 10, nlines;
	char *lineptr[MAXLINES];

	if(argc == 2){
		n = 0;
		if((*++argv)[0] == '-')
			while(*++argv[0])
				n = 10 * n + (*argv[0] - '0');
	}

	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
		while(n-- > 0)
			printf("%s\n", lineptr[--nlines]);
	return 0;
}*/
