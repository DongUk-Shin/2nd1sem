#include <stdio.h>
#include <stdlib.h>
typedef struct ListNodeType {
	int data;
	struct ListNodeType *link;
}ListNodeType;

ListNodeType* insert_first(ListNodeType* head, int data) {
	ListNodeType *p = (ListNodeType*)malloc(sizeof(ListNodeType));
	p->data = data;

	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNodeType* insert_last(ListNodeType* head, int data) {
	ListNodeType *p = (ListNodeType*)malloc(sizeof(ListNodeType));
	p->data = data;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

void print_list(ListNodeType* head) {
	ListNodeType* p;
	if (head == NULL) 
		return;
	p = head->link;
	do {
		printf("%d ->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}

int main(void) {
	ListNodeType* list = NULL;

	list = insert_first(list, 10); print_list(list);
	list = insert_first(list, 20); print_list(list);
	list = insert_first(list, 30); print_list(list);
	list = insert_last(list, 40); print_list(list);
	list = insert_last(list, 50); print_list(list);
}
