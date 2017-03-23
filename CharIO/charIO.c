#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

int main(void){
	int c;
	bool lastCharSpace = false;
	while((c = getchar()) != 'q'){
		if(c == 0x20){
			lastCharSpace = true;
		}
		else if(c != 0x20 && lastCharSpace == true){
			putchar(' ');
		    putchar(c);
		}
		else
			putchar(c);
	}
}
