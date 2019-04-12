#pragma once
typedef struct TAG {
	int fir;
	int sec;
} TAG;			// 이것도 구조체의 선언일뿐 실제 메모리에 올라가는 정의는 아니므로 헤더에 선언

TAG put(int a, int b);
