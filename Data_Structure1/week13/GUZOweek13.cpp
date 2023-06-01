#include <stdio.h>
#include <stdlib.h>

void postorder(int t[], int i) {
	if (i < 15 && t[i] != 0) {
		postorder(t, (i * 2));
		postorder(t, (i * 2) + 1);
		printf("[%d] ", t[i]);
	}
	
}
void inorder(int t[], int i) {
	if (i < 15 && t[i] != 0) {
		inorder(t, (i * 2));
		printf("[%d] ", t[i]);
		inorder(t, (i * 2) + 1);
	}
}
void preorder(int t[], int i) {
	if (i < 15 && t[i] != 0) {
		printf("[%d] ", t[i]);
		preorder(t, (i * 2));
		preorder(t, (i * 2) + 1);
	}
}

int main(void) {
	int t[15] = { 0, 1, 2, 3, 4, 5, 6, 0, 0, 7, 8, 0, 0, 9};
	
	printf("트리 (배열)\n전위: ");
	preorder(t, 1); printf("\n");

	printf("중위: ");
	inorder(t, 1); printf("\n");

	printf("후위: ");
	postorder(t, 1); printf("\n\n");

    return 0;
}
