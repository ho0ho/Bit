#include <stdio.h>
#include <string.h>

#pragma warning(disable :4996)
//
//// ���� ȯ�� ���Ḯ��Ʈ 
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
//// -��� �߰� *-
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
//		Node* Tail = (*Head)->PrevNode;	// tail : ���������� 2��° ���
//
//		Tail->NextNode->PrevNode = NewNode;	// ���Խ�: tail�� ���������� �а�, �� ��忡 ����� ����
//		Tail->NextNode = NewNode;			// tail�� �ٽ� ���������� 2��° ��� ����Ű�� ��
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
//	// -��� 5�� �߰� *-
//		for (i = 0; i < 5; i++) //�� �ݺ����� 3�� ���� �������� �޸� ��� �׸���
//		{
//			NewNode = CreateNode(i);
//			AppendNode(&List, NewNode);
//		}
//}

// ------------------------------------------------------------------------------------------------------
//
//// �迭�� ���ñ���
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
//// ���Ḯ��Ʈ�� ���ñ���
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
//	if (/*����*/) {
//		push(in);
//		
//	}
//	else if (/*������*/) {
//		char *op1 = pop();
//		char *op2 = pop();
//		atoi(op1) in atoi(op2));
//	}
//}
//-------------------------------------------------------------------------------------------------------------------------------------------------
//#include <stdarg.h>
typedef char *  myva_list;
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )		// x86 �� ���� �� ���డ��(x64�� �ϸ� sizeof()���� �޶��� �� ����)
#define va_start(ap,v)  ( ap = (myva_list)&v + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (myva_list)0 )

float average(int num, ...) {		// ... : ��������
	myva_list arg_ptr;				// �������� �տ��� ���������� Ư¡�� ��Ÿ���� �͵��� ��
	int cnt, total = 0;				// �Ǹ޸𸮿��� ���� �Ű����������� ��(10<-1<-2<-...<-10)=> stack

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
	printf("  < �ڷ� �̵��� �� �ִ� ��� > \n");
	printf("=====================================\n");
	i = currTop;
	j = 1;
	while (0 < i)
		printf("%d. %s\n", j++, stack[--i]);
	if (j == 1) printf("�ڷ� �� ���������� �����ϴ�.\n\n");
	printf("\n  < ������ �̵��� �� �ִ� ��� > \n");
	printf("=====================================\n");
	i = currTop;
	j = 1;
	while (validTop > i)
		printf("%d. %s\n", j++, stack[++i]);
	if (j == 1) printf("������ �� ���������� �����ϴ�.\n\n");
}

int main() {
	int user_m;
	char *menu[] = { "URL ����", "�湮��� ����", "�ڷ�", "������", "����" };
	char first[] = "about:blank";
	char url[STR_SIZE];	

	init();
	while (1) {
		printf("\n���� �������� �� ������: %s\n", first);
		printf("============================================\n");
		for(size_t idx = 0; idx < 5; idx++)
			printf("%d. %s\n", idx + 1, menu[idx]);
		printf("============================================\n");

		printf("�޴��� �Է��ϼ���: ");
		scanf("%d", &user_m);

		switch (user_m) {
		case 1:
			printf("\n������ �������� �ּҸ� �Է��ϼ���: ");
			scanf("%s", url);
			connectWebPage(url);
			system("cls");
			break;
		case 2:
			printf("\n2. �湮��� ���⸦ �����ϼ̽��ϴ�.\n");
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
			printf("\n\n�����մϴ�.\n");
			return 0;
		default:
			printf("\n\n������\n");
		}
		if (currTop >= 0 && currTop <= validTop)
			strcpy(first, stack[currTop]);
	}
	return 0;
} 
// ----------------------------------------------------------------------------------------------------------------------------------------------