#include <iostream>
using namespace std;

namespace mystd {
	int a = 10;
	namespace mystdin {
		int a = 20;
	}
}

int a = 30;				// global(�ܺο��� extern���� ��밡��)
static int a = 40;		// static + global (�� ���Ͼȿ����� ��밡���� ��������, �̰� �ܺ����Ͽ��� extern���ε� ���Ұ�)
class Num {
private:
	int a;					// Num n; n.a�� ���(Ŭ���� �ܺο����� ���x, private)
	static int praaa;		// static ����Լ��� ��밡���� ����(private) Ŭ���� �ؿ��� �ʱ�ȭ�ؾ���. Num::praaa�� ���
public:
	static int uraaa;
	Num(int a = 0) : a(a) {}
	void set_aaa(int aaa) { this->a = aaa; }
	int get_aaa() const { return this->a; }		// static ����Լ�
};
int Num::praaa = 20;		// static�� Ŭ�����ܺο��� �ݵ�� �ʱ�ȭ, Ŭ���������� ����
int Num::uraaa = 30;	

int main() {
	namespace myin = mystd::mystdin;
	Num aob;
	cout << mystd::a << endl;
	cout << mystd::mystdin::a << endl;
	cout << ::a << endl;			// global(30)
	cout << aob.a << endl;			// error. a�� private�����̹Ƿ� Ŭ������������ ���ٰ���
	cout << aob.get_aaa() << endl;
	cout << myin::a << endl;
	Num::praaa;			// error(private)
	Num.praaa;			// error(static->Ŭ���������� ȣ��)
	Num::uraaa;			// ����
	Num.uraaa;			// error(static->Ŭ���������� ȣ��)
	

	getchar();
	return 0;
}