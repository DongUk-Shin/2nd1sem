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

void compress(char* string) {   
    int count = 1;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == string[i+1]) { //현재 문자와 다음 문자를 비교
            count++;   //같다면 count 증가
        } else {       //현재 문자와 다음 문자가 다르다면
            push(string[i]); //해당 문자를 push
            push(count + '0'); //count 값 push (count를 char로 변환하기 위해 0을 더한다)
            count = 1;  //count 초기화
        }
    }
    char output[MAX_STACK_SIZE];    //이하는 aaas를 입력시에
    int i = 0;                      //s1a3이 출력되지 않고 3a1s가 출력되도록
    while (!is_empty()) {           //배열을 생성해 스택 배열의 값을 저장 후
        output[i] = pop();          //역순으로 출력 해주는 장치이다.
        i++;
    }
    for (int j = i-1; j >= 0; j--) {
        putchar(output[j]);
    }
}

int main() {
    char string[MAX_STACK_SIZE];
    printf("텍스트 입력(소문자 영어만): ");
    scanf("%s", string);
    compress(string);
    printf("\n");
    return 0;
}