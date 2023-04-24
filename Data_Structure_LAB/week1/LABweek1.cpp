#include<stdio.h>

int main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) 
            printf("*");
        printf("\n");   
    }

    for (int a = 0; a < 5; a++) {
        for (int b = 0; b <= 4-a; b++)
            printf("*");
        printf("\n");  
    }
    

    return 0;
}