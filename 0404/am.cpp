#include <stdio.h>

#pragma warning(disable : 4996);

void print_a(char **p);

int main() {

	char a[3][10] = { "abc", "defg", "zzzzzz" };

//	array1to2(a);		// void array1to2(char(*p)[3]); or (char p[의미없는숫자][10]) or (char p[][10])
//	array1to2(a[2]);	// void array1to2(char *p);

	char *aa[3] = { "abc", "home", "print" };
	print_a(aa);


	return 0;
}

void print_a(char **p) {	// char *a[3] = {"abc", "home", "print"};
	// for pointer
	// abc에서 bc출력
	printf("%s\n", *p + 1);		// &(*p)[1] or *p + 1 or p[0] + 1 (== &p[0][0] + 1)
	// home에서 h 출력
	printf("%c\n", );	// p[1][0] or *(p[1]) or *(*(p+1)) or (*(p+1))[0] or 1[p][0] or 0[1[p]]
	// print에서 i출력
	printf("c\n", *(p[0] + 2) + 2);	// p[2][2] or *(p[2]+2) or *(*(p+1)+2) or (*(p+1))[2]
}
