#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNodeType {
    int data;
    struct ListNodeType* link;
} ListNodeType;

ListNodeType* insert_first(ListNodeType* head, int val) {
    ListNodeType* new_node = (ListNodeType*) malloc(sizeof(ListNodeType));
    new_node->data = val;
    new_node->link = head;
    head = new_node;
    return head;
}

ListNodeType* cons_list(ListNodeType* head) {
    for (int i = 0; i < 50; i++) {
        int val = rand() % 10 + 1;  // 1~10 사이의 난수 생성
        head = insert_first(head, val);
    }
    return head;
}

int count(ListNodeType* head, int key) {
    int count = 0;
    ListNodeType* p = head;
    while (p != NULL) {
        if (p->data == key) {
            count++;
        }
        p = p->link;
    }
    return count;
}

void print_list(ListNodeType* head) {
    for (ListNodeType* p = head; p != NULL; p = p->link)
        printf("%d - > ", p->data);
    printf("\n");
}

int main() {
    srand(time(NULL));          //난수 생성
    ListNodeType* head = NULL;  //초기화
    head = cons_list(head);     //리스트 생성
    int key = rand() % 10 + 1; 
    int num_nodes = count(head, key);
    printf("Key = %d / Num_nodes = %d\n", key, num_nodes);
    print_list(head);

    return 0;
}
