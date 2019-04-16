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
public:
	Number(int f = 0, int s = 0) :fir(f), sec(s) {}
	~Number() {}

	Number(const Number& cp) { fir = cp.fir; sec = cp.sec; }

	Number& operator = (const Number &right) { fir = right.fir; sec = right.sec; return *this; }
	bool operator == (const Number& right) { return (fir == right.fir && sec == right.sec); }		// overloading(member method)

	friend bool operator == (const Number& n1, const Number& n2);	// overloading(friend function)		

	void settor(int f, int s) { fir = f; sec = s; }
	int gettor_fir() const { return fir; }
	int gettor_sec() const { return sec; }
};

bool operator == (const Number& n1, const Number& n2) {		// overloading(global function)
	// return (n1.gettor_fir() == n2.gettor_fir() && n1.gettor_sec() == n2.gettor_sec());	// global일때 
	return (n1.fir == n2.fir && n1.sec == n2.sec);			// friend일때
	// return (n1 == n2);
}

int main() {
	Number a(10, 20), b(20, 40), c(a);			// copy constructor
	if (a == b) cout << "true" << endl;
	else cout << "false" << endl;

	getchar();
	return 0;
}