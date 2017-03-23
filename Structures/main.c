#include "declarations.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * main always gets the root of the tree from addtree, the value returned does not change
 * once it is assigned.
 */
int main(void){
	int i;
	struct tnode *root;
	char word[MAXWORD];
	extern int ntn;
	extern struct tnode *list[];

	root = NULL;
	while(getword(word, MAXWORD) != '!')
		if(isalpha(word[0]))
			root = addtree(root, word);
	//treeprint(root);
	treestore(root);
	for(i = 0; i < ntn; i++)
		printf("%d %s\n", list[i]->count, list[i]->word);
	return 0;
}

/*
 * spaces are skipped, a space after each word will be pushed back by ungetch and retrieved
 * again by getch.  if c is a number or not a letter it will be returned to main and a node
 * will not be added, getword will be called again.
 */
int getword(char *word, int lim){
	int c;
	// maybe use this temp var w so that word is not incremented and can be returned without
	// having to decrement
	char *w = word;

	while(isspace(c = getch()))
		;
	if(c != '!')
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for( ;--lim > 0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
