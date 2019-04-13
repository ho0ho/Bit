#include <iostream>
using namespace std;

void swap1(int &ra, int &rb) {
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap_p(int *(&pa), int *(&pb)) {	// int* 역할을 하는데 타입은 int&인 pa, pb 
	int *tmp;							// => (int *)형에 대한 alias이기도 한 int &형으로 선언. 
	tmp = pa;
	pa = pb;
	pb = tmp;
}

//int main() {
//	int a = 3, b = 5;
//	int *pa = &a, *pb = &b;
//
//	cout << *pa << ", " << *pb << endl;
//	swap_p(pa, pb);		// 포인터를 받아서 각자 가리키는 방향 교환하기
//	cout << *pa << ", " << *pb << endl;
//	getchar();
//	return 0;
//}

struct Number {
	int fst;
	int snd;
};

Number& NumberAdd(const Number &pa, const Number &pb) {
	Number *add = (Number *)malloc(sizeof(Number));		// 변수 add는 local이라 함수 리턴후 소멸
	add->fst = pa.fst + pb.fst;							// 그러나 그 메모리는 힙에 남아있고 그 메모리는 그대로(&) 넘기므로 유효
	add->snd = pa.snd + pb.snd;							// malloc으로 받은 메모리의 스코프는 free를 만날때까지!(함수의 리턴과 상관X)
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
	free(&rpa);			// rpa 메모리 해제
	free(pa);
	free(pb);
	getchar();
	return 0;
}