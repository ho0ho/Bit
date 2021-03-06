#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

#pragma warning (disable : 4996)

void swap1(int &ra, int &rb) {
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap_p(int *(&pa), int *(&pb)) {	// pa의 타입은 int *. 인자로 전달받는 메모리(int*)에 pa라는 이름 추가
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

//struct Number {
//	int fst;
//	int snd;
//};
//
//Number& NumberAdd(const Number &pa, const Number &pb) {
//	Number *add = (Number *)malloc(sizeof(Number));		// 변수 add는 local이라 함수 리턴후 소멸
//	add->fst = pa.fst + pb.fst;							// 그러나 그 메모리는 힙에 남아있고 그 메모리는 그대로(&) 넘기므로 유효
//	add->snd = pa.snd + pb.snd;							// malloc으로 받은 메모리의 스코프는 free를 만날때까지!(함수의 리턴과 상관X)
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
//	free(&rpa);			// rpa 메모리 해제
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
//	int &rb = func3(a);		// a, func3의 매개변수 ra, rb 세 변수 모두 동일한 하나의 메모리에 대한 이름
//	int b = func3(a);		// b는 a, ra(func3의 매개변수)와는 다른 새로운 메모리. func3(a)의 값을 복사하여 받음 => 레퍼런스값을 일반변수로 받을 때도 복사
//	int c = func4(a);		// c는 a, ra(func3의 매개변수)와는 다른 새로운 메모리. func3(a)의 값을 복사하여 받음
//	int &d = func4(a);		// error. func4(a)값은 상수. 레퍼런스 변수(d)는 상수값(func4의 리턴은 int)을 받을 수 없음.
//	const int &cd = func4(a);		// 레퍼런스변수가 상수값을 받으려면 const키워드 사용하면 됨.
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
//	Number e;		// error. Number() 형식의 생성자가 정의되지 않았기 때문.
//	Number e2();		// error. Number() 형식의 생성자가 정의되었어도 이렇게 정의하지않도록 주의
//
//	Number n(2);		// Number객체 n 생성
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
//	char *p;		// 포인터는 그 값(주소)만 복사(얕은 복사)
//};
//
//struct deep {
//	int key;
//	char p[10];		// 배열은 아예 공간을 할당하여 복사(깊은 복사)
//};
//
//int main() {
//	shallow a = { 10, "AAA" }, b;
//	deep c = { 20, "CCC" }, d;
//
//	b = a;		// 구조체는 
//	d = c;
//	return 0;
//}


class Wrap {
public:
	virtual void eat() { }
};

class bob : public Wrap {
public:
	void eat() { cout << "밥먹다" << endl; }
};

class kok : public Wrap {
public:
	void eat() { cout << "국먹다" << endl; }
};

class kim : public Wrap {
public:
	void eat() { cout << "김먹다" << endl; }
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

//int main() {
//	/*Brunch bb;
//	bob ob;
//	kok ok;
//	kim im;
//	bb.eattherice(ob);
//	bb.eatthesoup(ok);
//	bb.eatthekim(im);*/
//
//	bob b;
//	kok k;
//	kim ki;
//	eat(b);
//	eat(k);
//	eat(ki);
//
//	getchar();
//	return 0;
//}

#define SIZE 20
static int cnt = 0;

class Engine {
private:
	int km;
	char mode;
public:
	Engine(int _km = 0, const char _mode = '?') : km(_km), mode(_mode) {}
	~Engine() {}

	void speed_engine(/*int _km, const char _mode*/) {
		cout << "[" << mode << "]  " << km << "km" << endl;
	}
	void stop_engine(void) {
		cout << "엔진을 정지합니다\n";
	}

	int get_km(void) { return km; }
	char get_mode(void) { return mode; }
	void set_km(int _km) { km = _km; }
	void set_mode(int _mode) { mode = _mode; }

	Engine& operator = (const Engine &other) {
		set_km(other.km);
		set_mode(other.mode);
		return *this;
	}
};

class BlackBox {
private:
	Engine *history;
public:
	void make_history_size(/*BlackBox &his, */int _size) {
		history = new Engine[_size];
	}

	void update_history(/*BlackBox &_his, int _rkm, const char _rmode*/Engine e) {
		history[cnt++] = e;
	}

	void display_history(void) {
		int f = 0;
		while (f < cnt) {
			history[f++].speed_engine();
		}
	}
};

class Car {
public:
	BlackBox *eye;
public:
	Engine *sedan, *sports;

	Car() {}
	~Car() { delete eye; delete sedan; delete sports; }
	void autoStop(void) { cout << "정지합니다" << endl; }

	void make_bbox(void) {
		eye = new BlackBox;
		eye->make_history_size(20);
	}

	void addEngine(char op, int speed) {
		if (op == 'e') {
			sedan = new Engine(speed, 'e');
			eye->update_history(*sedan);
		}
		else if (op = 's') {
			sports = new Engine(speed, 's');
			eye->update_history(*sports);
		}
		else
			cout << "wrong op" << endl;
	}
};

typedef char c;
typedef c cc[10];
typedef cc dim2[3];

int main() {
	int user_s;
	char user_m;
	dim2 en = { "[e]co", "[s]ports", "[h]istory" };
	dim2 kn = { "연비주행", "과속주행", "히스토리" };

	cout << "------------------------------------------" << endl;
	for (size_t i = 0; i < 3; i++)
		cout << en[i] << "\t\t" << kn[i] << endl;
	cout << "------------------------------------------" << endl;
	cout << "원하는 자동차 모드를 선택하시오 : ";
	cin >> user_m;

	Car c;	
	c.make_bbox();

	Engine *e = NULL;
	while (user_m != 'q') {
		if (user_m == 'h') {
			cout << "히스토리모드를 선택하셨습니다.\n";
			c.eye->display_history();
		}
		else {
			if (user_m == 'e') {
				e = c.sedan;
				cout << "에코모드를 선택하셨습니다.\n";
			}
			else if (user_m == 's') {
				e = c.sports;
				cout << "스피드모드를 선택하셨습니다.\n";
			}
			cin >> user_s;
			c.addEngine(user_m, user_s);
			e->speed_engine();
		}

		cout << endl << endl;
		cout << "------------------------------------------" << endl;
		for (size_t i = 0; i < 3; i++)
			cout << en[i] << "\t\t" << kn[i] << endl;
		cout << "------------------------------------------" << endl;
		cout << "원하는 자동차 모드를 선택하시오 : ";
		cin >> user_m;
	}

	getchar();
	return 0;
}

//int main() {
//	string arr[25];				// 'e'입력받았을 때 "에코"로 바꿔받는 방법.
//	arr[1] = "echo";			// 아스키코드 이용 
//	arr[4] = "history";
//	arr[15] = "speed";
//	char c;
//	cin >> c;
//	cout << arr[c % 25];
//}