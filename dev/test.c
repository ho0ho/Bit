#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable: 4996)

int main() {
	int ans = 87;
	int age;
	int cnt = 0;
	int high = 100, low = 0;

	while (1) {
		printf("나이를 입력하세요: ");
		scanf("%d", &age);

		cnt++;
		if (low > age) 
			printf("왜 더 적은 값을 입력하셨습니까?\n");
		else if (high < age) 
			printf("왜 더 많은 값을 입력하셨습니까?\n");
		else {
			if (age < ans) {
				if (low < age) low = age;
				printf("그보단 만치요\n");
			}
			else if (age > ans) {
				if (high > age) high = age;
				printf("그보단 적지요\n");
			}
			else {
				printf("맞습니다.\n%d번만에 맞추셨습니다.\n", cnt);
				break;
			}
		}
	}
	
	return 0;
}