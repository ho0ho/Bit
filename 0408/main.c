#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#pragma warning(disable : 4996)

//struct engine {
//	int piston;
//	int fan;
//	int pipe;
//};
//
//struct car {
//	struct engine *sedan, *sports;
//};
//
//void hyundai(struct car *man) {
//	struct engine *e = man->sedan;		// chaining removal
//	e->piston = 50;
//	e->fan = 30;
//	e->pipe = 20;
//}
//
//void init_car(struct car *man) {
//	man->sedan = (struct engine *)malloc(sizeof(struct engine));
//	man->sports = (struct engine *)malloc(sizeof(struct engine));
//}
//
//int main() {
//	//struct car hi;
//	//init_car(&hi);				// pointer 초기화하고 사용해야함
//	//hyundai(&hi);
//	//printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan, hi.sedan->pipe);
//	//getchar("");
//
//	int arr[] = {}
//
//	return 0;
//}
//
///* 인접한 값과 비교해서 가장 큰 값을 맨뒤에 넣기 */
//void bubble_sort(int *arr, int size) {
//	for (size_t i = 0; i < size; i++) {
//		for(size_t = )
//	}
//}
//
///* 제일 작은 값을 찾아서 가장 앞에 위치 */
//void select_sort(int *arr, int size) {
//	int min, min_i;
//	for (size_t i = 0; i < size - 1; i++) {
//		min_i = i;
//		min = arr[i];			// 대입연산은 늘었지만 속도면에서 향상
//		for (size_t j = i + 1; j < size; j++) {
//			if (min > arr[j]) min = arr[i]; min_i = j;
//		}
//
//		/*swap(arr, i, )*/
//	}		
//}
//
///* 내앞쪽들이랑 비교(두번째부터 시작, 앞이 작으면 다 정렬된 것, 크면 작은 것 찾을때까지만 비교 ) */
//void insert_sort(int *arr, int size) {
//	for (size_t i = 1; i < size, i++) {
//		for(size_t j = )
//	}
//}
//
///* 비교,교환과정을 인덱스배열을 통해 진행하고 원본데이터는 최종단계에서 접근 */
//void indirect_insert_sort(int *arr, int size) {
//
//}
//
///* 대용량 데이터를 부분으로 나누어(with 간격) 각각 정렬 */
//void shell_sort() {		// 비교의 폭을 바로 앞/뒤가 아닌 크게 잡아서, "제위치에서 크게 벗어난 값"을 빠르게 제 위치로 이동시킴
//}

