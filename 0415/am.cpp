#include <iostream>
using namespace std;

//namespace mystd {
//	int a = 10;
//	namespace mystdin {
//		int a = 20;
//	}
//}
//
//int a = 30;				// global(외부에서 extern으로 사용가능)
//static int a = 40;		// static + global (이 파일안에서만 사용가능한 전역변수, 이건 외부파일에서 extern으로도 사용불가)
//class Num {
//private:
//	int a;					// Num n; n.a로 사용(클래스 외부에서는 사용x, private)
//	static int praaa;		// static 멤버함수만 사용가능한 변수(private) 클래스 밑에서 초기화해야함. Num::praaa로 사용
//public:
//	static int uraaa;
//	Num(int a = 0) : a(a) {}
//	void set_aaa(int aaa) { this->a = aaa; }
//	int get_aaa() const { return this->a; }		// static 멤버함수
//};
//int Num::praaa = 20;		// static은 클래스외부에서 반드시 초기화, 클래스명으로 접근
//int Num::uraaa = 30;	

//int main() {
//	namespace myin = mystd::mystdin;
//	Num aob;
//	cout << mystd::a << endl;
//	cout << mystd::mystdin::a << endl;
//	cout << ::a << endl;			// global(30)
//	cout << aob.a << endl;			// error. a는 private변수이므로 클래스내에서만 접근가능
//	cout << aob.get_aaa() << endl;
//	cout << myin::a << endl;
//	Num::praaa;			// error(private)
//	Num.praaa;			// error(static->클래스명으로 호출)
//	Num::uraaa;			// 가능
//	Num.uraaa;			// error(static->클래스명으로 호출)
//
//	getchar();
//	return 0;
//}

namespace carPark {
	class Car {
	private:
		int power;
		int gas;
		int brake;
	public:
		Car(int _pow = 10, int _gas = 10, int _br = 10) : power(_pow), gas(_gas), brake(_br) {}
		~Car() {}
		void view() { cout << power << ", " << gas << ", " << brake << endl; }
	};
}
//
//using namespace carPark;
//int main() {
//	Car ob0, ob1(200), ob2(200, 30), ob3(200, 30, 40);
//	Car arr_c[] = { ob0, ob1, ob2, ob3 };		
//	for (Car c : arr_c) c.view();
//
//	Car **dim2 = new Car *[2];			// 2차원 배열 생성
//	for (size_t i = 0; i < 2; i++)
//		dim2[i] = new Car[3];
//
//	for (size_t i = 0; i < 2; i++)		// 2차원 배열 해제
//		delete[] dim2[i];
//	delete[] dim2;
//
//	getchar();
//	return 0;
//}

#include <time.h>
#include <iomanip>

class Matrix {
private:
	int rows;
	int cols;
	int **mat;
	const int cnt;	// const 멤버변수는 반드시 "생성자"의 초기화섹션에서 초기화가 이루어져야 한다.
public:
	Matrix(int _rows, int _cols) : rows(_rows), cols(_cols), cnt(0) {		
		mat = new int *[rows];
		for (size_t i = 0; i < rows; i++)
			mat[i] = new int[cols];
	}
	
	~Matrix() {
		for (size_t i = 0; i < rows; i++)
			delete[] mat[i];
		delete[] mat;
	}

	int& element(int _row, int _col) const { return mat[_row][_col]; }
	int getRows() const { return rows; }
	int getCols() const { return cols; }
	void print() const {
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++)
				cout << setw(3) << mat[i][j] << " ";
			cout << endl;
		}
	}

	void setRand() {
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < rows; i++) 
			for (size_t j = 0; j < cols; j++)
				mat[i][j] = rand() % 100 + 1;
	}

	int maxPixel() {
		int max = mat[0][0];
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++)
				if (max < mat[i][j]) max = mat[i][j];
		}
		return max;
	}
};

//
//int main() {
//	Matrix mat(110, 55);
//
//	mat.setRand();
//	mat.print();
//	cout << endl;
//	cout << "mat[선애][바보]: " << mat.element(3, 4) << endl << endl;
//	cout << "행복: " << mat.getRows() << ", 열라면: " << mat.getCols() << endl;
//	cout << "최대값: " << mat.maxPixel() << endl;
//	cout << "동열이가 한거임" << endl;
//
//	getchar();
//	return 0;
//} 

class Vector {
private:
	int count;
	int *vct;
public:
	Vector(int _count = 10) : count(_count), vct(new int[count]) {}
	~Vector() { delete[] vct; }

	Vector(const Vector& cp) {						// copy constructor
		count = cp.count;							// 복사생성자의 가장 큰 필요의 이유: 내부에 동적할당관련한 멤버변수가 있기때문
		vct = new int[count];
	/*	for (size_t i = 0; i < cp.count; i++)
			vct[i] = cp.vct[i];*/
		memcpy(vct, cp.vct, sizeof(int)*count);		// 메모리복사
	}

