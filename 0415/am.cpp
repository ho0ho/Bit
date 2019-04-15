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

//ostream& operator << (ostream& out, string str) {
//	out << str;
//	return out;
//}
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
	int getA() const { return a; }
	virtual int get() const { return getA(); }
	AAA(const AAA& cp) { a = cp.a; }			// copy contructor	
	AAA& operator = (const AAA& right) { a = right.a; return *this; }	// assign operator
};

class BBB : public AAA{
	int b;
public:
	BBB(int _a = 0, int _b = 0) : AAA(_a), b(_b) {}			
	~BBB() {}
	void setB(int _data) { b = _data; }
	int getB() const { return b; }
	int get() const { return getB(); }
	BBB(const BBB& cp) { b = cp.b; }
	BBB& operator = (const BBB& right) { 
		AAA::operator = (right);  // a = right.a;
		b = right.b; 
		return *this; 
	}
};
//
//int main() {
//	BBB ob1(20, 5), ob2(ob1), ob3 = ob2, ob4;		// ob2, ob3는 copy constructor
//	ob4 = ob1;		// ob4는 assign operator
//
//	AAA *p[] = { &ob1, &ob2, &ob3, &ob4 };
//	for (AAA *a : p)
//		cout << a->get() << endl;
//
//	getchar();
//	return 0;
//}

ostream& operator << (ostream& out, string str) {
	for (int i = 0; i < str.length(); i++)
		out << str[i];
	return out;
}

class Person {
private:
	string perName;
	int perAge;
public:
	Person() {}
	Person(string _name, int _age) : perName(_name), perAge(_age) {}
	~Person() {}

	Person& operator = (const Person& right) {
		perName = right.perName;
		perAge = right.perAge;
	}

	string getName() const { return perName; }
	int getAge() const { return perAge; }
	void setName(string name_new) { perName = name_new; }
	void setAge(int age) { perAge = age; }
	virtual void info() const {
		cout << perName << "(" << perAge << ")";
	}

};

class Subject {
protected:
	string subjName;
	int subjScore;
public:
	Subject() {}
	Subject(string _sName, int _sScore) : subjName(_sName), subjScore(_sScore) {}

	void setScore(int score) { subjScore = score; }
	int getScore() const { return subjScore; }

	void info() const { cout << getScore() << "\t"; }
};

class Student : public Person {
private:
	const int id;
	int totalScore;
	int average;
	Subject *p_subj;
public:
	Student(string name, int age, int _id) 
		: Person(name, age), totalScore(0), average(0), p_subj(new Subject[3]), id(_id) {}
	~Student() { delete[] p_subj; }

	void setScore(int *_score) {
		for (size_t i = 0; i < 3; i++) {
			p_subj[i].setScore(_score[i]);
			totalScore += _score[i];
		}
		average = totalScore / 3;
	}

	void editName(string name_new) { setName(name_new); }
	void editAge(int age_new) { setAge(age_new); }
	int getId() const { return id; }
	/*int getTotalScore() const { return totalScore; }
	int getAverage() const { return average; }*/
	void info() const {
		cout << "[" << getId() << "] ";
		Person::info();
	}
	void infoAll() const {
		info();
		cout << " ";
		for (size_t i = 0; i < 3; i++)
			p_subj[i].info();
		cout << totalScore << "\t" << average;
	}
};

class GradeHandler {
private:
	string university;
	Student **s_arr;
	int cnt_s;
	int size;
public:
	GradeHandler(string _university = "blank", int size = 10)
		: university(_university), size(size), s_arr(new Student *[size]), cnt_s(0) {}
	~GradeHandler() { delete[] s_arr; }

	void addStudent(string name, int age, int id) {
		s_arr[cnt_s++] = new Student(name, age, id);
		Student *s = s_arr[cnt_s - 1];
		cout << "[" << s->getId() << "] " << s->getName() << "(" << s->getAge() << ")"  << " 학생이 추가됨" << endl;
	}

	/*void addScore(int id, int *score) {
		Student *f = find_id(id);
		f->setScore(score);
	}*/

	void editStudent(string name, int id, string name_new, int age_new) {
		Student *s = find(name, id);
		if (!s) cout << "존재하지 않는 이름입니다." << endl;
		else {
			Person p(s->getName(), s->getAge());
			s->editName(name_new);
			s->editAge(age_new);
			
			cout << "[" << s->getId() << "] ";
			p.info();
			cout << "이 ";
			s->info();
			cout << "로 수정됨" << endl;
		}
	}

