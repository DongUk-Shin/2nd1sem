//전위 - 순환
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p) {
    if (top < SIZE -1) 
        stack[++top] = p;
}

TreeNode *pop() {
    TreeNode *p = NULL;
    if (top >= 0) 
        p = stack[top--];
    return p;
}

void preorder_iter(TreeNode *root) { 
    push(root);
    while (top >= 0) {
        TreeNode *node = pop();
        if (node) {
            printf("[%c] ", node->data);
            push(node->right);
            push(node->left);
        }
    }
}

TreeNode n1 = {'I', NULL, NULL}; 
TreeNode n2 = {'G', &n1, NULL}; 
TreeNode n3 = {'F', NULL, NULL}; 
TreeNode n4 = {'C', &n3, &n2}; 

TreeNode n5 = {'H', NULL, NULL}; 
TreeNode n6 = {'E', NULL, &n5}; 
TreeNode n7 = {'D', NULL, NULL}; 
TreeNode n8 = {'B', &n7, &n6}; 
TreeNode n9 = {'A', &n8, &n4}; 
TreeNode *root = &n9;

int main(void) {
    printf("전위: ");
    preorder_iter(root);
    printf("\n");
    return 0;
}
