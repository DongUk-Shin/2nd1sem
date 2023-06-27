#include <stdio.h>
#include <stdlib.h>

void postorder(int t[], int i) {
	if (t[i] != 0) {
		postorder(t, (i * 2));
		postorder(t, (i * 2) + 1);
		printf("[%d] ", t[i]);
	}
	
}
void inorder(int t[], int i) {
	if (t[i] != 0) {
		inorder(t, (i * 2));
		printf("[%d] ", t[i]);
		inorder(t, (i * 2) + 1);
	}
}
void preorder(int t[], int i) {
	if (t[i] != 0) {
		printf("[%d] ", t[i]);
		preorder(t, (i * 2));
		preorder(t, (i * 2) + 1);
	}
}

int main(void) {
	int t[32] = {0, 1, 2, 3, 4, 5, 6, 0, 0, 7, 8, 0, 0, 9, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Ʈ�� (�迭)\n����: ");
	preorder(t, 1); printf("\n");

	printf("����: ");
	inorder(t, 1); printf("\n");

	printf("����: ");
	postorder(t, 1); printf("\n\n");

    return 0;
}
