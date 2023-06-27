//계산기 입력(중위) -> 후위 -> 트리 -> 트리연산
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
/*   스택 상태 확인 함수
void stackprint(stack_type s) { 
    printf(" 스택: ");
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
char* postfix(char exp[], char post[]) { //중위 -> 후위 함수
    int i = 0, j = 0;
    char ch;
    stack_type s;
    init(&s);
    
    while ((ch = exp[i++]) != '\0') {
        if (ch == ' ') continue; //공백일 시 pass
        
        else if (ch == '(' || ch == '[' || ch == '{') stack_push(&s, ch);
        
        else if (ch == ')' || ch == ']' || ch == '}') {
            while (!is_empty(s) && peek(s) != '(' && peek(s) != '[' && peek(s) != '{') 
                post[j++] = stack_pop(&s);
            if (!is_empty(s) && ((ch == ')' && peek(s) == '(') || 
                                 (ch == ']' && peek(s) == '[') || 
                                 (ch == '}' && peek(s) == '{'))) {
                stack_pop(&s); // 왼쪽 괄호 제거
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
            while (!is_empty(s) && pis(peek(s)) >= pie(ch)) {
                post[j++] = stack_pop(&s);
            }
            stack_push(&s, ch);
        }
        else { //ch가 숫자일 때 
            post[j++] = ch;
        }
        //printf("ch: %c", ch);  스택, ch 상태 확인
        //stackprint(s);
    }
    while (!is_empty(s)) 
        post[j++] = stack_pop(&s);
    post[j] = '\0';
    
    return post;
}

char* get_exp(char exp[]) { //수식 입력 함수
    printf("수식을 입력하세요: ");
    scanf("%[^\n]", exp);
    return exp;
}
/*-------------------------*/

typedef struct TreeNode { //트리 노드
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
    }
}

int eval(TreeNode *root) { //노드 두개 연산 (전위)
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return root->data; //단말 노드인가(정수인가)
    int leftopnd = eval(root->left);
    int rightopnd = eval(root->right);
    printf("노드 연산: %d %c %d \n", leftopnd, root->data, rightopnd);
    return eval_oper(leftopnd, rightopnd, root->data);
}

TreeNode* cons_exptree(char post[]) { //후위 -> 트리
    int i = 0;
    char ch;
    printf("노드: ");
    while ((ch = post[i++]) != '\0') {
        TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        printf("[%c] ", ch);
        if (isdigit(ch)) { // 정수이면
            int num = ch - '0'; // 숫자 문자를 정수로 변환
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
    get_exp(exp); //수식 입력
    postfix(exp, post); //중위식 -> 후위식
    printf("후위: %s\n", post); 
    TreeNode *root = cons_exptree(post); //후위식 -> 트리
    printf("계산 결과: %d \n\n", eval(root));
    return 0;
}