//#define swap(a, b) do {int t; t = a; a = b; b = t;} while(0)		// 매크로. 끝에 ;없어야 실제코드 뒤에 ;랑 같이 인식됨
//
//int partition(int *arr, int start, int end) {	
//	int pv = arr[start];
//	int small = start;
//	int large = end + 1;
//	while (small < large) {
//		while (++small <= end && arr[small] < pv) ;
//		while (--large > start && arr[large] > pv);
//		if (small < large)
//			swap(arr[small], arr[large]);
//	}
//	swap(arr[large], pv);
//	return large;
//}
//
///* pivot */
//void myqsort(int *arr, int start, int end) {
//	if (start < end) {
//		int pv = partition(arr, start, end);		// 정렬은 여기서 일어남
//		qsort(arr, start, pv - 1);
//		qsort(arr, pv + 1, end);
//	}
//}
//
void isort(int a[], int n) {
	int i, j, t;
	for (i = 1; i < n; i++) {
		t = a[i];
		j = i;
		while (a[j - 1] > t && j > 0) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}
//
//int mystringcmp(char *str1, char *str2) {
//	while (*str1++ == *str2++);
//	if (--str1 < --str2) return -1;
//	else if (str1 > str2) return 1;
//	else return 0;
//}
//
//void isort_ch(char (*a)[7], int n) { 
//	int i, j;
//	char f[7];
//	for (i = 1; i < n; i++) {
//		strcpy(f, a[i]);
//		j = i;
//		while (j > 0 && strcmp(a[j - 1], f) > 0) {
//			strcpy(a[j], a[j - 1]);
//			j--;
//		}
//		strcpy(a[j], f);
//	}
//}
//
//int main() {
//	int arr[] = { 5, 1, 6, 2, 7, 3, 9, 0, 4, 8 };
//	//myqsort(arr, 0, 9);
//	//for (int i = 0; i < 10; i++)
//	//	printf("%d ", arr[i]);
//	//getchar("");
//	
//	char student[][7] = { "배상우","소준영","손병국","고승희","구민교","김기백","김다희",
//						"박선애","박성경","신동열","이경수","조희은","황상진","강상헌",
//						"이호세","전하람","이승연","정낙현","조민희","이인찬" };
//
//	isort_ch(student, 20);
//	for (int i = 0; i < 20; i++)
//		printf("%s ", student[i]);
//	getchar("");
//
//
//
//	return 0;
//}

//void cold() { puts("cold"); }
//void hot() { puts("hot"); }
//
//void aircon(void(*p)(void)) { p(); }			//// call back function
//
//int main() {
//	aircon(cold);
//	aircon(hot);
//	
//	getchar("");
//	return 0;
//}

//
//int comp_i(const void *a, const void *b) {
//	return (*(int *)a - *(int *)b);
//}
//
//int comp_d(const void *a, const void *b) {
//	if (*(double *)a > *(double *)b) return 1;
//	else if (*(double *)a < *(double *)b) return -1;
//	else return 0;
//}
//
//int comp_s(const void *a, const void *b) {
//	return strcmp(*(char *)a, *(char *)b);
//}
//
//void print_int(int *arr, int size) {
//	for (size_t i = 0; i < size; i++)
//		printf("%d   ", arr[i]);
//	printf("\n");
//}
//
//void print_double(double *arr, int size) {
//	for (size_t i = 0; i < size; i++)
//		printf("%.1f ", arr[i]);
//	printf("\n");
//}
//
//int main() {
//	int arri[] = { 3, 4, 5, 1, 2 };
//	double arrd[] = { 3.2, 5.6, 1.2, 4.3, 4.6, 4.5, 7.2, 2.4, 9.1 };
//	char *student[] = { "배상우","소준영","손병국","고승희","구민교","김기백","김다희",
//						"박선애","박성경","신동열","이경수","조희은","황상진","강상헌",
//						"이호세","전하람","이승연","정낙현","조민희","이인찬" };
//	qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
//	print_int(arri, 5);
//	qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
//	print_double(arrd, sizeof(arrd) / sizeof(arrd[0]));
//	qsort(student, sizeof(student) / sizeof(student[0]), sizeof(student[0]), comp_s);
//	getchar("");
//
//	return 0;
//}
//
//typedef struct _sales {
//	char itemname[20];
//	int unitprice;
//	int count;
//	int amount;
//} Sales;
//
//int prd_item(const void *a, const void *b) {
//	return strcmp((*(Sales *)a).itemname, (*(Sales *)b).itemname);
//}
//
//int main() {
//	Sales prd[5] = {{ "ccc", 10,90,900 },
//					{ "aaa", 20,80,1600 },
//					{ "ddd", 30,70,2100 },
//					{ "eee", 40,60,2400 },
//					{ "bbb", 50,50,2500 }
//	};
//
//	int dx;
//	qsort(prd, 5, sizeof(prd[0]), prd_item);
//
//	for (dx = 0; dx < 5; dx++)
//		printf("%s %d %d %d\n", prd[dx].itemname, prd[dx].unitprice, prd[dx].count, prd[dx].amount);
//	getchar("");
//	return 0;
//}

//typedef struct _node {
//	char name[10];
//	struct _node *next;
//} Node;
//
//int cmp_node(const void *a, const void *b) {
//	return strcmp( (*(Node **)a)->name, (*(Node **)b)->name  );
////}
//
//int main() {
//	Node *k[4];			// k : Node **타입
//	Node *p = (Node *)malloc(sizeof(Node));
//	strcpy(p->name, "ccc");
//	p->next = NULL;
//
//	Node *q = (Node *)malloc(sizeof(Node));
//	strcpy(q->name, "aaa");
//	q->next = NULL;
//
//	k[0] = p;
//	k[1] = q;
//	k[2] = (Node *)malloc(sizeof(Node));
//	strcpy(k[2]->name, "bbb");
//	k[2]->next = NULL;
//
//	qsort(k, 3, sizeof(Node *), cmp_node);
//	for (int i = 0; i < 3; i++)
//		printf("%s\n", k[i]->name);
//	getchar("");
//	return 0;
//}

typedef int(*FCMP)(const void *, const void *);

int cmp_i(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int cmp_s(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

void func(void *arr, int size, int sizeCnt, FCMP fcmp) {
	printf("%d\n", fcmp(arr, (char *)arr + sizeCnt));
}

//int main() {
//	int a[5] = { 100000, 3, 1, 5, 2 };
//	char b[10][10] = { "aaaa", "aaaa" };
//
//	func(a, 5, sizeof(int), cmp_i);
//	/*func(b, 2, sizeof(b[0]), cmp_s);*/
//	getchar("");
//	return 0;
//}
//
//int main() {
//
//	char **a;
//	char ***pa = &a;
//
//	char *b[2];			// char*가 2개인 배열 b
//	char c[2][3];
//	char *d[2][3] = { "aa", "bb", "cc", "dd", "ee", "ff" };
//	char(*e)[2][3];
//	char(*f[2])[3];		// char[3]을 가리키는(*) 요소 2개를 갖는 배열 f(배열포인터를 요소로 갖는 배열f)
//
//	/*char *(*pb)[2] = &b;*/
//	char **pb = b;
//	char(*pc)[3] = c;
//	char(**pe)[2][3] = &e;	// e는 배열이름이 아닌, 포인터변수이므로 &e가 맞음
//	char (**pf)[3] = f;
//
//	
//}

//int main() {
//	char *d[2][3];
//	char*(*pd)[3] = d;
//	char*(*ppd)[2][3] = &d;
//
//	char **dd[2][3];
//	char **(*pdd)[3] = dd;
//	char **(*ppdd)[2][3] = &dd;
//
//	char (*pdb[2])[3] = {}
//
//	return 0;
//}

#define STR_SIZE 20

typedef struct _item {
	char name[STR_SIZE];
	int price;
	int cnt;
	struct _item *next;
} Item;

typedef struct _list {
	Item *head;
	Item *tail;
} SalesList;

void init(SalesList *slist) {
	slist->head = (Item *)malloc(sizeof(Item));
	slist->tail = (Item *)malloc(sizeof(Item));
	slist->head->next = slist->tail;
	slist->tail->next = slist->tail;	// 매듭
}

Item *find(SalesList *slist, char *name) {
	Item *pfind = slist->head;
	Item *find = pfind->next;
	while (find != slist->tail) {
		if (strcmp(find->name, name) == 0)
			break;
		pfind = find;
		find = find->next;
	}
	if (find == slist->tail) return NULL;
	else return pfind;
}

int is_empty(SalesList *slist) { return (slist->head->next == slist->tail); }

void add(SalesList *slist, char *name, int price/*, int cnt*/) {
	if (find(slist, name)) return;		// 중복 거절

	Item *new_item = (Item *)malloc(sizeof(Item));
	strcpy(new_item->name, name);
	new_item->price = price;
	/*new_item->cnt = cnt;*/

	if (is_empty(slist)) {
		slist->head->next = new_item;
		new_item->next = slist->tail;
		return;
	}

	new_item->next = slist->head->next;
	(slist->head)->next = new_item;
}

void add_cnt(SalesList *slist, char *name, int cnt) {
	Item *pfind = find(slist, name);
	if (pfind) {
		Item *find = pfind->next;
		find->cnt = cnt;
	}
	/*else { printf("not exist\n"); }*/
}

Item *find_arr(Item **arr, int size, char *name) {
	size_t i = 0;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i]->name, name) == 0) break;
	}
	if (i < size) return arr[i];
	return NULL;	
}

