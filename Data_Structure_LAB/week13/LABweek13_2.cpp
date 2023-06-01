#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
} TreeNode;

#define MAX 5
typedef TreeNode* element; 
typedef struct {
	int front;
	int rear;
	element data[MAX];
}QueueType;

void init_queue(QueueType*q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType q) {
	return ((q.rear + 1) % MAX == q.front);
}

int is_empty(QueueType q) {
	return (q.rear == q.front);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(*q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX);
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
    printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(*q)) {
		printf("Queue is full.");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(*q)) {
		printf("Queue is empty.\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}

void pretorder(TreeNode *root) { //전위
	if (root != NULL) {
		printf("[%d] ", root->data);
		pretorder(root->left);
		pretorder(root->right);
	}
}
void postorder(TreeNode *root) { //후위
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

void inorder(TreeNode *root) { //중위
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

TreeNode* make_node(int data) {
	TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

TreeNode *cons_list(int t[], int i) {
	if (i < 15 && t[i] != 0) {
		TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
		root = make_node(t[i]);

		if (root != NULL) {
			root->left = cons_list(t, (i * 2));
			root->right = cons_list(t, (i * 2) + 1);
		}
		return root;
	}
	else
		return NULL;
}

void level_order(TreeNode* root) {
	QueueType q;
	TreeNode *p = root;
	init_queue(&q);
	if (p == NULL) return;
	enqueue(&q, p);
	while (!is_empty(q)) {
		p = dequeue(&q);
		printf("[%d] ", p->data);
		if (p->left) 
			enqueue(&q, p->left);
		if (p->right) 
			enqueue(&q, p->right);
	}
}

int main(void) {
	TreeNode *T = NULL;

	int t[15] = { 0, 1, 2, 3, 4, 5, 6, 0, 0, 7, 8, 0, 0, 9};
	
	T = cons_list(t, 1); 
	printf("트리 (노드)\n전위: ");
	pretorder(T);		 printf("\n");

	printf("중위: ");
	inorder(T);			 printf("\n");

	printf("후위: ");
	postorder(T);		 printf("\n");

	printf("레벨: ");
	level_order(T);		 printf("\n\n");
	return 0;
}
