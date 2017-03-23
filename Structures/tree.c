#include "declarations.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// trees store data without using an array

// array of pointers to structs, each element points to memory allocated by talloc when the
// struct was created in addtree.
struct tnode *list[NDISTINCT];
int ntn = 0;

/*
 * on first call p will be null. and a new node will be created.  on subsequent calls root will
 * not be null.  a node will not be created if it matches the root. else addtree will be called
 * again with the pointer to the roots left or right node.  when a node is created nested in
 * recursive calls to addtree, this does not change what addtree returns to main.  p->left
 * or p->right will be assigned once for the new node, as function percolates back up the
 * recursion, the return value will be the pointer that was already there.  the root will
 * always remain the same and be returned to main.
 */
struct tnode *addtree(struct tnode *p, char *w){
	int cond;

	if(p == NULL){
		p = talloc();
		p->word = strdup(w); // word is stored in space provided by malloc
		p->count = 1;
		p->left = p->right = NULL;
	}else if((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if(cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

/*
 * the root will be printed towards the middle of the list.  it will not be printed until all
 * of its leaves to the left have printed their leaves.  the first tree printed will be the left
 * leaf of the last node to have a left leaf, than the tree will percolate down that leaf's
 * right side.
 */
void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

// returns space for each struct to store its word
char *strdupMine(char *s){
	char *p;

	p = (char *) malloc(strlen(s) + 1); // +1 for '\0'
	if(p != NULL)
		strcpy(p, s);
	return p;
}

void treestore(struct tnode *p){
	if(p != NULL){
		treestore(p->left);
		if(ntn < NDISTINCT)
			list[ntn++] = p;
		treestore(p->right);
	}
}

/*				ShellSort
 * compares far apart elements early in run time. works on sorting small subarrays, initially
 * two in this case, that are far apart.  as the gap decreases the subarrays increase and the
 * elements compared are closer together. but the previous steps have provided more order to the
 * array as a whole.
 * comparing the values in the list and swapping them is an insertion sort.  the insertion sort
 * is performed on the subarray. j+gap = i.  insertion sort increments up the list, building a
 * sorted list behind it. it compares each element to the largest element in the sorted list,
 * which is the element just before the current element.
 * the number of iterations through the innermost for loop is the size of the subarrays.
 */
void sortlist(void){
	int gap, i, j;
	struct tnode *temp;

	for(gap = ntn/2; gap > 0; gap /= 2)
		for(i = gap; i < ntn; i++)
			for(j = i - gap; j >= 0; j -= gap){
				if((list[j]->count) >= (list[j+gap]->count))
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}
