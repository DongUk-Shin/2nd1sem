#include <stdio.h>
#include <stdlib.h>

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

void reverse(stack_type *s, char string[]) {
	int i = 0;
	while (string[i] != '\0') {
		push(s, string[i]);
		i++;
	}
	while (!is_empty(*s)) {
		printf("%c", pop(s));
	}
}

int main() {
	char string[MAX_SIZE] = "abcdef";
	stack_type s;
	init(&s);
	reverse(&s, string);
	return 0;
}