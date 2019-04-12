#include <stdio.h>
#pragma warning(disable : 4996)

int check(int m);

int main() {
	int money;
	char menu_name[][10] = { "물", "콜라", "환타", "사이다", "비타민", "울트라" };
	int menu[] = { 800, 1000, 1100, 1200, 1500, 2000 };

	while (1) {
		printf("동전을 넣으시오(1000, 500, 100만 가능): ");
		scanf("%d", &money);

		if (check(money) > 0) break;
	}
	
	while (1) {
		int flag = 0;
		printf("\n총금액: %d\n\n", money);

		// print menu
		for (int i = 0; i < 6; i++) {
			if (menu[i] <= money) {
				flag = 1;
				printf("%d. %s %d원\n", i + 1, menu_name[i], menu[i]);
			}
		}

		if (!flag) 
			printf("잔액부족\n");

		int m;
		printf("\n음료선택 또는 금액추가: ");
		scanf("%d", &m);

		// choose
		if (m >= 1 && m <= 10) {
			printf("%d. %s %d 선택\n", m, menu_name[m-1], menu[m - 1]);
			money -= menu[m-1];
		}
		// add money
		else {
			if (check(m) > 0) 
				money += m;
		}
	}

	return 0;
}

int check(int m) {
	if (m != 1000 && m != 500 && m != 100) {
		printf("잘못된 금액입니다.\n");
		return -1;
	}
	else return m;
}