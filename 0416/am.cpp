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

int main() {
	Bird *e = new Eagle;
	Bird *s = new Seagull;

	Bird *arr[] = { e, s };
	for (Bird *b : arr)
		b->fly();

	Eagle *ee = dynamic_cast<Eagle *>(e);
	ee->hahah();
	Seagull *ss = dynamic_cast<Seagull *>(s);
	ss->hohoh();

	getchar();
	return 0;
}
