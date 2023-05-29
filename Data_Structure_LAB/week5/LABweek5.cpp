#include <stdio.h>

int main() {

     

    int a = 10; 
    int b = 20;
    int *p1, *p2; 
    printf("0. a:%p b:%p c:%p d:%p\n", &a, &b, &p1, &p2);
    p1 = &a;
    printf("1. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    p2 = &b;
    printf("2. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    b = *p1;
    printf("3. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    *p2 = 20;
    printf("4. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    *p1 = *p2;
    printf("5. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    p2 = p1;
    printf("6. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    *p2 = 10;
    printf("7. a:%d b:%d c:%p d:%p\n", a, b, (void*)p1, (void*)p2);
    return 0;
}
