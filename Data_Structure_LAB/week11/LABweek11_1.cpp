#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int size;
}ArrayListType;

void init(ArrayListType *L) {
    L->size = 0;
}

int is_empty(ArrayListType* L) {
    return L->size == 0;
}

int is_full(ArrayListType* L) {
    return L->size == MAX;
}

void insert_first(ArrayListType* L, int item) {
    if (!is_full(L)) {
        for (int i = L->size - 1; i >= 0; i--) {
            L->data[i + 1] = L->data[i];
        }
        L->size++;
        L->data[0] = item;
    }
}

void insert(ArrayListType* L, int pos, int item) {
    if (!is_full(L)) {
        for (int i = L->size - 1; i >= pos; i--) {
            L->data[i + 1] = L->data[i];
        }
        L->size++;
        L->data[pos] = item;
    }
}

int delete1(ArrayListType* L, int pos) {
    if (is_empty(L) || pos < 0 || pos >= L->size) {
        printf("위치오류");
        return -1;
    }

    int item = L->data[pos];
    for (int i = pos; i < L->size - 1; i++) {
        L->data[i] = L->data[i + 1];
    }

    L->size--;
    return item;
}


int delete_first(ArrayListType* L) {
    int item;
    if (!is_empty(L)) {
        item = L->data[0];
        for (int i = 0; i < L->size - 1; i++) {
            L->data[i] = L->data[i + 1];
        }
        L->size--;
        return item;
    }
    return -1;
}

void print_list(ArrayListType* L) {
    if (!is_empty(L)) {
        for (int i = 0; i < L->size; i++) {
            printf("%d ", L->data[i]);
        }
        printf("\nsize: %d\n", L->size);
    }
    else
        printf("\nempty\n");
}


int main() {
    ArrayListType list;
    init(&list);
    insert_first(&list, 10);
    print_list(&list);
    insert_first(&list, 20);
    print_list(&list);
    insert_first(&list, 30);
    print_list(&list);
    insert(&list, 0, 40);
    print_list(&list);
    insert(&list, 1, 50);
    print_list(&list);
    delete_first(&list);
    print_list(&list);
    delete1(&list, 1);
    print_list(&list);
    //printf("%d\n", delete_first(&list));
    //print_list(&list);
    return 0;
}