void remove(SalesList *slist, Item **arr, int size, char *name) {
	Item *pf = find(slist, name);
	Item *arr_f = find_arr(arr, size, name);
	if (pf) {
		Item *f = pf->next;
		pf->next = f->next;

		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       

		free(f);
	}
}

void preView(FILE *fp) {
	fprintf(fp, "=========================\n");
	fprintf(fp, "\t\t삼성전자 온라인 매출현황\t\t\n");
	fprintf(fp, "===================\n");
	fprintf(fp, "\t상품명\t\t단가\t개수\t금액\n");
	fprintf(fp, "--------------------------------\n");
}

void view(SalesList *slist, FILE *fp) {
	int i = 0;
	Item *s = slist->head->next;	
	preView(fp);
	while (s != slist->tail) {
		fprintf(fp, "%d%15s\t%7d\t%7d%7d\n", ++i, s->name, s->price, s->cnt, (s->price * s->cnt));
		s = s->next;
	}
}

void listToArray(SalesList *slist, Item **p) {
	Item *f = slist->head;
	int i = 0;
	while (f->next != slist->tail) {
		*p++ = f->next;
		f = f->next;
	}
}

int comp_item(const void *a, const void *b) {
	return strcmp( (*(Item **)a)->name, (*(Item **)b)->name );
}

