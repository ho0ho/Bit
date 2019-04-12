#include <stdio.h>
#include <string.h>

#pragma warning(disable :4996)
//
//// 이중 환형 연결리스트 
//typedef int ElementType;
//typedef struct tagNode
//{
//	ElementType Data;
//	struct tagNode* PrevNode;
//	struct tagNode* NextNode;
//} Node;
//Node* CreateNode(ElementType NewData)
//{
//	Node* NewNode = (Node*)malloc(sizeof(Node));
//	NewNode->Data = NewData;
//	NewNode->PrevNode = NULL;
//	NewNode->NextNode = NULL;
//	return NewNode;
//}
//
//// -노드 추가 *-
//void AppendNode(Node** Head, Node* NewNode)
//{
//	if ((*Head) == NULL)
//	{
//		*Head = NewNode;
//		(*Head)->NextNode = *Head;
//		(*Head)->PrevNode = *Head;
//	}
//	else
//	{
//		Node* Tail = (*Head)->PrevNode;	// tail : 마지막에서 2번째 노드
//
//		Tail->NextNode->PrevNode = NewNode;	// 삽입시: tail을 마지막노드로 밀고, 그 노드에 새노드 연결
//		Tail->NextNode = NewNode;			// tail은 다시 마지막에서 2번째 노드 가리키게 됨
//		NewNode->NextNode = (*Head);
//		NewNode->PrevNode = Tail;
//	}
//}
//int main(void)
//{
//	int   i = 0;
//	int   Count = 0;
//	Node* List = NULL;
//	Node* NewNode = NULL;
//	Node* Current = NULL;
//	// -노드 5개 추가 *-
//		for (i = 0; i < 5; i++) //이 반복문이 3번 도는 경우까지의 메모리 모양 그리기
//		{
//			NewNode = CreateNode(i);
//			AppendNode(&List, NewNode);
//		}
//}

// ------------------------------------------------------------------------------------------------------
//
//// 배열로 스택구현
//#define STACK_SIZE 5
//
//typedef struct _node {
//	int key;
//	// other data...
//} Node;
//
////typedef struct _stack {
////	int top;
////	Node arr[];
////} Stack;
//
//int top = -1;
//Node *arr[STACK_SIZE];
//
//void init() { top = -1; }
//
//int is_full() {	return (top >= STACK_SIZE); }
//
//int is_empty() { return (top < 0); }
//
//void push(int data) {
//	Node *new_node = (Node *)malloc(sizeof(Node));
//	new_node->key = data;
//	if (is_full()) { printf("full\n"); return; }
//	arr[++top] = new_node;
//}
//
//int pop() {
//	int del;
//	if (is_empty()) { printf("empty\n"); return -1; }
//	del = arr[top]->key;
//	free(arr[top--]);
//	return del;
//}
//
//int peek() {
//	if (is_empty()) { printf("empty\n"); return; }
//	return arr[top]->key;
//}
//
//int main() {
//	init();
//	push(8);
//	push(10);
//	push(5);
//	push(3);
//	for(size_t i = 0; i < 5; )
//	printf("%d ", pop());
//
//	return 0;
//}
//
//// 연결리스트로 스택구현
//typedef struct _node {
//	int key;
//	struct _node *link;
//} Node;
//
//typedef struct _stack {
//	struct Node *top;
//} Stack;
//
//void init(Stack *s) {
//	s->top = NULL;
//}

//----------------------------------------------------------------------------------------------------
//
//void evaluate(char *in) {
//	if (/*숫자*/) {
//		push(in);
//		
//	}
//	else if (/*연산자*/) {
//		char *op1 = pop();
//		char *op2 = pop();
//		atoi(op1) in atoi(op2));
//	}
//}
//-------------------------------------------------------------------------------------------------------------------------------------------------
//#include <stdarg.h>
typedef char *  myva_list;
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )		// x86 로 했을 때 진행가능(x64로 하면 sizeof()값이 달라질 수 있음)
#define va_start(ap,v)  ( ap = (myva_list)&v + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (myva_list)0 )

float average(int num, ...) {		// ... : 가변인자
	myva_list arg_ptr;				// 가변인자 앞에는 가변인자의 특징을 나타내는 것들을 씀
	int cnt, total = 0;				// 실메모리에는 우측 매개변수값부터 들어감(10<-1<-2<-...<-10)=> stack

	va_start(arg_ptr, num);
	for (cnt = 0; cnt < num; cnt++)
		total += va_arg(arg_ptr, int);

	va_end(arg_ptr);
	return ((float)total / num);
}
//
//int main() {
//	float x;
//	x = average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//	printf("first avg is %f\n", x);
//	return 0;
//}
//------------------------------------------------------------------------------------------------------------------------------------------------
#define STACK_SIZE 10
#define STR_SIZE 10
char stack[STACK_SIZE][STR_SIZE];
int currTop;
int validTop;

void init() {
	currTop = validTop = -1;
}

int isEmpty() { return (validTop < 0); }
int isFull() { return (validTop >= STACK_SIZE); }

void push(char *url) {
	if (isFull()) { printf("full\n"); return; }
	if (currTop < validTop)
		validTop = currTop;
	currTop++;
	strcpy(stack[++validTop], url);
}

char *pop() {
	if (isEmpty()) { printf("empty\n"); return NULL; }
	return stack[validTop--];
}

void connectWebPage(char *url) { if (strcmp(stack[currTop], url)) push(url); }

void viewWebPage() {
	int i, j;
	printf("  < 뒤로 이동할 수 있는 목록 > \n");
	printf("=====================================\n");
	i = currTop;
	j = 1;
	while (0 < i)
		printf("%d. %s\n", j++, stack[--i]);
	if (j == 1) printf("뒤로 갈 웹페이지가 없습니다.\n\n");
	printf("\n  < 앞으로 이동할 수 있는 목록 > \n");
	printf("=====================================\n");
	i = currTop;
	j = 1;
	while (validTop > i)
		printf("%d. %s\n", j++, stack[++i]);
	if (j == 1) printf("앞으로 갈 웹페이지가 없습니다.\n\n");
}

int main() {
	int user_m;
	char *menu[] = { "URL 접속", "방문기록 보기", "뒤로", "앞으로", "종료" };
	char first[] = "about:blank";
	char url[STR_SIZE];	

	init();
	while (1) {
		printf("\n현재 접속중인 웹 페이지: %s\n", first);
		printf("============================================\n");
		for(size_t idx = 0; idx < 5; idx++)
			printf("%d. %s\n", idx + 1, menu[idx]);
		printf("============================================\n");

		printf("메뉴를 입력하세요: ");
		scanf("%d", &user_m);

		switch (user_m) {
		case 1:
			printf("\n접속할 웹페이지 주소를 입력하세요: ");
			scanf("%s", url);
			connectWebPage(url);
			system("cls");
			break;
		case 2:
			printf("\n2. 방문기록 보기를 선택하셨습니다.\n");
			viewWebPage();
			getchar(""); getchar("");
			system("cls");
			break;
		case 3:
			if (currTop > 0) currTop--;
			system("cls");
			break;
		case 4:
			if (currTop < validTop) currTop++;
			system("cls");
			break;
		case 5:
			printf("\n\n종료합니다.\n");
			return 0;
		default:
			printf("\n\n없지롱\n");
		}
		if (currTop >= 0 && currTop <= validTop)
			strcpy(first, stack[currTop]);
	}
	return 0;
} 
// ----------------------------------------------------------------------------------------------------------------------------------------------