	Vector& operator = (const Vector& right) {		// operator =
		if (this != &right) return *this;			// Vector객체간의 =연산이 정의되지 않았으므로 포인터로 비교해야함
		if (count != right.count) {
			delete[] vct;
			count = right.count;
			vct = new int[count];
		}

		for (size_t i = 0; i < count; i++)
			vct[i] = right.vct[i];
		return *this;
	}

	void randset_vector() {
		for (size_t i = 0; i < count; i++)
			vct[i] = rand() % 100 + 1;
	}

	void view_vector() {
		for (size_t i = 0; i < count; i++)
			cout << vct[i] << " ";
		cout << endl;
	}

};

//int main() {
//	Vector vt;
//
//	srand((unsigned)time(NULL));
//	vt.randset_vector();
//	vt.view_vector();
//
//	Vector vt2(vt);		// copy constructor
//	vt2.view_vector();
//
//	Vector vt3(5);
//	vt3.randset_vector();
//	vt3.view_vector();
//
//	Vector vt4;
//	vt4 = vt3;			// operator = 
//	vt3.view_vector();
//
//	Vector vt5 = vt3;	// copy constructor
//	vt5.view_vector();
//
//	getchar();
//	return 0;
//}

#include <string.h>
#pragma warning(disable : 4996)

class Engine {
private:
	int horsePower;
	int getHP() const { return horsePower; }
public:
	Engine(int hp) {
		if (120 <= hp && hp <= 290) horsePower = hp;
		else horsePower = -1;
	}
	~Engine() {}

	int realgetHP() const { return getHP(); }
	/*int getHp() const { return horsePower; }*/

	virtual string view() const { return ("HP: " + horsePower); }
};

class InterCoolerEngine : public Engine {
protected:
	char cooler[5];
public:
	InterCoolerEngine(int hp, const char *_cooler) : Engine(hp) { strcpy(cooler, _cooler); }
	~InterCoolerEngine() {}

	InterCoolerEngine(const InterCoolerEngine& cp) : Engine(cp.realgetHP()) { strcpy(cooler, cp.cooler); }
	string getCooler() const { return cooler; }

	void view_p() const { cout << "InterCoolerEngine" << endl; }
	string view() const { return (Engine::view() + ", Cooler: " + cooler); }	// 오버라이딩에 의해 무효화된 Engine::view()를 호출
};

class TurboEngine : public InterCoolerEngine {
private:
	char turboCharger;
public:
	TurboEngine(int hp, const char *_cooler, char _charger)
		: InterCoolerEngine(hp, _cooler), turboCharger(_charger) {}
	~TurboEngine() {}
	string view() const { return (InterCoolerEngine::view() + ", Charger: " + turboCharger); }
};

ostream& operator << (ostream& out, string str) {
	out << str;
	return out;
}
//
//int main() {
//	Engine eng1(150);
//	InterCoolerEngine eng2(270, "박"), eng3(eng2);
//	TurboEngine eng4(290, "선애", 'B');
//
//	Engine *arr[] = { &eng1, &eng2, &eng3, &eng4 };
//
//	//eng2.view();			// InterCoolerEngine::view() 호출 => "상속"자체로 알아서 자기꺼 찾아감
//
//	for (Engine *pe : arr) 	// virtual이 필요한 경우는, 이렇게 하나의 타입으로 여러가지 명시하고 싶을때!
//		cout << pe->view() << endl;
//	
//	getchar();
//	return 0;
//}


// 오버라이딩에 의해 무효화된 부모의 멤버함수 사용하기 = > Engine::view();
// 순수가상함수가 하나라도 있으면 객체 생성 X
// (C c1(c2);) == (C c1 = c2;) => (int a = 10;) == (int a(10);)
// 없으면 컴파일러가 디폴트로 만들어주는(즉, 기본적으로 반드시 있어야 하는) 함수 => 1) 디폴트생성자 2) 복사생성자 3) 대입연산자 4) 소멸자

class AAA {
	int a;
public:
	AAA(int _a = 0) : a(_a) {}					// default constructor
	~AAA() {}									// destructor	
	void setA(int _data) { a = _data; }			
	AAA(const AAA& cp) { a = cp.a; }			// copy contructor	
	AAA& operator = (const AAA& right) { a = right.a; }	// assign operator
};

class BBB : public AAA{
	int b;
public:
	BBB(int _b = 0) : AAA(), b(_b) {}			
	~BBB() {}
	void set_b(int _data) { b = _data; }
	BBB(const BBB& cp) { b = cp.b; }
	BBB& operator = (const BBB& right) { b = right.b; }
};

int main() {
	BBB ob1(20), ob2(ob1), ob3 = ob2, ob4;		// ob2, ob3는 copy constructor
	ob4 = ob1;		// ob4는 assign operator

	return 0;
}


