#include <stdio.h>

int strrindex(char[], char[]);

int main(void){
	char input[] = "couldwouldshould";
	char pattern[] = "ould";
	int result = 0;
	result = strrindex(input, pattern);
	printf("%d", result);
}

int strrindex(char s[], char t[]){
	int i, j, k, index;
	index = 0;

	for(i = 0; s[i] != '\0'; i++){
		if(t[k] == '\0')
			index = i-1;
		for(j = i, k = 0; (t[k] != '\0') && s[j] == t[k]; j++, k++)
			;
	}
	if(index > 0)
		return index;
	else
		return -1;
}
