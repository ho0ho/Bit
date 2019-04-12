#include <stdio.h>

// void(*signal(int signum, void(*handler)(int)))(int);
// void -> (int) -> * -> (int sn, void(*h)(int)) -> signal
// void (int) ������ �Լ��� ����Ű��(*) �Լ�������(�� �Լ��� ����)�� �����ϴ� �Լ� signal

void func(int a) {

}

//void(*)(int) signal() {	// �̷� ���´� �̰� �ƴ϶� �Ʒ��� ���� ǥ���Ѵ�.
//	return func;
//}

void(*signal())(int) {	// 
	return func;
}

// void f(int) ������ �Լ��� ���� �� �ִ� �Լ� ������ Ÿ�� ���� -> typedef void(*pf)(int)
// void f(int) ������ �Լ��� ���� �� �ִ� �Լ� �����͵��� �迭 ���� -> void (*pf[3])(int);
// void f(int) ������ �Լ��� ���� �� �ִ� �Լ� �����͸� �����ϴ� �Լ� ���� -> void (*signal())(int) {...} 

// void (*())(int) 
typedef void v;
typedef v fv(int);
typedef fv* pfv;
typedef pfv fpfv();

fpfv signal;		// ������Ÿ�� ����. // void (*signal())(int); �� ������ ������ ǥ��
pfv singal() {		// void (*signal())(int)�� ������ ������ ǥ��
	return func;
}

// int a[2][3]
typedef int i;			// int a[2][3]�� typdef�ϴ� ���
typedef i ai[3];		// a�� Ÿ���� aai��. => aai a, b; �̷��� �����ϸ� int a[2][3], b[2][3]; �� ����
typedef ai aai[2];		// ai[2]�� aai�� typedef �ϴ°�.
typedef int bbi[2][3];	// �̰Ͱ� ���� => bbi a; => int a[2][3];

// int (*(*)())();	
typedef int i;			// int
typedef i f();			// int         ()
typedef f* pf;			// int (*     )()
typedef pf fpf();		// int (*   ())()
typedef fpf* pfpf;		// int (*(*)())()

// char *(*(*var)())[10];	// var�� Ÿ���� pfparrc�̴�.
// => pfparrc var �� ���ľ��� ����
typedef char *c;			// char *
typedef c arrc[10];			// char *        [10]
typedef arrc* parrc;		// char *(*     )[10]
typedef parrc fparrc();		// char *(*   ())[10]
typedef fparrc *pfparrc;	// char *(*(*)())[10]
//	
//int main() {
//	int a = 3;
//	(signal())(a);			// ����: void
//
//	return 0;
//}
	
