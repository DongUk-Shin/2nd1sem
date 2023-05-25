#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
} TreeNode;

void postorder(TreeNode *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

void pretorder(TreeNode *root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		pretorder(root->left);
		pretorder(root->right);
	}
}

void inorder(TreeNode *root) {
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
	printf("%d ", p->data);
	return p;
}

TreeNode *cons_list(int t[], int i) {
	if (t[i] != NULL) {
		TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
		root = make_node(t[i]);

		if (root != NULL) {
			root->left = cons_list(t, i * 2);
			root->right = cons_list(t, (i * 2) + 1);
		}
		return root;
	}
	else
		return NULL;
}


int main(void) {
	TreeNode *T = NULL;

	int t[32];
	for (int i = 0; i < 32; i++)
		t[i] = NULL;
	t[1] = 1;
	t[2] = 2;
	t[3] = 3;
	t[4] = 4;
	t[5] = 5;
	t[6] = 6;
	t[9] = 7;
	t[10] = 8;
	t[13] = 9;

	T = cons_list(t, 1);
	pretorder(T);
	inorder(T);
	postorder(T);

	printf("\n");
	return 0;
}
