#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element; 
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}dq_type;

void init_deque(dq_type*q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(dq_type q) {
	return ((q.rear + 1) % MAX_QUEUE_SIZE == q.front);
}

int is_empty(dq_type q) {
	return (q.rear == q.front);
}

void deque_print(dq_type* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(*q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
    printf("\n");
}

void add_rear(dq_type* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

void add_front(dq_type* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	
}

element delete_front(dq_type* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(dq_type* q) {
	int i = q->rear;
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[i];
}

element get_front(dq_type* q) {
	if (!is_empty(*q))
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(dq_type* q) {
	if (!is_empty(*q))
		return q->data[q->rear];
}

int main(void) {
	dq_type q;
	init_deque(&q);

	add_rear(&q, 1);
	deque_print(&q);
	add_rear(&q, 2);
	deque_print(&q);
	add_front(&q, 3);
	deque_print(&q);
	add_front(&q, 4);
	deque_print(&q);
	delete_rear(&q);
	deque_print(&q);
	delete_front(&q);
	deque_print(&q);
	add_front(&q, 5);
	deque_print(&q);
}
