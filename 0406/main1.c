#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct Node {
	int key;
	struct Node *next;		// �ڱ����� ����ü
} Node;

typedef struct list {
	Node *head;				// ���̳��(��Ÿ������)
	Node *tail;				// ���̳��(��Ÿ������)
} List;

void list_init(List *list) {
	/*list->head = NULL;
	list->tail = NULL;*/

	list->head = (Node *)malloc(sizeof(Node));		// list->head(Stack ����), ����Ű�� ������ Heap����
	list->tail = (Node *)malloc(sizeof(Node));
	list->head->next = list->tail;
	list->tail->next = list->tail;		// �������� �ڱ��ڽ��� ����(�ŵ�)
}	

int is_empty(List *list) {	return (list->head->next == list->tail); }

void list_add(List *list, int e) {
	// head�ʿ� �߰��ϴ� �޼ҵ�
	Node *pf = list_find(list, e);
	if (!pf) {
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->key = e;		
		new_node->next = pf->next;
		pf->next = new_node;
	}
}

void list_add_sort(List *list, int e) {			// �����ϸ鼭 �߰���		
	Node *new_node = (Node *)malloc(sizeof(Node));		// list_add()�� ������ new_node������ ������� heap������ ���� �޸𸮰���(malloc)�� �����ִ�. 
	new_node->key = e;
	if (is_empty(list)) {
		list->head->next = new_node;
		new_node->next = list->tail;
	}
	else {
		Node *pf = list->head;
		while (pf->next != list->tail && pf->next->key <= e) {	// 
			pf = pf->next;
		}

		new_node->next = pf->next;
		pf->next = new_node;
	}
}

void list_view(List *list) {
	Node *find = list->head->next;
	printf("[���]  ");
	while (find != list->tail) {
		printf("%d ", find->key);
		find = find->next;
	}
}

Node *list_find(List *list, int d) {
	int flag = 0;
	Node *find, *p_find;

	find = list->head->next;
	p_find = list->head;
	while (find != list->tail) {
		if (find->key == d) {
			flag = 1; break;
		}
		p_find = find;
		find = find->next;
	}

	if (!flag) return NULL;
	else return p_find;
}

void list_delete(List *list, int d) {
	Node *p_find = list_find(list, d);
	if (!p_find) printf("not exist\n");
	
	Node *find = p_find->next;
	p_find->next = find->next;

	free(find);
	find = NULL;
}

void list_delete_all(List *list) {
	// 1. list_delete() �̿��ϴ� ���
	Node *p = list->head;
	while (p->next != list->tail) 
		list_delete(list, p->next->key);

	//// 2. ���� ����
	//Node *f = list->head->next;
	//Node *d;
	//while (f != list->tail) {
	//	d = f;
	//  f = f->next;
	//	free(d);
	//}
}

void moveTofront(List *list, int f) {	   /* f�� �Ǿ����� �������� */	
	Node *p_find = list_find(list, f);
	if (!p_find) { printf("%d not exist", f); return; }
	if (p_find != list->head) {
		Node *find = p_find->next;
		Node *h = find->next;
		find->next = list->head->next;
		list->head->next = p_find->next;
		p_find->next = h;
	}
}