// ---------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  
#define loop(v, lo, hi) for((v)=(lo); (v)<(hi); (v)++)

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multi(int a, int b) { return a * b; }
int divv(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

// calculator3�� typedef_calculator3�� ������ ������ �ϵ��� FP, FPP�� typedef�� �̿��Ͽ� �ۼ��ϼ���.
typedef int(*FP)(int, int);   // FP �ۼ�
//typedef int i;
//typedef i f(int, int);
//typedef f* FP;
typedef int(*FPP[])(int, int);   // FPP �ۼ�			
//typedef int(**FPP)(int, int);	// (3)
//typedef FP *FPP;				// (4)
//typedef FP FPP[];				// (1)
//typedef int i;				// (2)
//typedef i f(int, int);
//typedef f *pf;
//typedef pf FPP[];

// calculator3��  �Լ� ������ �迭�� �Ű������� �ް� �Լ� �����͸� ��ȯ�ϴ� �Լ� 
// typedef_calculator3�� ������ ������ �ǵ��� calculator3�� ��� �κ��� �ۼ��մϴ�.
// typedef ������
int (*calculator3(int (*fp[])(int, int), int arr_size))(int, int) {
//FP calculator3(FPP fp, int arr_size) {
	int low = 0;
	int high = arr_size - 1;
	int random_Num = rand() % (high - low) + low; //���� �߻������� low���� high �������� ��µǴ� �ڵ�
	return fp[random_Num];
}

FP typedef_calculator3(FPP fp, int arr_size) {
	return calculator3(fp, arr_size);
}

// calculator2�� �Լ� ������ �迭�� �Ű����� �޴� �Լ�
//    calculator2 �Լ��� arr_size �������� �����߻�
//    ��Ģ������ ���� �ǿ����ڴ� 11,7�� ����
//    ������ ���� �Լ� ���� �� ���
//    ����� �Լ� �����͸� ��ȯ�� 

int calculator2(FPP fp, char *optor, int arr_size) {	//
	int random_Num;
	int fir = 11, sec = 7;
	int low = 0;
	int high = arr_size - 1;

	printf("���� �߻� ���� %d ~ %d\n", low, high);

	random_Num = rand() % (high - low) + low; //���� �߻������� low���� high �������� ��µǴ� �ڵ�
	printf("���� : %d\n", random_Num);
	printf("�Լ� ���� : %d %c %d = %d\n", fir, optor[random_Num], sec, fp[random_Num](fir, sec));
	return random_Num;
}

int typedef_calculator2(FPP fp, char* optor, int arr_size) {
	return calculator2(fp, optor, arr_size);
}

//calculator�� �Լ� ������ �迭�� �μ��� �޴� �Լ� 
//fir��sec������ ��� ��Ģ������ ���� ����Ͻÿ�
int calculator(FPP fp, int arr_size) {
	int dx;
	int fir = 11, sec = 7;
	for (size_t i = 0; i < arr_size; i++)
		printf("%d ", fp[i](fir, sec));
	puts("");
}

int typedef_calculator(FPP fp, int arr_size) {
	return calculator(fp, arr_size);
}
//
//int main(void) {
//	int(*fpa[])(int, int) = { sum, sub, multi, divv, mod };  // 1. fpa�� �Լ� ������ �迭 
//	char optor[] = { '+', '-', '*', '/', '%' };
//	int dx;
//
//
//	srand(time(NULL));
//
//	// typedef �� ������� ���� �Լ� ȣ�� 
//	calculator(fpa, sizeof(fpa) / sizeof(fpa[0]));
//
//	calculator2(fpa, optor, sizeof(fpa) / sizeof(fpa[0]));
//	loop(dx, 0, 5)
//	{
//		Sleep(300);
//		printf("random RUN!! : %d\n", calculator3(fpa, sizeof(fpa) / sizeof(fpa[0]))(10, 3));
//	}
//
//	// typedef �� ����� �Լ� ȣ��     
//	typedef_calculator(fpa, sizeof(fpa) / sizeof(fpa[0]));
//
//	typedef_calculator2(fpa, optor, sizeof(fpa) / sizeof(fpa[0]));
//	loop(dx, 0, 5)
//	{
//		Sleep(300);
//		printf("random RUN!! : %d\n", typedef_calculator3(fpa, sizeof(fpa) / sizeof(fpa[0]))(10, 3));
//	}
//}
// ----------------------------------------------------------------------------------------------------------------------------------------
// Circular Queue
#define QUEUE_SIZE 5
int queue[QUEUE_SIZE];
int front, rear;

// ť�� ����� ��: front == rear;		// ó���� 0���� ����, n���� ���� ���� ����(empty�ǹ̴� ����)
// ť�� �� á�� ��: (rear + 1) % QUEUE_SIZE == front (ȯ���̶�) => rear + 1 == QUEUE_SIZE �ϸ� ����ť

void init_queue(void) { front = rear = 0; }
void put(int data) { 
	if ((rear + 1) % QUEUE_SIZE == front) {			// ���ڸ� ����� 
		printf("full\n");
		return;
	}
	queue[rear] = data;				// �ְ� ������Ű��(�ӵ�)
	rear = ++rear % QUEUE_SIZE;
} 
int get() { 
	int save;
	if (front == rear) { printf("empty\n"); return -1; }
	save = front;
	front = ++front % 5;			
	return queue[save];				// ������Ű�� �ֱ�(�ӵ�)
}

void print_queue() {
	int f = front;
	while (f != rear) {
		printf("%d ", queue[f]);
		f = ++f % 5;
	}
}

//int main() {
//	init_queue();
//	put(3);
//	put(4);
//	put(1);
//	put(5);
//	put(2);			// overflow
//	printf("%d\n", get());	printf("%d\n", get());
//	put(6);
//	put(7);
//	print_queue();		// 1 5 6 7 //
//
//	getchar("");
//	return 0;
//}
// -------------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct _tree {
	int key;
	struct _tree *left;
	struct _tree *right;
} Tree;

