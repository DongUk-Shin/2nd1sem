//?쟾?쐞 - ?닚?솚
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == SIZE - 1;
}

void push(TreeNode *p) {
    if (!is_full()) 
        stack[++top] = p;
}


TreeNode *pop() {
    TreeNode *p = NULL;
    if (!is_empty())
        p = stack[top--];
    return p;
}

TreeNode* peek() {
    TreeNode* p = NULL;
    if (!is_empty())
        p = stack[top];
    return p;
}



void preorder_iter(TreeNode *root) { 
    push(root);
    while (!is_empty()) {
        TreeNode *node = pop();
        if (node != NULL) {
            printf("[%c] ", node->data);
            push(node->right);
            push(node->left);
        }
    }
}

void postorder_iter(TreeNode* root) {
    TreeNode* prev = NULL;
    while (!is_empty() || root != NULL) {
        if (root != NULL) {
            push(root);
            root = root->left;
        } else {
            TreeNode* node = peek();
            if (node->right == NULL || node->right == prev) {
                printf("[%c] ", node->data);
                prev = node;
                pop();
            } else {
                root = node->right;
            }
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
    printf("후위: ");
    postorder_iter(root);
    printf("\n후위: ");
    postorder_iter(root);
    printf("\n후위: ");
    postorder_iter(root);
    printf("\n전위: ");
    preorder_iter(root);
    printf("\n");
    return 0;
}
