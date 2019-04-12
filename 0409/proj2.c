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

	// -------- n자릿수 정렬

	Queue *qs[10];
	int num[10];
	int d, r0;
	// initiation
	for (int i = 0; i < 10; i++)
		init_queue(&qs[i]);

	printf("자릿수: ");
	scanf("%d", &d);
	printf("숫자: ");
	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);


	int gg = d;
	int save_d = d;
	while (--d > 0) {
		for (int i = 0; i < 10; i++) {
			int save = num[i];
			int t = num[i], g;
			while (gg++ <= save_d) {
				g = t;
				t /= 10;
			}
			r0 = g-- % 10;
			enqueue(qs[r0], num[i]);
		}

		for (int i = 0, j = 0; i < 10 && j < 10; i++ ) {
			while (qs[i]->front != qs[i]->rear) {
				int v = dequeue(qs[i]);
				num[j++] = v;
			}
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

