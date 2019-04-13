#include <iostream>
#include <cstdlib>
using namespace std;

#pragma warning (disable : 4996)

void swap1(int &ra, int &rb) {
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap_p(int *(&pa), int *(&pb)) {	// pa�� Ÿ���� int *. ���ڷ� ���޹޴� �޸�(int*)�� pa��� �̸� �߰�
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

//struct Number {
//	int fst;
//	int snd;
//};
//
//Number& NumberAdd(const Number &pa, const Number &pb) {
//	Number *add = (Number *)malloc(sizeof(Number));		// ���� add�� local�̶� �Լ� ������ �Ҹ�
//	add->fst = pa.fst + pb.fst;							// �׷��� �� �޸𸮴� ���� �����ְ� �� �޸𸮴� �״��(&) �ѱ�Ƿ� ��ȿ
//	add->snd = pa.snd + pb.snd;							// malloc���� ���� �޸��� �������� free�� ����������!(�Լ��� ���ϰ� ���X)
//	return *add;
//}

//int main() {
//	Number *pa = (Number *)malloc(sizeof(Number));
//	pa->fst = 1;
//	pa->snd = 2;
//	Number *pb = (Number *)malloc(sizeof(Number));
//	pb->fst = 10;
//	pb->snd = 20;	
//	
//	Number &rpa = NumberAdd(*pa, *pb);
//	cout << rpa.fst << ", " << rpa.snd << endl;
//	free(&rpa);			// rpa �޸� ����
//	free(pa);
//	free(pb);
//	getchar();
//	return 0;
//}
//
//int main() {
//	const int a = 10;
//	const int *p = &a;
//	const int *(&rp) = p;
//
//	cout << a << endl;
//	cout << *p << endl;
//	cout << *rp << endl;
//	
//	getchar();
//	return 0;
//}

void func1(int *(&ppa)) {
	*ppa = 10;
}

void func2(int *ppa) {
	*ppa = 20;
}

int& func3(int &ra) {
	return (ra = 10);
}

int func4(int &ra) {
	return (ra = 40);
}

//int main() {
//	int a = 10;
//	int *pa = &a;
//	func1(pa);
//	cout << *pa << endl;
//	func2(pa);
//	cout << *pa << endl;
//
//	int &rb = func3(a);		// a, func3�� �Ű����� ra, rb �� ���� ��� ������ �ϳ��� �޸𸮿� ���� �̸�
//	int b = func3(a);		// b�� a, ra(func3�� �Ű�����)�ʹ� �ٸ� ���ο� �޸�. func3(a)�� ���� �����Ͽ� ���� => ���۷������� �Ϲݺ����� ���� ���� ����
//	int c = func4(a);		// c�� a, ra(func3�� �Ű�����)�ʹ� �ٸ� ���ο� �޸�. func3(a)�� ���� �����Ͽ� ����
//	int &d = func4(a);		// error. func4(a)���� ���. ���۷��� ����(d)�� �����(func4�� ������ int)�� ���� �� ����.
//	const int &cd = func4(a);		// ���۷��������� ������� �������� constŰ���� ����ϸ� ��.
//
//	return 0;
//}

class Number {
	int fir;
	int sec;
public:
	Number(int fir = 0, int sec = 0) : fir(fir), sec(sec) {}
	Number(const Number& other) {		// copy constructor
		fir = other.fir;
		sec = other.sec;
	}
	~Number() {}

	Number& operator = (const Number& right) {
		fir = right.fir;
		sec = right.sec;
		return *this;
	}
	Number& DisplayAndRead(const char *msg) {
		cout << msg;
		cin >> fir >> sec;
		return *this;
	}
	void printData(const char *msg) {
		cout << msg << " " << fir << " + " << sec << endl;
	}

	Number& addition(const Number& a, const Number& b) {
		fir = a.fir + b.fir;
		sec = a.sec + b.sec;
		return *this;
	}
	int getFir() { return fir; }
	int getSec() { return sec; }
	void view(void) { cout << fir << "," << sec << endl; }
};
//
//int main() {
//	Number a, b, c;
//	a.DisplayAndRead(" A = ");
//	b.DisplayAndRead(" B = ");
//	c.addition(a, b);
//	a.printData(" A = ");
//	b.printData(" B = ");
//	c.printData(" A+B = ");
//	
//	getchar();
//	getchar();
//	return 0;
//}
//
//int main() {
//	Number e;		// error. Number() ������ �����ڰ� ���ǵ��� �ʾұ� ����.
//	Number e2();		// error. Number() ������ �����ڰ� ���ǵǾ�� �̷��� ���������ʵ��� ����
//
//	Number n(2);		// Number��ü n ����
//	Number *pn = new Number(3, 5);
//	n.view();
//	pn->view();
//
//	getchar();
//	return 0;
//}
//
//struct shallow {
//	int key;
//	char *p;		// �����ʹ� �� ��(�ּ�)�� ����(���� ����)
//};
//
//struct deep {
//	int key;
//	char p[10];		// �迭�� �ƿ� ������ �Ҵ��Ͽ� ����(���� ����)
//};
//
//int main() {
//	shallow a = { 10, "AAA" }, b;
//	deep c = { 20, "CCC" }, d;
//
//	b = a;		// ����ü�� 
//	d = c;
//	return 0;
//}


class Wrap {
public:
	virtual void eat() { }
};

class bob : public Wrap {
public:
	void eat() { cout << "��Դ�" << endl; }
};

class kok : public Wrap {
public:
	void eat() { cout << "���Դ�" << endl; }
};

class kim : public Wrap {
public:
	void eat() { cout << "��Դ�" << endl; }
};

//class Brunch {
//public:
//	void eattherice(bob &rb) { rb.eat(); }
//	void eatthesoup(kok &rok) { rok.eat(); }
//	void eatthekim(kim &rk) { rk.eat(); }
//};

void eat(Wrap& w) {
	w.eat();
}

int main() {
	/*Brunch bb;
	bob ob;
	kok ok;
	kim im;
	bb.eattherice(ob);
	bb.eatthesoup(ok);
	bb.eatthekim(im);*/

	bob b;
	kok k;
	kim ki;
	eat(b);
	eat(k);
	eat(ki);

	getchar();
	return 0;
}