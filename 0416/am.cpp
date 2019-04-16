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
	Number(int f = 0, int s = 0) : size(10), arr(new int[10]), fir(f), sec(s) { }
	~Number() {}

	Number(const Number& cp) { fir = cp.fir; sec = cp.sec; }

	Number& operator = (const Number &right) { fir = right.fir; sec = right.sec; return *this; }
	bool operator == (const Number& right) { return (fir == right.fir && sec == right.sec); }		// overloading(member method)
	int& operator [] (int idx) { return arr[idx]; }			// [] ������ �����ε� => ����θ� ���ǰ���
	int operator [] (int idx) const { return arr[idx]; }	// ?
	const Number operator + (int num) const {		// a + 2 = b; �̷��� ���X (-> const����)
		//Number n(fir + num, sec + num);				// �ӽð�ü n�� ����ϹǷ� �����ؼ� �Ѱܾ� ��(&���� ����)
		return Number(fir + num, sec + num);
	}
	int operator() (int dx, int dy) { fir += dx; sec += dy; return (fir + sec); }
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

//int main() {
//	Number a(10, 20), b(20, 40), c(a);			// copy constructor
//	if (a == b) cout << "true" << endl;
//	else cout << "false" << endl;
//
//	a = a + 5;			// ����Լ� operator + () ȣ��
//	cout << a.gettor_fir() << ", " << a.gettor_sec() << endl;
//
//	a = 5 + a;			// �����Լ� operator + () ȣ��
//	cout << a.gettor_fir() << ", " << a.gettor_sec() << endl;
//
//	cout << int(a) << endl;
//
//	b[0] = 3;
//	cout << b[0] << endl;
//
//	cout << a;
//
//	cout << a(55, 44) << endl;
//
//	getchar();
//	return 0;
//}

class AAA {
	int num;
public:
	AAA(int num = 0) : num(num) {}
	~AAA() {}

	int getNum() const { return num; }
	friend ostream& operator << (ostream& out, const AAA& a);
	friend class Smart;

};

class Smart {
	AAA *p;
public:
	Smart(AAA *p) : p(p) {}			// ���� �Ҵ�
	~Smart() {}

	AAA& operator *() { return *p; }
	AAA& operator *() const { return *p; }
	AAA* operator->() {	return p; }

};

ostream& operator << (ostream& out, const AAA& a) {
	out << a.num;		// �ι�° operator *() ȣ��(const)
	return out;
}

//int main() {
//	Smart ob(new AAA(10));			// ob.p = new aaa(10);
//	*ob = 10;			// smart��ü�� aaa��ü�� ���� �ڵ鷯����(smart��ü�� aaa��ü�� ��Ʈ��)
//	
//	//cout << ob;
//	//cout << (ob.operator->()).getnum() << endl;
//	cout << *ob << endl;
//	cout << ob->getNum() << endl;
//	return 0;
//}

template <typename T>
T add(T v1, T v2) {
	return v1 + v2;
}


//int main() {
//	cout << add<int>(3, 5) << endl;
//	cout << add<double>(3.0, 11.4) << endl;
//
//	getchar();
//	return 0;
//}

#define SIZE 10
#pragma warning(disable : 4996)

class Weapon {
public:
	char wpName[SIZE];
public:
	Weapon(const char *wp) { strcpy(wpName, wp); }
};

class Glove {
private:  
	char gvName[SIZE];
	Weapon *weapon;
public:
	Glove(const char *gv, const char *wp)   {
		strcpy(gvName, gv);
		weapon = new Weapon(wp);
	}
	Weapon *operator -> () {
		return weapon;
	}
	friend class Soldier;		
};

class Soldier{
private:
	char sdName[SIZE];
	Glove *glove;
public:
	Soldier(const char *sd, const char *gv, const char *wp) {
		strcpy(sdName, sd);
		glove = new Glove(gv, wp);
		//strcpy(gvName, gv);
		//strcpy(wpName, wp);
	}
	~Soldier() {}

	Weapon *operator ->(/*const char *name*/) {
		return glove->weapon;			// friend class Soldier�վ����
	}

	char *operator * () {
		return sdName;
	}
};

//int main() {
//	Soldier sd1("���̾��", "ö�尩", "��Ư�޷�����");
//	cout << sd1->wpName << endl;
//	/*cout << sd1.operator->() << endl;*/
//
//	getchar();
//	return 0;
//}

class Tel {
private:
	string name;
	int phone;
public:
	friend class TelHandler;
	Tel() {}
	Tel(string _name, int _phone) : name(_name), phone(_phone) {}
	int& operator [] (string name) {
		return phone;
	}
	//int& operator [] (string name) const {
	//	return phone;
	//}

};