	void deleteStudent(string name, int id) {
		Student *s = find(name, id);
		// 학번에 [*]표시
	}

	Student *find_id(int id) {
		size_t i;
		for (i = 0; i < cnt_s; i++)
			if (s_arr[i]->getId() == id) break;
		if (i >= cnt_s) return NULL;
		return s_arr[i];
	}

	Student *find(string name, int id) {
		size_t i;
		for(i = 0; i < cnt_s; i++)
			if ((s_arr[i])->getName() == name && s_arr[i]->getId() == id) 
				break;
		if (i >= cnt_s) return NULL;
		return s_arr[i];
	}

	void toPrintAll() {
		for (size_t i = 0; i < cnt_s; i++) {
			s_arr[i]->infoAll();
			cout << endl;
		}
	}


};

int main() {
	int managedId = 0;
	int cnt_s;
	char university[10];

	cout << "학교명과 학생수를 입력하시오" << endl;
	cout << "학교명: ";
	cin >> university;
	cout << "학생수: ";
	cin >> cnt_s;

	GradeHandler g(university, cnt_s);

	int comm, comm2;
	
	char name_s[10], name_new[10];
	int age_s, id_s, age_new, score;
	int sScore[3];
	string subjName[] = { "국어", "영어", "수학" };
	string menu_student[] = { "학생추가", "학생수정", "학생삭제" };
	string menu_score[] = { "성적출력", "성적추가" };
	Student *st = NULL;

	cout << "--------------------------------" << endl;
	cout << "1. 학생관리" << endl;
	cout << "2. 성적관리" << endl;
	cout << "[선택] ";
	cin >> comm;

	char cont[2] = "y";
	while (comm != 'q') {
		switch (comm) {
		case 1:
			cout << "--------------------------------" << endl;
			cout << "1. 학생관리" << endl;
			for (size_t i = 0; i < 3; i++)
				cout << comm << "-" << i + 1 << ". " << menu_student[i] << endl;
			cout << "[선택] ";
			cin >> comm2;
			switch (comm2) {
			case 1:
				while (cont[0] != 'n') {
					cout << "[학생 추가] 이름: ";
					cin >> name_s;
					cout << "[학생 추가] 나이: ";
					cin >> age_s;
					g.addStudent(name_s, age_s, managedId++);
					cout << "Continue?(y/n) ";
					cin >> cont;
				}
				cout << "------ 추가작업 완료 ------\n\n";
				break;
			case 2:
				cout << "[" << menu_student[comm2 - 1] << "] 이름: ";
				cin >> name_s;
				cout << "[학생 수정] 학번: ";
				cin >> id_s;
				cout << "[학생 수정] 변경할 이름: ";
				cin >> name_new;
				cout << "[학생 수정] 변경할 나이: ";
				cin >> age_new;
				g.editStudent(name_s, id_s, name_new, age_new);
				break;
			case 3:
				cout << "[학생 삭제] 이름: ";
				cin >> name_s;
				cout << "[학생 삭제] 학번: ";
				cin >> id_s;
				g.deleteStudent(name_s, id_s);
				break;
			default:
				cout << "wrong comm2" << endl;
				break;
			}
			break;
		case 2:
			cout << "2. 성적관리" << endl;
			for (size_t i = 0; i < 2; i++)
				cout << comm << "-" << i + 1 << ". " << menu_score[i] << endl;
			cout << "[선택] ";
			cin >> comm2;
			switch (comm2) {
			case 1:
				// print
				cout << " 학번\t이름(나이)\t국어\t영어\t수학\t총점\t평균\n";
				g.toPrintAll();
				break;
			case 2:
				cout << "[성적 추가] 학번: ";
				cin >> id_s;
				st = g.find_id(id_s);
				if (!st) {
					cout << "wrong id\n";
					break;
				}
				for (size_t i = 0; i < 3; i++) {
					cout << subjName[i] << "점수: ";
					cin >> sScore[i];
				}
				st->setScore(sScore);
				st->infoAll();
				break;
			}
			break;
		default:
			cout << "wrong input\n";
			break;
		}

		cout << "\n\n--------------------------------" << endl;
		cout << "1. 학생관리" << endl;
		cout << "2. 성적관리" << endl;
		cout << "[선택] ";
		cin >> comm;
	}




	return 0;
}
