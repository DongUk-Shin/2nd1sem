#include <stdio.h>
#include <stdlib.h>
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

int pop(stack_type *s) {
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

int paren_test(char exp[]) {
    stack_type s;
    init(&s);
    int i = 0;
    char ch;
    while ((ch = exp[i++]) != '\0') {
        if (ch == '(') {
            push(&s, '(');
        } else if (ch == ')') {
            if (is_empty(s)) 
                return 0;
            else 
                pop(&s);
        }
        else { //공백일시 아무것도 x
        }
    }
    if (!is_empty(s))
        return 0;
    else 
        return 1;
}

int main() {
    char string1[] ="((()) (( )))";
    char string2[] ="(((())())";
    printf("%s", string1);
    if (paren_test(string1) == 1)
        printf(" is Balanced\n");
    else 
        printf(" is Not Balanced\n");

    printf("%s", string2);
    if (paren_test(string2) == 1)
        printf(" is Balanced\n");
    else 
        printf(" is Not Balanced\n");
	return 0;
}
