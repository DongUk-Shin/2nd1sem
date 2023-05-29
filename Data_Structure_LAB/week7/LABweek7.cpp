#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
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
	default:
		break;
	}
}

double eval_postfix(char exp[])
{
    stack_type s;
    init(&s);
    int i = 0;
    char ch;
    double oper1, oper2;

    while ((ch = exp[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            push(&s, (double)(ch - '0'));
        }
        else
        {
            oper2 = pop(&s);
            oper1 = pop(&s);
            push(&s, eval(ch, oper1, oper2));
        }
    }
    return pop(&s);
}

int pie(char oper) {
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

char* postfix(char exp[], char pexp[]) {
    int i = 0, j = 0;
    char ch;
    stack_type s;
    init(&s);

    while ((ch = exp[i++]) != '\0') {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!is_empty(s) && pis(peek(s)) >= pie(ch)) {
                pexp[j++] = pop(&s);
            }
            push(&s, ch);
        }
        else {
            pexp[j++] = ch;
        }
    }
    while (!is_empty(s)) {
        pexp[j++] = pop(&s);
    }
    pexp[j++] = '\0';
    return pexp;
}

int main(void)
{
    char exp[MAX_SIZE] = "5*2+3-4/2";
    char pexp[MAX_SIZE];

    double result = eval_postfix(postfix(exp, pexp));
    printf("postfix: %s\n", pexp);
    printf("eval_postfix: %.1f\n", result);
}
