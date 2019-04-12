#ifndef _LINUX_LIST_H
#define _LINUX_LIST_H
#if defined(__KERNEL__) || defined(_LVM_H_INCLUDE)
// #include <linux/prefetch.h>
/ --------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*Simple doubly linked list implementation.
*
* Some of the internal functions("__xxx") are useful when
* manipulating whole lists rather than single entries, as
* sometimes we already know the next / prev entries and we can
* generate better code by using them directly rather than
* using the generic single - entry routines.
-------------------------------------------------------------------------- - *-
struct list_head
{
	struct list_head *next, *prev;
};
#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
struct list_head name = LIST_HEAD_INIT(name)
#define INIT_LIST_HEAD(ptr) do { \
(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*Insert a new entry between two known consecutive entries.
*
* This is only for internal list manipulation where we know
* the prev / next entries already!
-------------------------------------------------------------------------- - *-
static inline void __list_add(struct list_head *new,								// list_add => Stack
	struct list_head *prev,		
	struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_add_tail - add a new entry
* @new: new entry to be added
* @head: list head to add it before
*
* Insert a new entry before the specified head.
* This is useful for implementing queues.
-------------------------------------------------------------------------- - *-
static inline void list_add_tail(struct list_head *new, struct list_head *head)				// list_add_tail => Queue
{
	__list_add(new, head->prev, head);
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*Delete a list entry by making the prev / next entries
* point to each other.
*
* This is only for internal list manipulation where we know
* the prev / next entries already!
-------------------------------------------------------------------------- - *-
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;				// entry앞과 뒤를 연결
	prev->next = next;
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_del - deletes entry from list.
* @entry: the element to delete from the list.
* Note: list_empty on entry does not return true after this, the entry is in an undefined state.
-------------------------------------------------------------------------- - *-
static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	entry->next = (void *)0;			// entry(삭제대상)은 혼자 떠있게 됨(앞뒤와의 연결 모두끊김)
	entry->prev = (void *)0;
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_del_init - deletes entry from list and reinitialize it.
* @entry: the element to delete from the list.
-------------------------------------------------------------------------- - *-
static inline void list_del_init(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
	INIT_LIST_HEAD(entry);
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_move - delete from one list and add as another's head
* @list: the entry to move
* @head: the head that will precede our entry
-------------------------------------------------------------------------- - *-
static inline void list_move(struct list_head *list, struct list_head *head)
{
	__list_del(list->prev, list->next);		// list가 붕떠있게 함(이 메모리공간은 list란 이름의 변수가 잡고 있으므로 현재 접근은 가능)
	list_add(list, head);					// 붕떠있는 list를 head뒤(head와 head->next사이)로 연결(추가)
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_move_tail - delete from one list and add as another's tail
* @list: the entry to move
* @head: the head that will follow our entry
-------------------------------------------------------------------------- - *-
static inline void list_move_tail(struct list_head *list,
	struct list_head *head)
{
	__list_del(list->prev, list->next);
	list_add_tail(list, head);
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_empty - tests whether a list is empty
* @head: the list to test.
-------------------------------------------------------------------------- - *-
static inline int list_empty(struct list_head *head)
{
	return head->next == head;
}
static inline void __list_splice(struct list_head *list,
	struct list_head *head)
{
	struct list_head *first = list->next;
	struct list_head *last = list->prev;
	struct list_head *at = head->next;
	first->prev = head;
	head->next = first;
	last->next = at;
	at->prev = last;
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_splice - join two lists	
* @list: the new list to add.
* @head: the place to add it in the first list.
*-
static inline void list_splice(struct list_head *list, struct list_head *head)
{
	if (!list_empty(list))
		__list_splice(list, head);
}
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_splice_init - join two lists and reinitialise the emptied list.
* @list: the new list to add.
* @head: the place to add it in the first list.
*
* The list at @list is reinitialised
-------------------------------------------------------------------------- - *-
static inline void list_splice_init(struct list_head *list,
	struct list_head *head)
{
	if (!list_empty(list)) {
		__list_splice(list, head);
		INIT_LIST_HEAD(list);
	}
}

typedef struct type {

	 int member
}type;

type ptr;
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_entry - get the struct for this entry			// 가장 중요 => 보안을 위한 메커니즘 
* @ptr: the &struct list_head pointer.	// 무시		// 이 매크로를 숨기면 리스트를 떠돌기만 할 뿐, 실데이터에 접근하지 못함
* @type: the type of the struct this is embedded in.
* @member: the name of the list_struct within the struct.
-------------------------------------------------------------------------- - *-
#define list_entry(ptr, type, member) \								// (unsigned long)(&((type *)0)->member)) => type이라는 구조체 내에서 특정 멤버(그 구조체 내의 멤버)의 오프셋값
((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))		// 결국 type형의 구조체변수 내의 멤버 member의 이름으로 자기가 속한 구조체의 주소를 알수 있게 함		
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_for_each - iterate over a list
* @pos: the &struct list_head to use as a loop counter.
* @head: the head for your list.
-------------------------------------------------------------------------- - *-
#define list_for_each(pos, head) \
for (pos = (head)->next, prefetch(pos->next); pos != (head); \
pos = pos->next, prefetch(pos->next))
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_for_each_prev - iterate over a list backwards
* @pos: the &struct list_head to use as a loop counter.
* @head: the head for your list.
-------------------------------------------------------------------------- - *-
#define list_for_each_prev(pos, head) \
for (pos = (head)->prev, prefetch(pos->prev); pos != (head); \
pos = pos->prev, prefetch(pos->prev))
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_for_each_safe
* iterate over a list safe against removal of list entry
* @pos: the &struct list_head to use as a loop counter.
* @n: another &struct list_head to use as temporary storage
* @head: the head for your list.
-------------------------------------------------------------------------- - *-
#define list_for_each_safe(pos, n, head) \				
for (pos = (head)->next, n = pos->next; pos != (head); \	// pos->next노드를 n에 기억해놓음 => 중간에 링크가 깨지더라도 그 다음 탐색이 안전하게 수행되게 함
pos = n, n = pos->next)
/ -*-------------------------------------------------------------------------- -
-------------------------------------------------------------------------- -
*list_for_each_entry
* iterate over list of given type
* @pos: the type * to use as a loop counter.
* @head: the head for your list.
* @member: the name of the list_struct within the struct.
-------------------------------------------------------------------------- - *-
#define list_for_each_entry(pos, head, member) \		// 
for (pos = list_entry((head)->next, typeof(*pos), member), \	// typeof(*pos) => pos라는 구조체의 주소가 아닌, 구조체자체(pos가 가리키는 값, *pos)를 넣은 것
prefetch(pos->member.next); \
& pos->member != (head); \
pos = list_entry(pos->member.next, typeof(*pos), member), \
prefetch(pos->member.next))
#endif /- __KERNEL__ || _LVM_H_INCLUDE *-
#endif