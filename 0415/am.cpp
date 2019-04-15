#include <iostream>
using namespace std;

namespace mystd {
	int a = 10;
	namespace mystdin {
		int a = 20;
	}
}

int a = 30;				// global(외부에서 extern으로 사용가능)
static int a = 40;		// static + global (이 파일안에서만 사용가능한 전역변수, 이건 외부파일에서 extern으로도 사용불가)
class Num {
private:
	int a;					// Num n; n.a로 사용(클래스 외부에서는 사용x, private)
	static int praaa;		// static 멤버함수만 사용가능한 변수(private) 클래스 밑에서 초기화해야함. Num::praaa로 사용
public:
	static int uraaa;
	Num(int a = 0) : a(a) {}
	void set_aaa(int aaa) { this->a = aaa; }
	int get_aaa() const { return this->a; }		// static 멤버함수
};
int Num::praaa = 20;		// static은 클래스외부에서 반드시 초기화, 클래스명으로 접근
int Num::uraaa = 30;	

int main() {
	namespace myin = mystd::mystdin;
	Num aob;
	cout << mystd::a << endl;
	cout << mystd::mystdin::a << endl;
	cout << ::a << endl;			// global(30)
	cout << aob.a << endl;			// error. a는 private변수이므로 클래스내에서만 접근가능
	cout << aob.get_aaa() << endl;
	cout << myin::a << endl;
	Num::praaa;			// error(private)
	Num.praaa;			// error(static->클래스명으로 호출)
	Num::uraaa;			// 가능
	Num.uraaa;			// error(static->클래스명으로 호출)
	

	getchar();
	return 0;
}