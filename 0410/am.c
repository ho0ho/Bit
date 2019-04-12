#include <stdio.h>

// void(*signal(int signum, void(*handler)(int)))(int);
// void -> (int) -> * -> (int sn, void(*h)(int)) -> signal
// void (int) 형태의 함수를 가리키는(*) 함수포인터(즉 함수를 리턴)를 리턴하는 함수 signal

void func(int a) {

}

//void(*)(int) signal() {	// 이런 형태는 이게 아니라 아래와 같이 표현한다.
//	return func;
//}

void(*signal())(int) {	// 
	return func;
}

// void f(int) 형태의 함수를 받을 수 있는 함수 포인터 타입 선언 -> typedef void(*pf)(int)
// void f(int) 형태의 함수를 받을 수 있는 함수 포인터들의 배열 선언 -> void (*pf[3])(int);
// void f(int) 형태의 함수를 받을 수 있는 함수 포인터를 리턴하는 함수 선언 -> void (*signal())(int) {...} 

// void (*())(int) 
typedef void v;
typedef v fv(int);
typedef fv* pfv;
typedef pfv fpfv();

fpfv signal;		// 프로토타입 선언. // void (*signal())(int); 와 완전히 동일한 표현
pfv singal() {		// void (*signal())(int)와 완전히 동일한 표현
	return func;
}

// int a[2][3]
typedef int i;			// int a[2][3]을 typdef하는 방법
typedef i ai[3];		// a의 타입은 aai다. => aai a, b; 이렇게 선언하면 int a[2][3], b[2][3]; 과 동일
typedef ai aai[2];		// ai[2]를 aai로 typedef 하는것.
typedef int bbi[2][3];	// 이것과 동일 => bbi a; => int a[2][3];

// int (*(*)())();	
typedef int i;			// int
typedef i f();			// int         ()
typedef f* pf;			// int (*     )()
typedef pf fpf();		// int (*   ())()
typedef fpf* pfpf;		// int (*(*)())()

// char *(*(*var)())[10];	// var의 타입은 pfparrc이다.
// => pfparrc var 로 고쳐쓸수 있음
typedef char *c;			// char *
typedef c arrc[10];			// char *        [10]
typedef arrc* parrc;		// char *(*     )[10]
typedef parrc fparrc();		// char *(*   ())[10]
typedef fparrc *pfparrc;	// char *(*(*)())[10]
//	
//int main() {
//	int a = 3;
//	(signal())(a);			// 리턴: void
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

// calculator3과 typedef_calculator3이 동일한 동작을 하도록 FP, FPP를 typedef를 이용하여 작성하세요.
typedef int(*FP)(int, int);   // FP 작성
//typedef int i;
//typedef i f(int, int);
//typedef f* FP;
typedef int(*FPP[])(int, int);   // FPP 작성			
//typedef int(**FPP)(int, int);	// (3)
//typedef FP *FPP;				// (4)
//typedef FP FPP[];				// (1)
//typedef int i;				// (2)
//typedef i f(int, int);
//typedef f *pf;
//typedef pf FPP[];

// calculator3은  함수 포인터 배열을 매개변수로 받고 함수 포인터를 반환하는 함수 
// typedef_calculator3과 동일한 선언이 되도록 calculator3의 헤더 부분을 작성합니다.
// typedef 사용금지
int (*calculator3(int (*fp[])(int, int), int arr_size))(int, int) {
//FP calculator3(FPP fp, int arr_size) {
	int low = 0;
	int high = arr_size - 1;
	int random_Num = rand() % (high - low) + low; //난수 발생범위를 low에서 high 범위내에 출력되는 코드
	return fp[random_Num];
}

FP typedef_calculator3(FPP fp, int arr_size) {
	return calculator3(fp, arr_size);
}

// calculator2는 함수 포인터 배열을 매개변수 받는 함수
//    calculator2 함수는 arr_size 범위내로 난수발샘
//    사칙연산을 위한 피연산자는 11,7로 고정
//    난수에 따라 함수 수행 후 출력
//    수행된 함수 포인터를 반환함 

int calculator2(FPP fp, char *optor, int arr_size) {	//
	int random_Num;
	int fir = 11, sec = 7;
	int low = 0;
	int high = arr_size - 1;

	printf("난수 발생 범위 %d ~ %d\n", low, high);

	random_Num = rand() % (high - low) + low; //난수 발생범위를 low에서 high 범위내에 출력되는 코드
	printf("난수 : %d\n", random_Num);
	printf("함수 실행 : %d %c %d = %d\n", fir, optor[random_Num], sec, fp[random_Num](fir, sec));
	return random_Num;
}

int typedef_calculator2(FPP fp, char* optor, int arr_size) {
	return calculator2(fp, optor, arr_size);
}