int comp_cnt(const void *a, const void *b) {
	return ((*(Item **)a)->cnt - (*(Item **)b)->cnt);
}

int comp_price(const void *a, const void *b) {
	return ((*(Item **)a)->price - (*(Item **)b)->price);
}

int comp_total(const void *a, const void *b) {
	int total_a = (*(Item **)a)->cnt * (*(Item **)a)->price;
	int total_b = (*(Item **)b)->cnt * (*(Item **)b)->price;
	return total_a - total_b;
}

typedef int(*COMP)(const void*, const void *);

int main() {
	SalesList SamSung;
	FILE *fr_item, *fr_sales, *fw;
	Item *arr_item[19];
	int menu_i, s;

	COMP cmp[] = { comp_item, comp_price, comp_cnt, comp_total };

	int price, cnt;
	char name[STR_SIZE];

	fr_item = fopen("item.txt", "r");
	fr_sales = fopen("sales.txt", "r");
	assert(fr_item && fr_sales);

	// setting
	init(&SamSung);

	while (!feof(fr_item)) {
		fscanf(fr_item, "%s %d", name, &price);
		add(&SamSung, name, price);
	}

	while (!feof(fr_sales)) {
		fscanf(fr_sales, "%s %d", name, &cnt);
		add_cnt(&SamSung, name, cnt);
	}

	/*view(&SamSung);*/

	// test
	while (1) {
		printf("==== M E N U =====\n");
		printf(" 1. 매출현황 출력\n");
		printf(" 2. 매출현황 내보내기\n");
		printf(" 3. 상품 찾기\n");
		printf(" 4. 상품 삭제\n");
		printf(" 5. 매출현황 배열\n");
		printf(" 6. 정렬\n");
		printf(" 7. 종료\n");
		printf("==================\n");

		printf("메뉴를 선택하시오  : ");
		scanf("%d", &menu_i);

		switch (menu_i) {
		case 1:
			view(&SamSung, stdout);
			break;
		case 2:
			fw = fopen("out.txt", "w");
			assert(fw);
			view(&SamSung, fw);
			printf("============================\n");
			printf("파일로 보내기 완성\n\n");
			break;
		case 3:
			printf("검색상품 입력: ");
			scanf("%s", name);
			printf("================================\n");
			printf("\t상품명\t\t단가\t개수\t금액\n");
			printf("--------------------------------\n");
			Item *pf = find(&SamSung, name);
			/*printf("%15s\t%10d\t%10d\t%10d", );*/
		case 4:


		case 5:
			// to array
			listToArray(&SamSung, arr_item);
			for (int i = 0; i < 19; i++)
				printf("%s ", arr_item[i]->name);
			break;
		case 6:
			// sort
			listToArray(&SamSung, arr_item);
			printf("정렬기준을 입력하세요\n");
			printf("상품명기준(0) / 단가기준(1) / 개수기준(2) / 판매금액기준(3):");
			scanf("%d", &s);
			qsort(arr_item, 19, sizeof(Item *), cmp[s]);
			for (int i = 1; i < 20;i++)
				printf("%d%15s\t%7d\t%7d%7d\n", i, arr_item[i - 1]->name, arr_item[i - 1]->price, arr_item[i-1]->cnt, arr_item[i-1]->price * arr_item[i-1]->cnt);
			break;
		case 7: 
			printf("종료합니다.\n"); break;
		default:
			printf("다시 입력하세요\n");
			break;
		}
	}

	view(&SamSung, stdout);

	fclose(fr_item);
	fclose(fr_sales);

	return 0;
}

