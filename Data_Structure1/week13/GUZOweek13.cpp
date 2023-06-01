#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;
typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

void print_list(ListType *list) {
    for (ListNode *p = list->head; p != NULL; p = p->link) 
        printf("%d ", p->data);
    printf("\n");
}

void insert_last(ListType *list, int data) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->link = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->link = new_node;
        list->tail = new_node;
    }
    list->size++;
}

ListType* merge(ListType* list1, ListType* list2) {
    ListType* merged_list = (ListType*)malloc(sizeof(ListType));
    merged_list->size = list1->size + list2->size;
    merged_list->head = NULL;
    merged_list->tail = NULL;

    ListNode* p1 = list1->head;
    ListNode* p2 = list2->head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            insert_last(merged_list, p1->data);
            p1 = p1->link;
        } else {
            insert_last(merged_list, p2->data);
            p2 = p2->link;
        }
    }
    while (p1 != NULL) {
        insert_last(merged_list, p1->data);
        p1 = p1->link;
    }
    while (p2 != NULL) {
        insert_last(merged_list, p2->data);
        p2 = p2->link;
    }
    return merged_list;
}


int main(void) {
    ListType list1 = {0, NULL, NULL};
    ListType list2 = {0, NULL, NULL};

    for (int i = 3; i <= 30; i += 3) 
        insert_last(&list1, i);
    
    for (int i = 0; i <= 45; i += 5) 
        insert_last(&list2, i);
    
    print_list(&list1);
    print_list(&list2);

    ListType* merged_list = merge(&list1, &list2);
    print_list(merged_list);
}
