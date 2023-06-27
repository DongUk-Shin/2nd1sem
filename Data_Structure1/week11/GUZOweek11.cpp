// 스택 두 개로 큐 구현
// 숫자 배열 출력

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int stk[MAX_SIZE];
    int top;
} stack_type;

typedef struct {
    stack_type stk1;
    stack_type stk2;
} queue_type;

void init_stack(stack_type* s) {
    s->top = -1;
}

int is_stack_empty(stack_type* s) {
    return s->top == -1;
}

int is_stack_full(stack_type* s) {
    return s->top == MAX_SIZE - 1;
}

void push(stack_type* s, int e) {
    if (is_stack_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->stk[++s->top] = e;
}

int pop(stack_type* s) {
    if (is_stack_empty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->stk[s->top--];
}

void init_queue(queue_type* q) {
    init_stack(&q->stk1);
    init_stack(&q->stk2);
}

int is_queue_empty(queue_type* q) {
    return is_stack_empty(&q->stk1) && is_stack_empty(&q->stk2);
}

int is_queue_full(queue_type* q) {
    return is_stack_full(&q->stk1) && is_stack_full(&q->stk2);
}

void enqueue(queue_type* q, int e) {
    if (is_queue_full(q)) {
        printf("Queue is full\n");
        return;
    }
    push(&q->stk2, e);
}

int dequeue(queue_type* q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    if (is_stack_empty(&q->stk1)) {
        while (!is_stack_empty(&q->stk2)) {
            push(&q->stk1, pop(&q->stk2));
        }
    }
    return pop(&q->stk1);
}

int main() {
    queue_type q;
    init_queue(&q);
    enqueue(&q, 0);
    enqueue(&q, 1);

    int n, x, y;
    printf("숫자 입력: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        x = dequeue(&q);
        printf("%d ", x);
        y = dequeue(&q);
        enqueue(&q, y);
        enqueue(&q, x + y);
    }

    printf("\n");
    return 0;
}
