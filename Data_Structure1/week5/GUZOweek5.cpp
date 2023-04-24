#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100

typedef struct {
    int coef;
    int expo;
} poly_term;

typedef struct {
    int n_terms;
    poly_term terms[MAX_TERMS];
} poly;

poly input_poly() {
    int n_terms;
    poly p = {0, {{0, 0}}};
    printf("항의 개수를 입력하세요: ");
    scanf("%d", &n_terms);

    p.n_terms = n_terms;
    printf("항 의 계수와 차수를 입력하세요: \n");
    for (int i = 0; i < n_terms; i++) {
        scanf("%d %d", &p.terms[i].coef, &p.terms[i].expo);
    }
    return p;
}

void print_poly(poly p) {
    int i;
    for (i = 0; i < p.n_terms; i++) {
        if (i != p.n_terms - 1) {
            if (p.terms[i].expo == 1) {
                if (p.terms[i].coef > 0) 
                    printf("%dx + ", p.terms[i].coef);
                else 
                    printf("(%dx) + ", p.terms[i].coef);
            }

            else if (p.terms[i].expo == 0 ) {
                if (p.terms[i].coef > 0) 
                    printf("%d + ", p.terms[i].coef);
                else
                    printf("(%d) + ", p.terms[i].coef);
            }

            else if (p.terms[i].expo > 1 ){
                if (p.terms[i].coef > 0) 
                    printf("%dx^%d + ", p.terms[i].coef, p.terms[i].expo);
                else
                    printf("(%dx^%d) + ", p.terms[i].coef, p.terms[i].expo);
            }
        } else {
            if (p.terms[i].expo == 1) {
                if (p.terms[i].coef > 0) 
                    printf("%dx ", p.terms[i].coef);
                else 
                    printf("(%dx) ", p.terms[i].coef);
            }
            else if (p.terms[i].expo == 0 ) {
                if (p.terms[i].coef > 0) 
                    printf("%d" , p.terms[i].coef);
                else
                    printf("(%d) ", p.terms[i].coef);
            }
            else if (p.terms[i].expo > 1 ){
                if (p.terms[i].coef > 0) 
                    printf("%dx^%d ", p.terms[i].coef, p.terms[i].expo);
                else
                    printf("(%dx^%d) ", p.terms[i].coef, p.terms[i].expo);
            }
        }
    }
    printf("\n");
}

poly sub_poly(poly p1, poly p2) {
    poly p3 = {0, {{0, 0}}};
    int i = 0, j = 0, k = 0;
    while (i < p1.n_terms && j < p2.n_terms) {
        if (p1.terms[i].expo == p2.terms[j].expo) {
            int coef = p1.terms[i].coef - p2.terms[j].coef;
            if (coef != 0) {
                p3.terms[k].coef = coef;
                p3.terms[k].expo = p1.terms[i].expo;
                k++;
                p3.n_terms++;
            }
            i++;
            j++;
        }
        else if (p1.terms[i].expo > p2.terms[j].expo) {
            p3.terms[k].coef = p1.terms[i].coef;
            p3.terms[k].expo = p1.terms[i].expo;
            k++;
            p3.n_terms++;
            i++;
        }
        else {
            p3.terms[k].coef = -p2.terms[j].coef;
            p3.terms[k].expo = p2.terms[j].expo;
            k++;
            p3.n_terms++;
            j++;
        }
    }
    while (i < p1.n_terms) {
        p3.terms[k].coef = p1.terms[i].coef;
        p3.terms[k].expo = p1.terms[i].expo;
        k++;
        p3.n_terms++;
        i++;
    }
    while (j < p2.n_terms) {
        p3.terms[k].coef = -p2.terms[j].coef;
        p3.terms[k].expo = p2.terms[j].expo;
        k++;
        p3.n_terms++;
        j++;
    }
    return p3;
}

int main() {
    poly p1, p2, p3;

    printf("첫번째 다항식 입력 : \n");
    p1 = input_poly();

    printf("두번째 다항식 입력 : \n");
    p2 = input_poly();

    p3 = sub_poly(p1, p2);
    printf("----------------------------\n");
    print_poly(p1);
    print_poly(p2);
    printf("----------------------------\n");
    print_poly(p3);

    return 0;
}