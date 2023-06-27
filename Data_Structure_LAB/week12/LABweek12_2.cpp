#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {	
	int data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* rear;
} LinkedQueueType;

void init(LinkedQueueType* q) {
	q->rear = NULL;
}

int isQueueEmpty(LinkedQueueType* q) {
	return q->rear == NULL;
}

void enqueue(LinkedQueueType* q, int data) {
	QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
	p->data = data;
	p->link = NULL;

	if (isQueueEmpty(q)) {	
		q->rear = p;
		p->link = p; 
	}
	else {
		p->link = q->rear->link;  
		q->rear->link = p;  
		q->rear = p; 
	}
}

int dequeue(LinkedQueueType* q) {
	if (isQueueEmpty(q)) {
		printf("Queue is empty.\n");
		return -1;
	}

	QueueNode* p = q->rear->link;
	int data = p->data;

	if (p == q->rear) {
		q->rear = NULL;  
	}
	else {
		q->rear->link = p->link;
	}

	free(p);
	return data;
}

void printQueue(LinkedQueueType* q) {
	if (isQueueEmpty(q)) {
		printf("Queue is empty.\n");
		return;
	}


	QueueNode* p = q->rear->link;
	printf("?: ");

	do {
		printf("%d ", p->data);
		p = p->link;
	} while (p != q->rear->link);


	printf("rear: %d\n", q->rear->data);
}

int main() {
	LinkedQueueType q;
	init(&q);

	enqueue(&q, 1); printQueue(&q);
	enqueue(&q, 2); printQueue(&q);
	enqueue(&q, 3); printQueue(&q);
	dequeue(&q);    printQueue(&q);
	enqueue(&q, 4); printQueue(&q);
	dequeue(&q);    printQueue(&q);
	dequeue(&q);    printQueue(&q);
	enqueue(&q, 5); printQueue(&q);

	return 0;
}
