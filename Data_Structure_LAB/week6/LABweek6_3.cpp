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

int paren_num(char exp[]) {
    stack_type s;
    init(&s);
    int left_paren_index = 0;
    int i = 0;
    int left_paren_pos;

    while (exp[i] != '\0') {
        if (exp[i] == '(') {
            push(&s, ++left_paren_index);
            printf("%d ", left_paren_index);
        }
        else if (exp[i] == ')') {
            if (!is_empty(s)) {
                left_paren_pos = pop(&s);
                printf("%d ", left_paren_pos);
            }
            else {  //±×·¸Áö ¾ÊÀ¸¸é pass
            }
        }
        i++;
    }
    return 0;
}

int main() {
    char string[] = "((())(()))";
    printf("\n");
    paren_num(string);

    char string2[] = "((((()";
    printf("\n");
    paren_num(string2);

    char string3[] = "())(()))";
    printf("\n");
    paren_num(string3);
    printf("\n");

	return 0;
}
