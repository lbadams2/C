#include <stdio.h>
#define YES 1
#define NO 0

int htoi(char[]);
void squeeze(char[], char[]);
unsigned setbits(unsigned, int, int, unsigned);

int main(void){

	unsigned x, y;
	x = 0356; // 011101110
	y = 0412; // 100001010

	x = setbits(x, 4, 3, y); //011101010 = 234
	printf("%u", x);
	return 0;
}

int htoi(char s[]){
	int i, n, inhex, hexdigit;

	n= 0;
	inhex = YES;
	for (i = 0; inhex == YES; ++i){
		if(s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if(s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;
		n = 16 * n + hexdigit;
	}
	return n;
}

/* For each character in s1, iterate over the entire s2 array, if the for loop breaks
 * before the end of s2, the ith character in s1 is not copied. k maintains the index of
 * characters that are copied. k will be less than or equal to i, characters are passed
 * over when there is a match between s1 and s2 and then replaced by the next non match
 */
void squeeze(char s1[], char s2[]){
	int i, j, k;
	k = 0;
	for(i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++){
			;
		}
		if(s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

/* generate n bits turned off, shift the left most off bit to position p and & with x
 * get only right most n bits from y, shift the left most to position p
 * OR these two to copy the n right most y bits to x beginning at position p.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y){
	return (x & ~(~(~0 << n) << (p + 1 -n))) |
			(y & ~(~0 << n)) << (p + 1 - n);

}
