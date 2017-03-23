#include <stdio.h>

int main(void){
	int c, cc, i, j;
	int wlength[10];
	cc = 0;

	for(i = 0; i < 10; i++)
		wlength[i] = 0;

	while((c = getchar()) != 'q'){
		if(c == ' ' || c == '\n' || c == '\t'){
			wlength[cc]++;
			cc = 0;
		}
		else
			cc++;
	}

	printf("Value of array: ");
	for(i = 0; i < 10; i++)
		printf("%d ", wlength[i]);

	printf("\n");
	for(i = 1; i < 10; i++){
		printf("%d characters in word: ", i);
		for(j = 0; j < wlength[i]; j++){
			printf("-");
		}
		printf("\n");
	}
	return 1;
}
