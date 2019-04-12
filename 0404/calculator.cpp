#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

typedef unsigned int uint;
typedef int(*myfp_t)(int, int);	// �Լ��������� Ÿ������

int add(int a, int b) {	return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

// �Լ��� �Ű������� �Լ��� ������ => �Լ������� �̿�
int temp(myfp_t pf, int a, int b) { return pf(a, b); }	// leaf function call 

int main() {
	int a = 10, b = 5;
	int(*pf[])(int, int) = { add, sub, mul, divide };

	for (myfp_t f : pf)
		printf("%d\n", temp(f, 10, 5));

	int i = 123;
	char ch = 'A';
	char arr[] = "abcde";
	void *p;		// ���������� => �� ������ ���� => �׷��� �ڱⰡ �� ����ִ��� ��(== �����Ʈ�� �о������ ��)
					// �׷��� ����� �� ĳ�����ϰ� ����ؾ���
	
	p = &i;
	printf("%d\n", *(int *)p);		
	
	p = &ch;
	printf("%c\n", *(char *)p);

	p = arr;
	printf("%s\n", (char *)p);		// %s�� ���� �ּҰ��� �״�� �޴� ����������
									// �׷��� ĳ���ñ��� ���ִ°� good!
	printf("%c %c %c\n", *(char *)p, *((char *)p + 1), *((char *)p + 2));	// p���� Ÿ���� ��� �ϱ�����

	printf("%c\n", *(char *)p);
//	printf("%c\n", *(((char *)p)++) );
	return 0;
}