#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){// left side of expression calculates unused space
		allocp +=n; // points to next free element symbolizing next unused memory address
		return allocp - n; // returns first free element to caller
						   // allocp + n - (allocp - n) = n, but arithmetic is inclusive
	}else
		return 0;
}

void afree(char *p){
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)// array contains address, value of p
		allocp = p;
}
