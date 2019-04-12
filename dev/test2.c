#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int arr[45];
	int rnum;
	int limit = 44;

	for (int i = 0; i < 45; i++)
		arr[i] = i + 1;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		rnum = rand() % 45;
		printf("\n%d %d\n", rnum, arr[rnum]);
		arr[rnum] = arr[limit--];
		for (int j = 0; j < limit; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}

	return 0;
}