#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void top();
void duplicate();
void swap();
void clear();

int main(void){
	int type;
	double op2;
	char s[MAXOP];
	double convert = 0.0;
	double oneDigit = 0;
	double tenDigit = 0;
	int modConvert = 0;

	while((type = getop(s)) != 'q'){
		switch(type){
		case NUMBER:
				convert = atof(s);
				oneDigit = (double)((int)convert % 10);
				modConvert = (int)convert;
				tenDigit = (double)((modConvert/10) % 10);
				push(tenDigit);
				push(oneDigit);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() - op2);
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	printf("%g", pop());

	return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full\n");
}

double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* s[0] will hold first char, if character is an operator return it, if it is a digit collect
 * subsequent digits and store in the array.  the last character retrieved will not be a digit
 * overwrite it in s[i] = '\0', then place it in the buffer with ungetch.  return a symbol
 * that a number was found
 * */
int getop(char s[]){
	int i, c;
	static int save = 0;
	if(save){
		s[0] = c = save;
		save = 0;
	}
	else{
		while((s[0] = c = getch()) == ' ' || c == '\t')
			;
	}
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != 'q')
		save = c;
	return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

// get character from buffer, ungetch will always point bufp to the element beyond the last
// character
int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character on buffer that was needs to be read again
void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void top(){
	int temp = sp;
	printf("Top element: %g", val[--temp]);
}

void duplicate(){
	int temp = sp;
	double top = 0;

	top = val[--temp];
	push(top);
}

void swap(){
	int temp = sp;
	double top = 0;
	double second = 0;
	top = val[--temp];
	second = val[--temp];
	push(top);
	push(second);
}

void clear(){
	while(sp > 0)
		pop();
	printf("Stack Pointer: %d", sp);
}
