

#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element; 
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType*q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType q) {
	return ((q.rear + 1) % MAX_QUEUE_SIZE == q.front);
}

int is_empty(QueueType q) {
	return (q.rear == q.front);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
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

void enqueue(QueueType* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void) {
	QueueType q;
	init_queue(&q);

    enqueue(&q, 1);
    queue_print(&q);
    enqueue(&q, 2);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);
    enqueue(&q, 3);
    queue_print(&q);
    enqueue(&q, 4);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);
	enqueue(&q, 5);
    queue_print(&q);
    enqueue(&q, 6);
    queue_print(&q);
}
