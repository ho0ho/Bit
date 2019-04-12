#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

typedef unsigned int uint;
typedef int(*myfp_t)(int, int);	// 함수포인터의 타입지정

int add(int a, int b) {	return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

// 함수의 매개변수로 함수를 던지기 => 함수포인터 이용
int temp(myfp_t pf, int a, int b) { return pf(a, b); }	// leaf function call 

int main() {
	int a = 10, b = 5;
	int(*pf[])(int, int) = { add, sub, mul, divide };

	for (myfp_t f : pf)
		printf("%d\n", temp(f, 10, 5));

	int i = 123;
	char ch = 'A';
	char arr[] = "abcde";
	void *p;		// 범용포인터 => 다 담을수 있음 => 그러나 자기가 뭘 담고있는지 모름(== 몇바이트씩 읽어야할지 모름)
					// 그래서 사용할 땐 캐스팅하고 사용해야함
	
	p = &i;
	printf("%d\n", *(int *)p);		
	
	p = &ch;
	printf("%c\n", *(char *)p);

	p = arr;
	printf("%s\n", (char *)p);		// %s는 원래 주소값을 그대로 받는 형식지정자
									// 그래도 캐스팅까지 해주는게 good!
	printf("%c %c %c\n", *(char *)p, *((char *)p + 1), *((char *)p + 2));	// p에게 타입을 계속 일깨워줌

	printf("%c\n", *(char *)p);
//	printf("%c\n", *(((char *)p)++) );
	return 0;
}