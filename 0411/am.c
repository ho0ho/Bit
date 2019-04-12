#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)
//
//#define DEBUG
//
//#ifdef DEBUG
//#define myDEBUG(exp) (exp)
//#else
//#define myDEBUG(exp) (void *)0
//#endif

//main() {
//	myDEBUG(puts("test"));
//	getchar();
//}

// exp == TRUE : 다음문 실행
// exp == FALSE : stderr에 에러메시지 출력 후 종료
/* NDEBUG 가 정의되어 있을 때는 FALSE여도 에러발생 X */
/* assert.h 포함해야함 */
// void assert(int exp);		
//
//#define NDEBUG
//#include <assert.h>
//
//main() {
//	int x;
//	printf("\nEnter an integer value: ");
//	scanf("%d", &x);
	/*assert(x >= 0);*/
//	printf("You entered %d.\n", x);
//	return(0);
//}
//------------------------------------------------------------------------------------------------------------------------------
//
#include <string.h>

int find_normal(char(*arr)[10], int low, int high, char *name) {
	while (low < high) {
		int mid = (low + high) / 2;
		if (strcmp(arr[mid], name) < 0)
			low = mid + 1;
		else if (strcmp(arr[mid], name) > 0)
			high = mid - 1;
		else return mid;
	}
	return -1;
}

int find_recursion(char(*arr)[10], int low, int high, char *name) {
	if (low < high) {
		int mid = (low + high) / 2;
		if (strcmp(arr[mid], name) < 0)
			return find_recursion(arr, mid + 1, high, name);
		else if (strcmp(arr[mid], name) > 0)
			return find_recursion(arr, low, mid - 1, name);
		else return mid;	// found
	}
	return -1;
}

int compare(const void *a, const void *b) {
	return (strcmp((char *)a, (char *)b) > 0);
}
//
//#define T 1
//#ifdef T 1
//#define test() find_recursion(key, 0, 25, name);
//#else 
//#define test() find_normal(key, 0, 25, name);
//#endif
//
//int main() {
//	char key[][10] = { "Alice", "Bill", "Carol", "David", "Elvis", "Fred", "Gabriel",
//					   "Helen", "Isabel", "Jane", "Kuper", "Louic", "Mathilda", "Nadia", 
//					   "Olive", "Pablo", "Queen", "Rambo", "Scarlet", "Trisha", "Umberto", 
//					   "Vincent", "Wily", "Xxx", "Yuki", "Zorro" };
//
//	char name[] = "Pablo";
//	int ret;
//
//	/*ret = find_recursion(key, 0, 25, name);*/
//	ret = test();
//	if (ret < 0) printf("%s not exist\n", name);
//	else printf("index of %s: %d\n", name, ret);
//
//	int b = bsearch()
//	if (b) printf("index of %s: %d\n", name, b);
//	else printf("%s not exist\n", name);
//
//	return 0;
//}

// --------------------------------------------------------------------------------------------------------------------------

