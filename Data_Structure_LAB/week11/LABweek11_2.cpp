#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct ListNodeType {
    int data;
    struct ListNodeType* link;
} ListNodeType;

ListNodeType* insert_first(ListNodeType* head, int item){
    ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}

ListNodeType* insert(ListNodeType* head, ListNodeType *prev, int item) {
    ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
    p->data = item;
    p->link = prev->link;
    prev->link = p;
    return head;
}

ListNodeType* delete_first(ListNodeType* head) {
    ListNodeType* p;
    if (head == NULL) return NULL;
    p = head;
    head = p->link;
    free(p);
    return head;
}

ListNodeType* delete1(ListNodeType* head, ListNodeType* prev) {
    ListNodeType* p;
    p = prev->link;
    prev->link = p->link;
    free(p);
    return head;
}

void print_list(ListNodeType* head) {
    for (ListNodeType* p = head; p != NULL; p = p->link)
        printf("%d - > ", p->data);
    printf("\n");
}

int main() {
    ListNodeType* head = NULL;


    head = insert_first(head, 10);
    print_list(head);
    head = insert_first(head, 20);
    print_list(head);
    head = insert_first(head, 30);
    print_list(head);
    head = insert_first(head, 40);
    print_list(head);
    head = insert(head, head, 50);
    print_list(head);

    head = delete_first(head);
    print_list(head);
    delete1(head, head);
    print_list(head);
    return 0;
}
