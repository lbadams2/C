#include <stdio.h>
#include <string.h>

void qsort(int[], int, int);
void swap(int[], int, int);
void itob(int, char[], int);
void reverse(char[], int, int);

int main(void){
	int i;
	int v[] = {12, 10, 19, 14, 15, 8, 18, 13, 7, 20, 12, 17};
	char s[3];
	/* swap 12 and 14.  last = 0.  compare each element starting at v[1] = 10 to v[0] = 14
	 * if less, increment last and swap with current element. 10 is less than 14 but it won't
	 * swap.  because ++last = i.  if they are all less than v[left], last will keep getting incremented
	 * and swapped with left after the for loop.  if i and last are not equal after last is
	 * incremented, than the value at the index of last is greater than the value at the left
	 * index. that signifies that the value at the just incremented last index did not satisfy
	 * the if statement. swapping i and last will ensure that the value at the last index
	 * is less than the value at the left index. the final swap places the value at the left
	 * index at the last index, which is it rightful place in the array, everything to its left
	 * will be less than and everything to its right will be greater.  last essentially counts
	 * the number of elements that are less than left. the swap within the if condition ensures
	 * that elements greater than the left element will be to the right of the last index. the
	 * new left will be the final number that was less than the previous left sequentially
	 */
	qsort(v, 0, 11);

	for(i = 0; i<12; i++)
		printf("%d ", v[i]);
	itob(345, s, 16);
	printf("\n%s", s);
	int len = strlen(s);
	reverse(s, 0, len);
	printf("\n%s", s);
	return 1;
}

void qsort(int v[], int left, int right){
	int i, last;

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);// i think on average a random group of numbers will be somewhat arranged from least to greatest
									// this isn't necessary, but reduces run time because of the fact above
	last = left;
	/*// compare every number to the pivot element, the element in the middle of the array that
	// was placed at the beginning.  last is the index of the last element that is less than
	// the pivot element. if i and last are different than the element at the last index will
	// be greater than the pivot element.  index i will always be greater than or equal to index
	// last.*/
	for(i = left+1; i <= right; i++){
		if(v[i] < v[left])
			swap(v, ++last, i); // moves element greater than pivot to the right of last
								// and places element less than pivot at the last index
	}
	swap(v, left, last);// puts pivot element in correct place, last is number of elements less than left element
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int i, int j){
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void itob(int n, char s[], int b){
	int sign;
	static int i = 0;

	if((sign = n) < 0)
		n = -n;

	if(n/b)
		itob((n/b), s, b);
	if(n % b > 9)
		s[i++] = (n % b - 10) + 'A';
	else
		s[i++] = n % b + '0';
	s[i] = '\0';
}

void reverse(char s[], int i, int len){
	int j, temp;

	j = len - (i + 1);
	if(i < j){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		reverse(s, ++i, len);
	}
}
