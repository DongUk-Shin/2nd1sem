#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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

void push(stack_type* s, char ch) {
	if (is_full(*s)) {
		fprintf(stderr, "error");
		exit(1);
	}
	(*s).stk[++(*s).top] = ch;
}

int pop(stack_type* s) {
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

double eval(char ch, double opnd1, double opnd2) {
	switch (ch) {
	case '+':
		return opnd1 + opnd2;
	case '-':
		return opnd1 - opnd2;
	case '*':
		return opnd1 * opnd2;
	case '/':
		return opnd1 / opnd2;
    case '^':  // 거듭제곱 연산 추가
        return pow(opnd1, opnd2);
	default:
		break;
	}
}

double eval_postfix(char exp[]) {
    stack_type s;
    init(&s);
    int i = 0;
    char ch;
    double oper1, oper2;

    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch)) {
            push(&s, (double)(ch - '0'));
        } 
        else {
            oper2 = pop(&s);
            oper1 = pop(&s);
            push(&s, eval(ch, oper1, oper2));
        }
    }
    return pop(&s);
}

int pie(char oper) {
    if (oper == '(' || oper == '[' || oper == '{') {
        return 4;
    } 
    else if (oper == '^') {
        return 3;
    } 
    else if (oper == '*' || oper == '/') {
        return 2;
    } 
    else if (oper == '+' || oper == '-') {
        return 1;
    } 
    else {
        return 0;
    }
}

int pis(char oper) {
    if (oper == '(' || oper == '[' || oper == '{') {
        return 0;
    } 
    else if (oper == '^') {
        return 3;
    } 
    else if (oper == '*' || oper == '/') {
        return 2;
    } 
    else if (oper == '+' || oper == '-') {
        return 1;
    } 
    else {
        return -1;
    }
}

char get_token(char exp[]) { //문자열의 자리수를 식별 후 반환
    static int pos = 0;
    char token = exp[pos];

    if (token == '\0') {
        pos = 0;
        return token;
    }
    else if (isdigit(token)) {
        pos++;
        return token;
    }
    else if (token == '+' || token == '-' || token == '*' || 
             token == '/' || token == '(' || token == ')' || 
             token == '[' || token == ']' || token == '{' || 
             token == '}' || token == '^') {
        pos++;
        return token;
    }
    else if (isspace(token)) { //공백이면 다음 토큰 호출 (재귀)
        pos++;
        return get_token(exp); 
    }
    else {
        printf("수식 오류\n");
        return 0;
    }
}

char* postfix(char exp[], char pexp[]) { //중위 -> 후위 함수
    int i = 0, j = 0;
    stack_type s;
    init(&s);
    char ch = get_token(exp);

    while (ch != '\0') {
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            while (!is_empty(s) && peek(s) != '(' && peek(s) != '[' && peek(s) != '{') {
                pexp[j++] = pop(&s);
            }
            if (!is_empty(s) && ((ch == ')' && peek(s) == '(') || 
                                 (ch == ']' && peek(s) == '[') || 
                                 (ch == '}' && peek(s) == '{'))) {
                pop(&s); // 왼쪽 괄호 제거
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!is_empty(s) && pis(peek(s)) >= pie(ch)) {
                pexp[j++] = pop(&s);
            }
            push(&s, ch);
        }
        else { //ch가 숫자일 때 
            pexp[j++] = ch;
        }
        ch = get_token(exp); //get_token 호출하여 exp의 다음 인덱스 반환
    }
    while (!is_empty(s)) {
        pexp[j++] = pop(&s);
    }
    pexp[j] = '\0';
    return pexp;
}

char* get_exp(char exp[]) { //수식 입력 함수
    printf("수식을 입력하세요: ");
    scanf("%[^\n]", exp);
    return exp;
}

int main(void) {   
    char exp[MAX_SIZE];
    char pexp[MAX_SIZE];

    get_exp(exp);
    
    char a[MAX_SIZE];
    int i = 0, j= 1;
    double result = eval_postfix(postfix(exp, pexp));

    printf("후위 변환 : %s\n", pexp);
    printf("계산 결과 : %.1f\n", result);
}