// 불균형 BST를 균형 BST로 만드는 함수
// arr은 balance를 타고 들어가면서도 인덱스정보가 공유되어야 하므로 매개변수로 넘기면 안됨
#define SIZE 5
typedef struct _tree {
	int key;
	struct _tree *left;
	struct _tree *right;
} Tree;
int sortArr[SIZE];
int idx = 0;
Tree *balance(Tree *t, int cnt_n) {
	int l_cnt_node, r_cnt_node;
	Tree *n;
	if (cnt_n > 0) {
		l_cnt_node = (cnt_n - 1) / 2;
		r_cnt_node = cnt_n - 1 - l_cnt_node;
		n = (Tree *)malloc(sizeof(Tree));
		n->left = balance(n->left, l_cnt_node);
		n->key = sortArr[idx++];
		n->right = balance(n->right, r_cnt_node);

		return n;
	}
	return NULL;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------

///#define list_entry(ptr, type, member) \
// ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
//list_entry를 이용하여 다음 구조체의 각멤버(a,b,c,d,x,y,z)를 이용해 
//구조체의 첫 주소를 출력하는 main함수를 완성하시오

#define address(ptr, type, member)  ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

typedef struct engine {
	char a[5];
	double b;
	int c[3];
} engine;

typedef struct car {
	char x[10];
	int y;
	struct engine z;
} car;
//void main()
//{
//	car bm;
//	printf("&bm : [ %x ]\n", address(&bm.x, car, x));	// => bm.x으로 car의 주소 알아내기
//	// (type *)((char *)(&bm.x) - (&((type *)0)->x)
//}
// ---------------------------------------------------------------------------------------------------------------------


//list.h(기존에 메일로 보낸 리눅스 커널 헤더)파일을 include 할 수 있도록 구현하시오
//inline이나 prefetch는 제공되지 않는 기능이다.
//
//#define _LINUX_LIST_H
//#include "list.h"
//
//typedef struct kernel_struct
//{
//	int key;
//	struct list_head list;
//
//} Node;
//#define ADRS(lt) &(lt)->list
//
//#define Node_SIZE (sizeof(Node))
//
//Node *head;
//
//
//void init_Node(void)
//{
//	//head를 메모리 할당시킨다 
//	head = malloc(Node_SIZE);
//
//	//head 구조체 멤버인 list내부의 멤버가 list를 가리키게 초기화시키자
//	INIT_LIST_HEAD(&head->list);
//}
//
//void print_all(void)
//{
//	struct list_head *temp;
//	printf("************\n");
//	list_for_each(temp, &head->list) {
//		Node *ps = list_entry(temp, Node, list);
//		printf("[%d]\n", ps->key);
//	}
//}

//void main()
//{
//	Node *a, *b;
//	if ((a = malloc(Node_SIZE)) == NULL)
//		printf("[ Error ]\n");
//	if ((b = malloc(Node_SIZE)) == NULL)
//		printf("[ Error ]\n");
//
//	init_Node();
//	a->key = 123; b->key = 789;
//	print_all();
//
//	if (list_empty(&head->list))
//		printf("[ Empty ]\n");
//
//
//
//
//	list_add();//list_add 함수를 이용하여 head뒤에 a를 삽입 
//	print_all();
//	list_add();//list_add 함수를 이용하여 head뒤에 b를 삽입
//	print_all();
//	list_del();//list_del함수를 이용하여 head뒤에 를 삭제
//
//	print_all();
//	free(a);
//	free(b);
//	free(head);
//}
// -----------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 256
struct nlist {
	struct nlist *next;
	char *name;
	char *phone;
};

static struct nlist *hashtab[HASHSIZE];
typedef struct nlist NLIST;

unsigned hash(char *s)
{
	unsigned hashval = 7;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist* lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

char *str_mcopy(char *s)
{
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

struct nlist* install(char *name, char *phone)
{
	struct nlist *np = (struct nlist *)malloc(sizeof(*np));
	unsigned hashval;

	if (np == NULL || (np->name = str_mcopy(name)) == NULL) return NULL;

	/* hashval = hash(name);
	f = lookup(name, hashtab[hash(name)]);
	if (!f)
		np->next = hashtab[hashval];
	else 
		np->next = f; 
	hashtab[hashval] = np;*/
	
	np->next = lookup(name);
	hashtab[hash(name)] = np;

	if ((np->phone = str_mcopy(phone)) == NULL) return NULL;
	
	return np;
}
int main()
{
	char *name[] = { "손나은","김태희","한지민", "문채원","전지현","문채원" };
	char *phone[] = { "731-1234", "567-8976", "521-5030", "521-9600", "418-4165", "520-3307", "425-1024" };
	int i, n = sizeof(name) / sizeof(name[0]);
	struct nlist *head, *ptr;

	for (i = 0; i < n; i++) {
		printf("%d: %s\n", hash(name[i]), name[i]);
		install(name[i], phone[i]);
	}
	printf("\nHash Table List \n");
	for (i = 0; i < HASHSIZE; i++) {
		head = hashtab[i];
		for (ptr = head; ptr != NULL; ptr = ptr->next) 
			printf("%d: %s, %s\n", i, ptr->name, ptr->phone);
	}
	printf("\nHash Table Search \n");
	
	char f[] = "문채원";
	ptr = lookup(f);
	while (ptr) {
		printf("found: %s, %s\n", ptr->name, ptr->phone);
		ptr = ptr->next;
	}
	printf("\nPress any key to end...");
	getchar();
	return 0;
}