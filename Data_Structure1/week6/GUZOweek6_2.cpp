#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() { //���� ����
    return (top == -1); 
}
int is_full() { //��ȭ ����
    return (top == (MAX_STACK_SIZE - 1)); 
}
void push(element item) {  //����
    if (is_full()) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else stack[++top] = item;
}
element pop() { //����
    if (is_empty()) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top--];
}
element peek() { //top ����
    if (is_empty()) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return stack[top];
}

void compress(char* string) {   
    int count = 1;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == string[i+1]) { //���� ���ڿ� ���� ���ڸ� ��
            count++;   //���ٸ� count ����
        } else {       //���� ���ڿ� ���� ���ڰ� �ٸ��ٸ�
            push(string[i]); //�ش� ���ڸ� push
            push(count + '0'); //count �� push (count�� char�� ��ȯ�ϱ� ���� 0�� ���Ѵ�)
            count = 1;  //count �ʱ�ȭ
        }
    }
    char output[MAX_STACK_SIZE];    //���ϴ� aaas�� �Է½ÿ�
    int i = 0;                      //s1a3�� ��µ��� �ʰ� 3a1s�� ��µǵ���
    while (!is_empty()) {           //�迭�� ������ ���� �迭�� ���� ���� ��
        output[i] = pop();          //�������� ��� ���ִ� ��ġ�̴�.
        i++;
    }
    for (int j = i-1; j >= 0; j--) {
        putchar(output[j]);
    }
}

int main() {
    char string[MAX_STACK_SIZE];
    printf("�ؽ�Ʈ �Է�(�ҹ��� ���): ");
    scanf("%s", string);
    compress(string);
    printf("\n");
    return 0;
}