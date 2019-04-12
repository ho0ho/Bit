#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

void mystrrev(char *src);
int myatoi(char *str);
void myitoa(int num, char *str);
void swap(char *src, int i, int j);

int main() {
	int va, vb, cnt;
	char a[10];
	scanf("%s %d", &a, &cnt);

	va = myatoi(a);
	mystrrev(a);
	vb = myatoi(a);
	int cal = va + vb;
	while (cnt--) {
		printf("   %10d\n", va);
		printf("¦»  %10d\n", vb);
		printf("------------\n");
		printf("   %10d\n\n", cal);

		va = cal;
		myitoa(va, a);
		mystrrev(a);
		vb = myatoi(a);
		cal = va + vb;
	}

	return 0;
}

void mystrrev(char *src) {
	int size = 0;
	char *f = src;
	while (*++f) size++;

	int i = 0;
	int j = size;
	while (i < size / 2)
		swap(src, i++, j--);
}

int myatoi(char *str) {
	int size = 0;
	char *f = str;
	while (*f++) size++;

	/*
	sum = 0;
	while () {
		sum *= 10;
		sum += *str -'0';
		str++;
	}	*/

	int sum = 0; 
	int j;
	while (*str) {
		int d = (*str-'0');
		j = size--;
		while (--j)
			d *= 10;
		sum += d;
		str++;
	}
	return sum;
}

void myitoa(int num, char *str) {
	char *f = str;
	while (num > 0) {
		int div = num / 10;
		int mod = num % 10;
		*str++ = mod + '0';
		num = div;
	}
	*str = '\0';
	str = f;
	mystrrev(str);	
}

void swap(char *src, int i, int j) {
	char c;
	c = src[i];
	src[i] = src[j];
	src[j] = c;
}