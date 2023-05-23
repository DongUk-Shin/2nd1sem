//계산기 입력(중위) -> 후위 -> 트리 -> 트리연산
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int pie(char oper) { //우선순위
    if (oper == '(') {
        return 3;
    } else if (oper == '*' || oper == '/') {
        return 2;
    } else if (oper == '+' || oper == '-') {
        return 1;
    } else {
        return 0;
    }
}
int pis(char oper) {
    if (oper == '(') {
        return 0;
    } else if (oper == '*' || oper == '/') {
        return 2;
    } else if (oper == '+' || oper == '-') {
        return 1;
    } else {
        return -1;
    }
}

char* postfix(char exp[], char pexp[]) { //중위 -> 후위 함수
    int i = 0, j = 0;
    char ch;
    stack_type s;
    init(&s);
    
    while ((ch = exp[i++]) != '\0') {
        if (ch == ' ') continue; //공백일 시 continue

        if (ch == '(' || ch == '[' || ch == '{') {
            stack_push(&s, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            while (!is_empty(s) && peek(s) != '(' && peek(s) != '[' && peek(s) != '{') {
                pexp[j++] = stack_pop(&s);
            }
            if (!is_empty(s) && ((ch == ')' && peek(s) == '(') || 
                                 (ch == ']' && peek(s) == '[') || 
                                 (ch == '}' && peek(s) == '{'))) {
                stack_pop(&s); // 왼쪽 괄호 제거
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!is_empty(s) && pis(peek(s)) >= pie(ch)) {
                pexp[j++] = stack_pop(&s);
            }
            stack_push(&s, ch);
        }
        else { //ch가 숫자일 때 
            pexp[j++] = ch;
        }
    }
    while (!is_empty(s)) {
        pexp[j++] = stack_pop(&s);
    }
    pexp[j] = '\0';
    return pexp;
}

char* get_exp(char exp[]) { //수식 입력 함수
    printf("수식을 입력하세요: ");
    scanf("%[^\n]", exp);
    return exp;
}

/*-------------------------*/

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void tree_push(TreeNode *p) {
    if (top < SIZE -1) 
        stack[++top] = p;
}
TreeNode *tree_pop() {
    TreeNode *p = NULL;
    if (top >= 0) 
        p = stack[top--];
    return p;
}

int eval_oper(int opnd1, int opnd2, char oper) { //연산자 계산
    switch (oper) {
    case '+':
        return opnd1 + opnd2;
    case '-':
        return opnd1 - opnd2;
    case '*':
        return opnd1 * opnd2;
    case '/':
        return opnd1 / opnd2;
    case '^':
        return pow(opnd1, opnd2);
    }
}

int eval(TreeNode *root) { //노드 두개 연산
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return root->data;
    else {
        int opnd1 = eval(root->left);
        int opnd2 = eval(root->right);
        printf("노드 두개 연산: %d %c %d \n", opnd1, root->data, opnd2);
        return eval_oper(opnd1, opnd2, root->data);
    }
    return 0;
}

TreeNode* cons_exptree(char postfix[]) { //후위 -> 트리
    stack_type s;
    init(&s);
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        
        if (isdigit(ch)) {
            int num = ch - '0'; // 숫자 문자를 정수로 변환
            newNode->data = num;
            printf("노드 :%d \n", num);
            tree_push(newNode);
        } else {
            printf("노드 :%c \n", ch);
            newNode->right = tree_pop();
            newNode->left = tree_pop();
            tree_push(newNode);
        }
    }
    return tree_pop();
}

int main(void) {
    char exp[MAX_SIZE];
    char post[MAX_SIZE];
    get_exp(exp);
    postfix(exp, post);
    printf("후위: %s\n", post);
    TreeNode *root = cons_exptree(post);

    printf("계산 결과: %d \n", eval(root));
    return 0;
}
