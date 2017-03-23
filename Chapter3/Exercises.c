#include <stdio.h>
#include<time.h>

int binsearch(int, int[], int);
void escape(char[], char[]);
void expand(char[], char[]);
void itob(int, char[], int);
void reverse(char[]);

int main(void){
	char s[5];
	itob(93, s, 16);
	printf("%s", s);
}

int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low <= high){
		mid = (low + high)/2;
		if(x < v[mid])
			high = mid -1;
		else if(x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

// input string must end with '\0' otherwise inconsistent runtime behavior
void escape(char s[], char t[]){
	int i,j;
	for(i = j = 0; t[i] != '\0'; i++){
		switch(t[i]){
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

void expand(char s[], char t[]){
	int end, i,range,j;
	t[0] = 0;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == '-')
			continue;
		else if(t[0] == 0)
			t[0] = s[i];
		else
			end = s[i];
	}
	range = end - t[0];
	for(j = 1; j <= range; j++)
		t[j] = t[j-1] +1;
}

void itob(int n, char s[], int b){
	int i, sign;

	if((sign = n) < 0)
		n = -n;

	i = 0;

	do{
		if(n % b > 9)
			s[i++] = (n % b - 10) + 'A';
		else
			s[i++] = n % b + '0';
	}while((n /= b) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int i = 0;
	int j, temp;

	while(s[i] != '\0')
		i++;
	i -= 1;
	for(j =0; j < i; j++){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i--;
	}
}
