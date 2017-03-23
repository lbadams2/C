#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 20

void filecopy(FILE *, FILE *);
/*char *filecomp(FILE *, FILE *);*/


int main(int argc, char *argv[]){
	FILE *fp;

	if(argc == 1){
		printf("Enter file name");
		return -1;
	}
	else
		while(--argc > 0)
			if((fp = fopen(*++argv, "r")) == NULL){
				printf("cat: can't open %s\n", *argv);
				exit(1);
			}else{
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

/*char *filecomp(FILE *fp1, FILE *fp2){
	char line1[MAXLINE];
	char line2[MAXLINE];

	while()
	if(fgets(line1, MAXLINE. fp1) != fgets(line2, MAXLINE, fp2))

}*/

void filecopy(FILE *ifp, FILE *ofp){
	int c;

	while((c = getc(ifp)) != EOF)
			putc(c, ofp);
}
