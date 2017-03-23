/*
 * declarations.h
 *
 *  Created on: May 17, 2014
 *      Author: Liam
 */

#ifndef DECLARATIONS_H_
#define DECLARATIONS_H_
#define MAXWORD 100
#define BUFSIZE 100
#define NDISTINCT 1000

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdupMine(char *);
int getword(char *, int);
int getch(void);
void ungetch(int);
void sortlist(void);
void treestore(struct tnode*);

#endif /* DECLARATIONS_H_ */
