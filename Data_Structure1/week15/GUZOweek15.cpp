//���� �Է�(����) -> ���� -> Ʈ�� -> Ʈ������
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct{
	char stk[MAX_SIZE];
	int top;
}stack_type;
void init(stack_type* s) {
	(*s).top = -1;
}
int is_empty(stack_type s) {
	return (s.top == - 1);
}
int is_full(stack_type s) {
	return (s.top == MAX_SIZE - 1);
}
void stack_push(stack_type* s, char ch) {
	if (is_full(*s)) {
		fprintf(stderr, "error");
		exit(1);
	}
	(*s).stk[++(*s).top] = ch;
}
int stack_pop(stack_type* s) {
	if (is_empty(*s)) {
		fprintf(stderr, "error");
		exit(1);
	}
	return (*s).stk[(*s).top--];
}
int peek(stack_type s) {
	if (is_empty(s)) {
		fprintf(stderr, "error");
		exit(1);
	}
	return (s).stk[(s).top];
}
/*   ���� ���� Ȯ�� �Լ�
void stackprint(stack_type s) { 
    printf(" ����: ");
    if (!is_empty(s)) {
        for (int i=0; i<=s.top; i++)
            printf("%c ", s.stk[i]);
    }
    else 
        printf("empty");
    printf("\n");
}
*/
int pie(char oper) {
    if (oper == '(' || oper == '[' || oper == '{') 
        return 3;
    else if (oper == '*' || oper == '/') 
        return 2;
    else if (oper == '+' || oper == '-') 
        return 1;
    else 
        return 0;
}

int pis(char oper) {
    if (oper == '(' || oper == '[' || oper == '{') 
        return 0;
    else if (oper == '*' || oper == '/') 
        return 2;
    else if (oper == '+' || oper == '-') 
        return 1;
    else 
        return -1;
}
char* postfix(char exp[], char post[]) { //���� -> ���� �Լ�
    int i = 0, j = 0;
    char ch;
    stack_type s;
    init(&s);
    
    while ((ch = exp[i++]) != '\0') {
        if (ch == ' ') continue; //������ �� pass
        
        else if (ch == '(' || ch == '[' || ch == '{') stack_push(&s, ch);
        
        else if (ch == ')' || ch == ']' || ch == '}') {
            while (!is_empty(s) && peek(s) != '(' && peek(s) != '[' && peek(s) != '{') 
                post[j++] = stack_pop(&s);
            if (!is_empty(s) && ((ch == ')' && peek(s) == '(') || 
                                 (ch == ']' && peek(s) == '[') || 
                                 (ch == '}' && peek(s) == '{'))) {
                stack_pop(&s); // ���� ��ȣ ����
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
            while (!is_empty(s) && pis(peek(s)) >= pie(ch)) {
                post[j++] = stack_pop(&s);
            }
            stack_push(&s, ch);
        }
        else { //ch�� ������ �� 
            post[j++] = ch;
        }
        //printf("ch: %c", ch);  ����, ch ���� Ȯ��
        //stackprint(s);
    }
    while (!is_empty(s)) 
        post[j++] = stack_pop(&s);
    post[j] = '\0';
    
    return post;
}

char* get_exp(char exp[]) { //���� �Է� �Լ�
    printf("������ �Է��ϼ���: ");
    scanf("%[^\n]", exp);
    return exp;
}
/*-------------------------*/

typedef struct TreeNode { //Ʈ�� ���
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int top = -1;
TreeNode *stack[MAX_SIZE];

void tree_push(TreeNode *p) {
    if (top < MAX_SIZE -1) 
        stack[++top] = p;
}
TreeNode *tree_pop() {
    TreeNode *p = NULL;
    if (top >= 0) 
        p = stack[top--];
    return p;
}

int eval_oper(int opnd1, int opnd2, char oper) { //������ ���
    switch (oper) {
    case '+':
        return opnd1 + opnd2;
    case '-':
        return opnd1 - opnd2;
    case '*':
        return opnd1 * opnd2;
    case '/':
        return opnd1 / opnd2;
    }
}

int eval(TreeNode *root) { //��� �ΰ� ���� (����)
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return root->data; //�ܸ� ����ΰ�(�����ΰ�)
    int leftopnd = eval(root->left);
    int rightopnd = eval(root->right);
    printf("��� ����: %d %c %d \n", leftopnd, root->data, rightopnd);
    return eval_oper(leftopnd, rightopnd, root->data);
}

TreeNode* cons_exptree(char post[]) { //���� -> Ʈ��
    int i = 0;
    char ch;
    printf("���: ");
    while ((ch = post[i++]) != '\0') {
        TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        printf("[%c] ", ch);
        if (isdigit(ch)) { // �����̸�
            int num = ch - '0'; // ���� ���ڸ� ������ ��ȯ
            newNode->data = num;
            tree_push(newNode);

        } else {
            newNode->right = tree_pop();
            newNode->left = tree_pop();
            tree_push(newNode);
        }
    }
    printf("\n");
    return tree_pop();
}

int main(void) {
    char exp[MAX_SIZE];
    char post[MAX_SIZE];
    get_exp(exp); //���� �Է�
    postfix(exp, post); //������ -> ������
    printf("����: %s\n", post); 
    TreeNode *root = cons_exptree(post); //������ -> Ʈ��
    printf("��� ���: %d \n\n", eval(root));
    return 0;
}
