#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() { //공백 검출
    return (top == -1); 
}
int is_full() { //포화 검출
    return (top == (MAX_STACK_SIZE - 1)); 
}
void push(element item) {  //삽입
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}
element pop() { //삭제
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}
element peek() { //top 관찰
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int remove(int n) {
    int result = 0;
    int pre_last_num = -1;
    int last_num;
    while (n > 0) {
        last_num = n % 10; //나머지를 저장
        if (last_num != pre_last_num) { //나머지와 이전 나머지가 서로 다르다면 
            push(last_num);   // 현재 나머지를 push
            pre_last_num = last_num; // push한 나머지 정보를 저장
        }
        n /= 10; //소수점은 버려진다
    }
                            // 스택에서 역순으로 자리수를 가져와서 결과를 계산
    while (!is_empty()) {   //스택이 비어있지 않으면
        result = (result * 10) + pop(); //스택에서 역순으로 자리수를 가져온다
    }

    return result;
}

int main(void) {
    int input_num;
    printf("숫자 입력: ");
    scanf("%d", &input_num);
    printf("%d\n", remove(input_num));
    return 0;
}