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

int remove(int n) {
    int result = 0;
    int pre_last_num = -1;
    int last_num;
    while (n > 0) {
        last_num = n % 10; //�������� ����
        if (last_num != pre_last_num) { //�������� ���� �������� ���� �ٸ��ٸ� 
            push(last_num);   // ���� �������� push
            pre_last_num = last_num; // push�� ������ ������ ����
        }
        n /= 10; //�Ҽ����� ��������
    }
                            // ���ÿ��� �������� �ڸ����� �����ͼ� ����� ���
    while (!is_empty()) {   //������ ������� ������
        result = (result * 10) + pop(); //���ÿ��� �������� �ڸ����� �����´�
    }

    return result;
}

int main(void) {
    int input_num;
    printf("���� �Է�: ");
    scanf("%d", &input_num);
    printf("%d\n", remove(input_num));
    return 0;
}