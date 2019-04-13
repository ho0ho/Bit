#include <iostream>
using namespace std;

void swap1(int &ra, int &rb) {
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap_p(int *(&pa), int *(&pb)) {	// int* ������ �ϴµ� Ÿ���� int&�� pa, pb 
	int *tmp;							// => (int *)���� ���� alias�̱⵵ �� int &������ ����. 
	tmp = pa;
	pa = pb;
	pb = tmp;
}

//int main() {
//	int a = 3, b = 5;
//	int *pa = &a, *pb = &b;
//
//	cout << *pa << ", " << *pb << endl;
//	swap_p(pa, pb);		// �����͸� �޾Ƽ� ���� ����Ű�� ���� ��ȯ�ϱ�
//	cout << *pa << ", " << *pb << endl;
//	getchar();
//	return 0;
//}

struct Number {
	int fst;
	int snd;
};

Number& NumberAdd(const Number &pa, const Number &pb) {
	Number *add = (Number *)malloc(sizeof(Number));		// ���� add�� local�̶� �Լ� ������ �Ҹ�
	add->fst = pa.fst + pb.fst;							// �׷��� �� �޸𸮴� ���� �����ְ� �� �޸𸮴� �״��(&) �ѱ�Ƿ� ��ȿ
	add->snd = pa.snd + pb.snd;							// malloc���� ���� �޸��� �������� free�� ����������!(�Լ��� ���ϰ� ���X)
	return *add;
}

int main() {
	Number *pa = (Number *)malloc(sizeof(Number));
	pa->fst = 1;
	pa->snd = 2;
	Number *pb = (Number *)malloc(sizeof(Number));
	pb->fst = 10;
	pb->snd = 20;	
	
	Number &rpa = NumberAdd(*pa, *pb);
	cout << rpa.fst << ", " << rpa.snd << endl;
	free(&rpa);			// rpa �޸� ����
	free(pa);
	free(pb);
	getchar();
	return 0;
}