//calculator는 함수 포인터 배열을 인수로 받는 함수 
//fir와sec값으로 모든 사칙연산을 구현 출력하시오
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
//	int(*fpa[])(int, int) = { sum, sub, multi, divv, mod };  // 1. fpa는 함수 포인터 배열 
//	char optor[] = { '+', '-', '*', '/', '%' };
//	int dx;
//
//
//	srand(time(NULL));
//
//	// typedef 를 사용하지 않은 함수 호출 
//	calculator(fpa, sizeof(fpa) / sizeof(fpa[0]));
//
//	calculator2(fpa, optor, sizeof(fpa) / sizeof(fpa[0]));
//	loop(dx, 0, 5)
//	{
//		Sleep(300);
//		printf("random RUN!! : %d\n", calculator3(fpa, sizeof(fpa) / sizeof(fpa[0]))(10, 3));
//	}
//
//	// typedef 를 사용한 함수 호출     
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

// 큐가 비었을 때: front == rear;		// 처음만 0으로 같고, n에서 같을 수도 있음(empty의미는 동일)
// 큐가 꽉 찼을 때: (rear + 1) % QUEUE_SIZE == front (환형이라서) => rear + 1 == QUEUE_SIZE 하면 선형큐

void init_queue(void) { front = rear = 0; }
void put(int data) { 
	if ((rear + 1) % QUEUE_SIZE == front) {			// 한자리 비워서 
		printf("full\n");
		return;
	}
	queue[rear] = data;				// 넣고 증가시키기(속도)
	rear = ++rear % QUEUE_SIZE;
} 
int get() { 
	int save;
	if (front == rear) { printf("empty\n"); return -1; }
	save = front;
	front = ++front % 5;			
	return queue[save];				// 증가시키고 넣기(속도)
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

// level : 위에서 0부터 
// level n층에 있는 노드의 수는 2^n개

// 우선순위큐 priority Q // tree => 배열

Tree *head, *tail;

void init_tree() {
	head = NULL;
	tail = NULL;
}

// 순회 : 전위/중위/후위/층별
// 전위(CLR)/중위(LCR)/후위(LRC) -> 스택기반 구현
// 층별 -> 큐기반 구현
void preorder(Tree *t) {	// 전위 x 재귀
	if (t) {
		printf("%d ", t->key);
		preorder(t->left);		
		preorder(t->right);
	}
}

// 1. 루트를 push
// 2. stack이 비어있지 않으면 pop() => 출력
// 3. pop()한 대상의 push(right child)하고, push(left child) => 반드시 오른쪽부터!(스택이므로 역순으로 push)
// 4. 1번부터 반복
void preorder_s(Tree *t) {	// 전위 x 스택
	push(&t);
	if (!is_empty()) {
		Tree f = pop();
		printf("%d ", f.key);
	}
	preorder_s(t->right);
	preorder_s(t->left);
}

// inorder는 이진탐색트리를 inorder방식으로 순회하면 정렬효과를 볼수 있다(즉, inorder는 이진탐색트리의 트리정렬때 사용된다)
void inorder(Tree *t) {	// 중위 x 재귀
	if (t) {
		inorder(t->left);
		printf("%d ", t->key);
		inorder(t->right);
	}
}

// 1. 루트를 push
// 2. left child가 없을 때까지 계속 left들을 push
// 3. 마지막 push한 leftchild를 pop() => 출력
// 4. pop()한 대상의 right child에 대해 1번부터 반복
void inorder_s(Tree *t) {	// 중위 x 스택
	push(&t);

}

void postorder(Tree *t) {	// 후위 x 재귀
	if (t) {
		postorder(t->left);
		postorder(t->right);
		printf("%d ", t->key);
	}
}

// 1. root를 push
// 2. 스택이 비어있지 않으면 pop() => 출력
// 3. pop()한 대상의 left를 push, right를 push
// 4. 2번부터 반복
void levelorder(Tree *t) {
	enqueue(t);					// levelorder를 위한 큐 queue 는 구조체포인터 배열 타입이어야 한다. 
	Tree *f;					// Tree *queue[];
	while (!is_empty()) {
		f = dequeue();
		printf("%d ", f->key);
		if (f->left) enqueue(f->left);
		if (f->right) enqueue(f->right);
	}	
}

// 트리의 불균형을 잡아내려면 밀도 대비 깊이 값을 알아야 함 => getLevel()의 용도
int getLevel(Tree *t) {
	int height = -1;		// level 값은 0부터
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
//	printf("%d\n", getLevel(&a));		// 루트노드의 level값. => 전체 트리의 depth
//	printf("%d\n", getLevel(a.left));	// a의 왼쪽서브리트의 level값
//	getchar("");
//}  
// --------------------------------------------------------------------------------------------------------------------------------------------------------

