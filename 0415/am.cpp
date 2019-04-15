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
		count = cp.count;
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

int main() {
	Vector vt;

	srand((unsigned)time(NULL));
	vt.randset_vector();
	vt.view_vector();

	Vector vt2(vt);		// copy constructor
	vt2.view_vector();

	Vector vt3(5);
	vt3.randset_vector();
	vt3.view_vector();

	Vector vt4;
	vt4 = vt3;			// operator = 
	vt3.view_vector();

	Vector vt5 = vt3;	// copy constructor
	vt5.view_vector();

	getchar();
	return 0;
}
