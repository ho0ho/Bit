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
		printf("���̸� �Է��ϼ���: ");
		scanf("%d", &age);

		cnt++;
		if (low > age) 
			printf("�� �� ���� ���� �Է��ϼ̽��ϱ�?\n");
		else if (high < age) 
			printf("�� �� ���� ���� �Է��ϼ̽��ϱ�?\n");
		else {
			if (age < ans) {
				if (low < age) low = age;
				printf("�׺��� ��ġ��\n");
			}
			else if (age > ans) {
				if (high > age) high = age;
				printf("�׺��� ������\n");
			}
			else {
				printf("�½��ϴ�.\n%d������ ���߼̽��ϴ�.\n", cnt);
				break;
			}
		}
	}
	
	return 0;
}