// level : ������ 0���� 
// level n���� �ִ� ����� ���� 2^n��

// �켱����ť priority Q // tree => �迭

Tree *head, *tail;

void init_tree() {
	head = NULL;
	tail = NULL;
}

// ��ȸ : ����/����/����/����
// ����(CLR)/����(LCR)/����(LRC) -> ���ñ�� ����
// ���� -> ť��� ����
void preorder(Tree *t) {	// ���� x ���
	if (t) {
		printf("%d ", t->key);
		preorder(t->left);		
		preorder(t->right);
	}
}

// 1. ��Ʈ�� push
// 2. stack�� ������� ������ pop() => ���
// 3. pop()�� ����� push(right child)�ϰ�, push(left child) => �ݵ�� �����ʺ���!(�����̹Ƿ� �������� push)
// 4. 1������ �ݺ�
void preorder_s(Tree *t) {	// ���� x ����
	push(&t);
	if (!is_empty()) {
		Tree f = pop();
		printf("%d ", f.key);
	}
	preorder_s(t->right);
	preorder_s(t->left);
}

// inorder�� ����Ž��Ʈ���� inorder������� ��ȸ�ϸ� ����ȿ���� ���� �ִ�(��, inorder�� ����Ž��Ʈ���� Ʈ�����Ķ� ���ȴ�)
void inorder(Tree *t) {	// ���� x ���
	if (t) {
		inorder(t->left);
		printf("%d ", t->key);
		inorder(t->right);
	}
}

// 1. ��Ʈ�� push
// 2. left child�� ���� ������ ��� left���� push
// 3. ������ push�� leftchild�� pop() => ���
// 4. pop()�� ����� right child�� ���� 1������ �ݺ�
void inorder_s(Tree *t) {	// ���� x ����
	push(&t);

}

void postorder(Tree *t) {	// ���� x ���
	if (t) {
		postorder(t->left);
		postorder(t->right);
		printf("%d ", t->key);
	}
}

// 1. root�� push
// 2. ������ ������� ������ pop() => ���
// 3. pop()�� ����� left�� push, right�� push
// 4. 2������ �ݺ�
void levelorder(Tree *t) {
	enqueue(t);					// levelorder�� ���� ť queue �� ����ü������ �迭 Ÿ���̾�� �Ѵ�. 
	Tree *f;					// Tree *queue[];
	while (!is_empty()) {
		f = dequeue();
		printf("%d ", f->key);
		if (f->left) enqueue(f->left);
		if (f->right) enqueue(f->right);
	}	
}

// Ʈ���� �ұ����� ��Ƴ����� �е� ��� ���� ���� �˾ƾ� �� => getLevel()�� �뵵
int getLevel(Tree *t) {
	int height = -1;		// level ���� 0����
	if (t) 
		height = 1 + (getLevel(t->left) > getLevel(t->right) ? getLevel(t->left) : getLevel(t->right));
	return height; 
}

//main() {
//	Tree i = { 9, NULL, NULL },
//		g = { 7, NULL, NULL },
//		h = { 8, &i, NULL },
//		d = { 6, NULL, NULL },
//		c = { 4, &d, NULL },
//		f = { 5, &g, &h },
//		b = { 2, NULL, &c },
//		e = { 3, &f, NULL },
//		a = { 1, &b, &e };
//
//	/*preorder(&a);
//	printf("\n");
//	inorder(&a);
//	printf("\n");
//	postorder(&a);
//	printf("\n");*/
//	printf("%d\n", getLevel(&a));		// ��Ʈ����� level��. => ��ü Ʈ���� depth
//	printf("%d\n", getLevel(a.left));	// a�� ���ʼ��긮Ʈ�� level��
//	getchar("");
//}  
// --------------------------------------------------------------------------------------------------------------------------------------------------------