void swap(List *list, int *i, int *j) {
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void transpose(List *list, int v) {
	//Node *pf = list_find(list, v);			// �߸Ť���
	//if (pf != list->head) { swap(list, &pf->key, &pf->next->key); }
	
	Node *pf = list_find(list, v);
	if (!pf) { printf("\n%d not exist\n\n", v); return; }
	if (pf != list->head) {
		Node *ppf = list_find(list, pf->key);
		Node *f = pf->next;
		pf->next = f->next;
		f->next = pf;
		ppf->next = f;
	}
}

int main() {
	List list;
	list_init(&list);
	list_add(&list, 3);
	list_add(&list, 4);
	list_add(&list, 5);
	list_view(&list);
	list_delete(&list, 3);
	list_view(&list);
	list_delete_add(&list);
	list_view(&list);
	return 0;
}

//int main() {
//	List list;
//	int size = 0;
//	list_init(&list);
//
//	srand((unsigned)time(NULL));
//	while (size < 10) {
//		system("cls");
//		int r = rand() % 10 + 1;
//		printf("%d\n", r);
//		Node *f = list_find(&list, r);
//		if (!f) {
//			list_add_sort(&list, r);
//			list_view(&list);
//			size++;
//		}
//		else {
//			list_view(&list);
//			printf("\n%d�ߺ�\n", r);
//		}
//		Sleep(300);
//	}
//
//	printf("\n�ϼ��Ǿ����ϴ�\n");
//
//	int front, change;
//	while (1) {
//		printf("\n\n�Ǿ������� �Űܾ��ϴ� ������ �Է��Ͻÿ�: ");
//		scanf("%d", &front);
//		moveTofront(&list, front);
//		list_view(&list);
//		printf("\n\n�ճ��� �ٲ���ϴ� ������ �Է��Ͻÿ�: ");
//		scanf("%d", &change);
//		transpose(&list, change);
//		list_view(&list);
//	}
//	return 0;
//}

//struct num {
//	int fir;
//	int sec;
//};
//
//void func1(int a, int b) {
//	printf("%d\n", a + b);
//}
//
//void func2(struct num *p) {		// struc num p[]�� ����
//	printf("%d\n", p->fir + p->sec);
//}
//
//void func3(struct num *p) {		// struct num �迭�� ���� �� ����!
//	int sum = 0;
//	for (int i = 0; i < 2; i++, p++)			
//		sum += (p->fir + p->sec);			// p[i].first, p[i].sec 
//	printf("%d\n", sum);					// => p[i]->first, p[i]->sec�� �ƴ��� ����!
//}
//
//main() {
//	struct num a = { 1, 2 }, b = { 3, 4 }, c[2] = { 5, 6, 7, 8 };
//	func1(a.fir, a.sec);
//	func2(&b);
//	func3(c);
//}

//typedef struct subject {
//	int subname[5];
//} Subject;
//
//typedef struct sung {
//	char name[10];
//	float avg;
//	Subject sub;
//} Sung;
//
//int main() {
//	int i = 0, cnt;
//	char *su[] = { "����", "����", "����" };
//
//	printf("cnt : ");
//	scanf("%d", &cnt);
//	Sung *s_arr = (Sung *)malloc(sizeof(Sung) * cnt);
//
//	int order = 0;
//	while (i < cnt) {
//		printf("%d��° ����̸�: ", i + 1);
//		scanf("%s", s_arr[i].name);
//		for (size_t s = 0; s < 3; s++) {
//			printf("%s����: ", su[s]);
//			scanf("%d", &s_arr[i].sub.subname[s]);
//		}
//
//		float sum_sub = 0;
//		for (int k = 0; k < 3; k++)
//			sum_sub += s_arr[i].sub.subname[k];
//		s_arr[i].sub.subname[3] = sum_sub;
//		s_arr[i].sub.subname[4] = 0;
//		s_arr[i].avg = sum_sub / 3;
//		i++;
//	}
//
//	// rank
//	for (size_t rx = 0; rx < cnt; rx++)
//		for (size_t cx = 0; cx < cnt; cx++)
//			if (s_arr[rx].avg > s_arr[cx].avg) s_arr[cx].sub.subname[4]++;
//
//	printf("����	\t����\t����\t����\t����\t����\t���\n");
//	printf("----------------------------------------\n");
//	for (int i = 0; i < cnt; i++) {
//		printf("%s\t", (s_arr + i)->name);
//		for (int j = 0; j < 4; j++)
//			printf("%d\t", (s_arr + i)->sub.subname[j]);
//		printf("%d\t%2f\n", (s_arr + i)->sub.subname[4], (s_arr + i)->avg);
//	}
//
//	free(s_arr);
//	free(order);
//
//	return 0;
//}
