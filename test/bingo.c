#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

#pragma warning(disable: 4996)

void print(int(*a)[5], int(*b)[5]);
void make(int(*arr)[5], int *ch);
int check(int(*arr)[5], int c);
int isBingo(int(*arr)[5], int i, int j);

#define T_USER 1
#define T_COM 0

int main() {
	int playerValue;
	char *player[] = { "USER", "COM" };
	int ch_user, ch_com;
	int check_u[25] = { 0, }, check_c[25] = { 0, };
	int user[5][5];
	int com[5][5];

	srand((unsigned)time(NULL));
	make(user, check_u);
	make(com, check_c);

	int t = T_USER;
	while (1) {
		// print
		print(user, com);

		// input
		printf("\n\n%s's turn : ", player[t]);

		if (t == T_USER) {
			scanf("%d", &playerValue);
			assert(playerValue >= 1 && playerValue <= 25);
		}
		else { // T_COM
			playerValue = rand() % 25 + 1;
			printf("%d\n", playerValue);
		}

		// check X
		ch_user = check(user, playerValue);
		ch_com = check(com, playerValue);
		if (ch_user) {
			print(user, com);
			printf("\nBingo! %s Win!\n\n", player[t]);
			break;
		}
		else if (ch_com) {
			print(user, com);
			printf("\nBingo! %s Win!\n\n", player[t]);
			break;
		}

		print(user, com);

		t = T_COM;
	}

	return 0;
}

void print(int(*a)[5], int(*b)[5]) {
	system("cls");
	printf("\tUSER\t\t\t\tCOM\n\n");
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			if (a[i][j] == 88)
				printf("%2c ", 'X');
			else printf("%2d ", a[i][j]);
		}

		printf("\t\t\t");

		for (size_t j = 0; j < 5; j++) {
			if (b[i][j] == 88)
				printf("%2c ", 'X');
			else printf("%2d ", b[i][j]);
		}
		printf("\n");
	}
}

int check(int(*arr)[5], int c) {
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			if (arr[i][j] == c) {
				arr[i][j] = 'X';
				if (isBingo(arr, i, j)) return 1;
				else return 0;
			}
		}
	}
}

int isBingo(int(*arr)[5], int i, int j) {
	int check = 0;
	if (i == j) {
		for (int k = 0; k < 5; k++) {
			if (/*k != i &&*/ arr[k][k] != 'X')
				break;
			check++;
		}
		if (check == 5) return 1;
	}
	if (i + j == 4) {
		check = 0;
		for (int k = 0; k < 5; k++) {
			if (/*k != i &&*/ arr[k][4 - k] != 'X')
				break;
			check++;
		}
		if (check == 5) return 1;
	}

	check = 0;
	for (int r = 0; r < 5; r++) {
		if (arr[r][j] != 'X')
			break;
		check++;
	}

	if (check == 5)
		return 1;
	else {
		check = 0;
		for (int c = 0; c < 5; c++) {
			if (arr[i][c] != 'X')
				break;
			check++;
		}

		if (check == 5)
			return 1;
		else return 0;
	}
}

void make(int(*arr)[5], int *ch) {
	int r;
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			r = rand() % 25 + 1;
			while (ch[r - 1] == 1)
				r = rand() % 25 + 1;
			ch[r - 1] = 1;
			arr[i][j] = r;
		}
	}
}