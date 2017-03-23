/* a string constant assigned to a character pointer, the char* holds the address of the first
 * char in the string.
 * C does not provide operators for processing a string as a unit
 * *p++ dereferences p than increments p
 * *--p decrements p then dereferences it
 */

int strlenMine(char *s){
	char *p = s;

	while(*p != '\0')
		p++;
	return p-s;
}

// the addresses are passed by value
// postfix increment doesn't change variable until after the char has been fetched
// *s = *t assigns the value that s points to to the value t points to
void strcpyMine(char *s, char *t){
	while(*s++ = *t++)
		;
}

int strcmpMine(char *s, char *t){

	for(;*s == *t; s++, t++)
		if(*t == '\0')
			return 0;
	return *s - *t;
}

// cannot append two string literals, must have enough space to hold both strings
void strcatMine(char *s, char *t){
	while(*s)
		s++;
	while((*s++ = *t++) != '\0')
		;
}


int strend(char *s, char *t){
	char *p = t;

	for(;*s ; s++){
		if(!*p)
			p = t;
		if(*s == *p && *s){
			p++;
			continue;
		}
	}
	if(!*p && !*s)
		return 1;
	else
		return 0;
}
