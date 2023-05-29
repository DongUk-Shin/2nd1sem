
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
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i > q->rear)
            printf("#|");
        else
            printf("%d|", q->data[i]);
    }
	printf("\n");
}

int is_full(QueueType q) {
	return (q.rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(QueueType q) {
	return (q.rear == q.front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	return q->data[++(q->front)];
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
