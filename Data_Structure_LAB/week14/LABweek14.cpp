//스레드 이진 트리 중위 순회
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
} TreeNode;

TreeNode* make_node(int data, int is_thread) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->is_thread = is_thread;
	//printf("%d ", p->data);
	return p;
}

TreeNode* find_successor(TreeNode* q) {
    TreeNode* node = q->right; //오른쪽으로 이동
    if (node == NULL || q->is_thread == TRUE)
        return node; 
    while (node->left != NULL) 
        node = node->left;
    return node;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;
	do {
		printf("[%d] -> ", q->data);
		q = find_successor(q);//다음 노드를 찾는다
	} while (q != NULL);
}

TreeNode* cons_thread_tree() {
    TreeNode* root = make_node(1, 0);
    TreeNode* node2 = make_node(2, 0);
    TreeNode* node3 = make_node(3, 0);
    TreeNode* node4 = make_node(4, 0);
    TreeNode* node5 = make_node(5, 1);
    TreeNode* node6 = make_node(6, 0);
    TreeNode* node7 = make_node(7, 1);
    TreeNode* node8 = make_node(8, 1);
    TreeNode* node9 = make_node(9, 1);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node4->right = node7;
    node5->left = node8;
    node6->right = node9;

    node7->right = node2;
    node8->right = node5;
    node5->right = root;
    node9->right = node3;
    return root;
}

int main(void) {
	
	TreeNode * root = cons_thread_tree();
    printf("스레드 노드 중위순회: ");
	thread_inorder(root);
	printf("\n");

	return 0;
}
