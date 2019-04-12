#include <stdio.h>

#pragma warning(disable : 4996)

#define QUEUE_SIZE 5

typedef struct _queue {
	int front;
	int rear;
	int q_data[QUEUE_SIZE];
} Queue;

void init_queue(Queue **q) {
	*q = (Queue *)malloc(sizeof(Queue));
	(*q)->front = (*q)->rear = 0;
}

void enqueue(Queue *q, int data) {
	if ((q->rear + 1) % QUEUE_SIZE == q->front) {			// 한자리 비워서 
		printf("full\n");
		return;
	}
	(q->q_data)[q->rear] = data;				// 넣고 증가시키기(속도)
	q->rear = ++(q->rear) % QUEUE_SIZE;
}

int dequeue(Queue *q) {
	int save;
	if (q->front == q->rear) { /*printf("empty\n");*/ return -1; }
	save = q->front;
	q->front = ++(q->front) % QUEUE_SIZE;
	return (q->q_data)[save];
}

void print_q(Queue *q) {
	int f = q->front;
	while (f != q->rear) {
		printf("%d ", (q->q_data)[f]);
		f = ++f % QUEUE_SIZE;
	}
}

int main() {
	//Queue *qs[2][10] = { 0, };
	//int num[10], r1, r0;

	//// initiation
	//for (int i = 0; i < 2; i++)
	//	for (int j = 0; j < 10; j++)
	//		init_queue(&qs[i][j]);

	//printf("숫자: ");
	//for (int i = 0; i < 10; i++)
	//	scanf("%d", &num[i]);

	//for (int i = 0; i < 10; i++) {
	//	r0 = num[i] % 10;
	//	enqueue(qs[0][r0], num[i]);
	//}

	//for (int i = 0; i < 10; i++) {
	//	int v = dequeue(qs[0][i]);
	//	if (v > 0) {
	//		r1 = v / 10;
	//		enqueue(qs[1][r1], v);
	//	}
	//}

	//printf("\n[기수정렬] ");
	//for (int i = 0; i < 10; i++)
	//	print_q(qs[1][i]);
	//printf("\n\n");

	//getchar("");
	//getchar("");

	// -------- n자릿수 정렬

	Queue *qs[10];
	int num[10];
	int d, r0;
	// initiation
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			init_queue(&qs[i][j]);

	printf("자릿수: ");
	scanf("%d", &d);
	printf("숫자: ");
	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);

	while (d-- > 0) {
		for (int i = 0; i < 10; i++) {
			r0 = num[i] % 10;
			enqueue(qs[r0], num[i]);
		}

		for (int i = 0; i < 10; i++) {
			int v = dequeue(qs[i]);
			if (v > 0)
				num[i] = v;
		}
	}

	printf("\n[기수정렬] ");
	for (int i = 0; i < 10; i++)
		printf("%d ", num[i]);
	printf("\n\n");

	getchar("");
	getchar("");


	return 0;
}

