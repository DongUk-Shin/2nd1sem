#include <stdio.h>
#include <stdlib.h>


void postorder(int t[], int i) {
	if (i < 14 && t[i] != NULL) {
		postorder(t, (i * 2));
		postorder(t, (i * 2) + 1);
		printf("[%d] ", t[i]);
	}
	
}
void inorder(int t[], int i) {
	if (i < 14 && t[i] != NULL) {
		inorder(t, (i * 2));
		printf("[%d] ", t[i]);
		inorder(t, (i * 2) + 1);
	}
}

void preorder(int t[], int i) {
	if (i < 14 && t[i] != NULL) {
		printf("[%d] ", t[i]);
		preorder(t, (i * 2));
		preorder(t, (i * 2) + 1);
	}
}




int main(void) {
	int t[15];
	for (int i = 0; i < 15; i++)
		t[i] = NULL;
	
	t[1] = 1;
	t[2] = 2;
	t[3] = 3;
	t[4] = 4;
	t[5] = 5;
	t[6] = 6;
	t[9] = 7;
	t[10] = 8;
	t[13] = 9;
	printf("전위: ");
	preorder(t, 1);
	printf("\n");

	printf("중위: ");
	inorder(t, 1);
	printf("\n");

	printf("후위: ");
	postorder(t, 1);
	printf("\n");

    return 0;
}
