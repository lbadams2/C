#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int trim(char[], int i);
void reverse(char[]);

int main(void){
	int len, max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = getline(line, MAXLINE)) > 1){
		if(len > max){
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0){
		reverse(longest);
		printf("%s", longest);
	}
	return 0;
}

int getline(char s[], int lim){
	int c, i;

	for(i = 0; i<lim-1 && (c = getchar()) != '\n'; i++)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	i = trim(s, i);
	return i;
}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}

int trim(char s[], int len){
	int temp = len - 2;

		while(s[temp] == ' '){
			s[temp] = s[len -1];
			s[temp + 1] = s[len];
			temp -= 1;
		}
	return temp + 2;
}

void reverse(char s[]){
	int i = 0;
	int j, temp;

	while(s[i] != '\0')
		i++;
	i -= 2;
	for(j =0; j < i; j++){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i--;
	}
}
