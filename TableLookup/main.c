#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

static struct nlist *hashtab[HASHSIZE];
char *names[] = {
		"one",
		"two",
		"three",
		"four",
		"five"
};
char *defns[] = {
		"1",
		"2",
		"3",
		"4",
		"5"
};

int main(void){
	struct nlist *p[10];
	int i;

	for(i = 0; i < 5; i++){
		p[i] = install(names[i], defns[i]);
		printf("Name: %s   Defn: %s\n", p[i]->name, p[i]->defn);
	}
	/*undef("three");
	if(lookup("three") == NULL)
		printf("%s removed", "three");*/
	return 0;
}

unsigned hash(char *s){
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31*hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *name){
	struct nlist *np;

	for(np = hashtab[hash(name)]; np != NULL; np = np->next)
		if(strcmp(name, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL){
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		// puts at head of linked list
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else
		free((void *) np->defn);
	if((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name){
	struct nlist *prev;
	struct nlist *np;
	int h = hash(name);
	for(np = hashtab[h]; np != NULL; np = np->next){
		if(strcmp(name, np->name) == 0)
			break;
		prev = np;
	}
	if(np != NULL){
		if(prev == NULL)
			hashtab[h] = np->next;
		else
			prev->next = np->next;
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);
		}
}

