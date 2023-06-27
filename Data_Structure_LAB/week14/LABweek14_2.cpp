//루트부터 잎 노드까지, 각 경로상의 합의 최댓값
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* make_node(int data) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	//printf("%d ", p->data);
	return p;
}

TreeNode *cons_list(int t[], int i) {
	if (i < 16 && t[i] != 0) { //15까지
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

int sum_root2leaf(TreeNode* root, int sum) {
    if (root == NULL) return sum;

    sum += root->data;
    if (root->left == NULL && root->right == NULL) 
        return sum;

    int leftSum = sum_root2leaf(root->left, sum);
    int rightSum = sum_root2leaf(root->right, sum);
    return (leftSum > rightSum) ? leftSum : rightSum;  //최댓값
}

int findNodesWithOneChild(TreeNode *root) {
    if (root == NULL)
        return 0;
    
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        // 자식 노드가 하나인 경우
        printf("[%d] ", root->data);  // 또는 원하는 작업 수행
		return 1;
    }
    
    int count = findNodesWithOneChild(root->left) + findNodesWithOneChild(root->right);
	return count;
}

int main(void) {
    int t[] = {0, 1, 2, 3, 8, 4, 5, 6, 0, 0, 10, 0, 7, 9, 0, 5}; //크기 15
    TreeNode * root = NULL;
    root= cons_list(t, 1);
	printf("\n");

    int maxSum = sum_root2leaf(root, 0);
    printf("루트부터 잎 노드까지, 각 경로상의 합의 최댓값\n%d\n", maxSum);

	printf("%d", findNodesWithOneChild(root));
	return 0;
}