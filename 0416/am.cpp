#include <iostream>
using namespace std;

class Bird {
protected:
	
public:
	/*virtual Bird() = 0;*/
	virtual void fly() = 0;
};

class Eagle : public Bird {
private:
	int val;
public:
	Eagle(int val = 0) : val(val) {}
	void fly() { cout << "Eagle" << endl; }		// virtual 
	void hahah() { cout << "hahaha " << val << endl; }	// dynamic_cast(down-casting)
};

class  Seagull : public Bird {
private:
	int val;
public:
	Seagull(int val = 40) : val(val) {}
	void fly() { cout << "Seagull" << endl; }	// virtual
	void hohoh() { cout << "hohoho " << val << endl; }	// dynamic_cast(down-casting)
};

//int main() {
//	Bird *e = new Eagle;
//	Bird *s = new Seagull;
//
//	Bird *arr[] = { e, s };
//	for (Bird *b : arr)
//		b->fly();
//
//	Eagle *ee = dynamic_cast<Eagle *>(e);
//	ee->hahah();
//	Seagull *ss = dynamic_cast<Seagull *>(s);
//	ss->hohoh();
//
//	getchar();
//	return 0;
//}

class Number {
	int fir;
	int sec;
	int *arr;
	int size;
public:
	Number(int f = 0, int s = 0) :fir(f), sec(s), size(10), arr(new int[size]) {}
	~Number() {}

	Number(const Number& cp) { fir = cp.fir; sec = cp.sec; }

	Number& operator = (const Number &right) { fir = right.fir; sec = right.sec; return *this; }
	bool operator == (const Number& right) { return (fir == right.fir && sec == right.sec); }		// overloading(member method)
	int& operator [] (int idx) { return arr[idx]; }			// [] ������ �����ε� => ����θ� ���ǰ���
	int& operator [] (int idx) const { return arr[idx]; }	// ?
	const Number operator + (int num) const {		// a + 2 = b; �̷��� ���X (-> const����)
		/*number n(fir + num, sec + num);*/				// �ӽð�ü n�� ����ϹǷ� �����ؼ� �Ѱܾ� ��(&���� ����)
		/*return n;*/
		return Number(fir + num, sec + num);
	}
	operator int() const { return fir; }		// int() ����ȯ ������ �����ε�(���� ���� void ����) => ����θ� ���ǰ���

	friend bool operator == (const Number& n1, const Number& n2);	// overloading(friend function)		
	friend Number& operator + (int num, Number& n);

	void settor(int f, int s) { fir = f; sec = s; }
	int gettor_fir() const { return fir; }
	int gettor_sec() const { return sec; }
};

bool operator == (const Number& n1, const Number& n2) {		// overloading(global function)
	// return (n1.gettor_fir() == n2.gettor_fir() && n1.gettor_sec() == n2.gettor_sec());	// global�϶� 
	return (n1.fir == n2.fir && n1.sec == n2.sec);			// friend�϶�
	// return (n1 == n2);
}

Number& operator + (int num, Number& n) {		// ��ȯ��Ģ���� �����ϰ� �ϱ� ���� �����Լ� �����ε�
	n.fir += num;
	n.sec += num;
	return n;
}

ostream& operator << (ostream& out, const Number& obj) {		// << �����ڴ� �����Լ��� �����ε�(����Լ��Ϸ��� coutŬ������ ����� �����߾����)
	out << "(" << obj.gettor_fir() << ", " << obj.gettor_sec() << ")" << endl;
	return out;
}

int main() {
	Number a(10, 20), b(20, 40), c(a);			// copy constructor
	if (a == b) cout << "true" << endl;
	else cout << "false" << endl;

	a = a + 5;			// ����Լ� operator + () ȣ��
	cout << a.gettor_fir() << ", " << a.gettor_sec() << endl;

	a = 5 + a;			// �����Լ� operator + () ȣ��
	cout << a.gettor_fir() << ", " << a.gettor_sec() << endl;

	cout << int(a) << endl;

	b[0] = 3;
	cout << b[0] << endl;

	cout << a;

	getchar();
	return 0;
}