class TelHandler {
private:
	Tel *tels;
	int sz_tel;
	static int pos;
public:
	TelHandler(int size) : sz_tel(size) { tels = new Tel[sz_tel]; }

	void addTel(string name, int phone) {
		tels[pos++] = Tel(name, phone);
	}
	
	int& operator [] (string name) {
	/*	int id = find(name);
		if (id >= sz_tel) cout << "not exist" << endl;*/
		return (*tels)[name];
	}

	int& operator [] (string name) const {
		return (*tels)[name];
	}

	int find(string name) {
		size_t i;
		for (i = 0; i < sz_tel; i++)
			if (tels[i].name == name) break;
		return i;
	}

};

int TelHandler::pos = 0;

//int main() {
//	
//	TelHandler thd(21);
//	string names[] = { "����", "���ؿ�", "�պ���", "�����", "���α�", "����", "�����", "�ڼ���", "�ڼ���",
//	"�ŵ���", "�̰��", "������", "Ȳ����", "������", "��ȣ��", "���϶�", "�̽¿�", "������", "������", "������"};
//	int phones[] = { 111, 666, 909, 222, 808, 789, 404, 303, 987, 333, 202, 555, 456, 654, 777, 101, 999, 123, 321, 707 };
//
//	for (size_t i = 0; i < 20; i++)
//		thd.addTel(names[i], phones[i]);
//
//	thd["�ڼ���"] = 100;
//	cout << thd["�ڼ���"] << endl;
//
//	return 0;
//}

#include <cstdlib>

class Point;
typedef Point *PP_T;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {  }
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator << (ostream& out, const PP_T& pp);
};

ostream& operator << (ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

ostream& operator << (ostream& out, const PP_T& pp) {
	out << '[' << pp->xpos << ", " << pp->ypos << ']' << endl;
	return out;
}

class PointHandler {
private:
	PP_T * arr;
	int arrlen;
	PointHandler(const PointHandler& arr) { }
	PointHandler& operator=(const PointHandler& arr) { }
public:
	PointHandler(int len) : arrlen(len) { arr = new PP_T[len]; }
	PP_T& operator[] (int idx) { return arr[idx]; }
	PP_T operator[] (int idx) const { return arr[idx]; }
	int GetArrLen() const { return arrlen; }
	~PointHandler()	{ delete[] arr; }
};

//int main(void)
//{
//	PointHandler arr(3);
//	arr[0] = new Point(3, 4);
//	arr[1] = new Point(5, 6);
//	arr[2] = new Point(7, 8);
//	for (int i = 0; i < arr.GetArrLen(); i++)
//		cout << arr[i];
//		/*cout << *(arr[i]);*/ //cout<<arr[i]�� �Ǿ ���� ����̵ǵ��� << �����ڸ�  �����ε� �Ͻÿ�
//	delete arr[0];
//	delete arr[1];
//	delete arr[2];
//
//	getchar();
//	return 0;
//}

#define SIZE 50

#include <cstring>
class String {
private:
	int len;
	char *str;
public:
	String() : len(0) { str = new char[SIZE]; }
	String(const char *s) {	
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	String(const String& s) {
		len = s.len;
		str = new char[len];
		strcpy(str, s.str);
	}
	~String() { delete[] str; }

	String& operator = (const String& s) {
		if (this == &s) return *this;
		if (s.len != len) {
			len = s.len;
			delete[] str;
			str = new char[len];
		}
		strcpy(str, s.str);
		return *this;
	}

	String& operator += (const String& s) {
		len += s.len;
		char *tmp = new char[len];
		strcpy(tmp, str);
		strcat(tmp, s.str);
		delete[] str;
		str = tmp;
		return *this;
	}

	bool operator == (const String& s) {
		if (len != s.len) return false;
		return strcmp(str, s.str);
	}

	const String operator + (const String& s) {
		String cat_s(*this);
		cat_s += s;
		return cat_s;
	}

	char& operator [] (int idx) { return str[idx]; }	
	friend ostream& operator << (ostream& out, const String& s);
	friend istream& operator >> (istream& in, String& s);
};

ostream& operator << (ostream& out, const String& s) {
	/*char *f = s.str;
	while (*f)
		out << *f++;*/
	out << s.str;
	return out;
}

istream& operator >> (istream& in, String& s) {
	char f[SIZE];
	in >> f;
	s = String(f);
	return in;
}

int main() {
	String str1 = "I like ";
	String str2 = "String class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	String str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;

	getchar();
	return 0;
}
