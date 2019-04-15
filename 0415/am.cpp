#include <iostream>
using namespace std;

//namespace mystd {
//	int a = 10;
//	namespace mystdin {
//		int a = 20;
//	}
//}
//
//int a = 30;				// global(�ܺο��� extern���� ��밡��)
//static int a = 40;		// static + global (�� ���Ͼȿ����� ��밡���� ��������, �̰� �ܺ����Ͽ��� extern���ε� ���Ұ�)
//class Num {
//private:
//	int a;					// Num n; n.a�� ���(Ŭ���� �ܺο����� ���x, private)
//	static int praaa;		// static ����Լ��� ��밡���� ����(private) Ŭ���� �ؿ��� �ʱ�ȭ�ؾ���. Num::praaa�� ���
//public:
//	static int uraaa;
//	Num(int a = 0) : a(a) {}
//	void set_aaa(int aaa) { this->a = aaa; }
//	int get_aaa() const { return this->a; }		// static ����Լ�
//};
//int Num::praaa = 20;		// static�� Ŭ�����ܺο��� �ݵ�� �ʱ�ȭ, Ŭ���������� ����
//int Num::uraaa = 30;	

//int main() {
//	namespace myin = mystd::mystdin;
//	Num aob;
//	cout << mystd::a << endl;
//	cout << mystd::mystdin::a << endl;
//	cout << ::a << endl;			// global(30)
//	cout << aob.a << endl;			// error. a�� private�����̹Ƿ� Ŭ������������ ���ٰ���
//	cout << aob.get_aaa() << endl;
//	cout << myin::a << endl;
//	Num::praaa;			// error(private)
//	Num.praaa;			// error(static->Ŭ���������� ȣ��)
//	Num::uraaa;			// ����
//	Num.uraaa;			// error(static->Ŭ���������� ȣ��)
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

using namespace carPark;
int main() {
	Car ob0, ob1(200), ob2(200, 30), ob3(200, 30, 40);
	Car arr_c[] = { ob0, ob1, ob2, ob3 };		
	for (Car c : arr_c) c.view();

	Car **dim2 = new Car *[2];			// 2���� �迭 ����
	for (size_t i = 0; i < 2; i++)
		dim2[i] = new Car[3];

	for (size_t i = 0; i < 2; i++)		// 2���� �迭 ����
		free(dim2[i]);
	free(dim2);

	getchar();
	return 0;
}
