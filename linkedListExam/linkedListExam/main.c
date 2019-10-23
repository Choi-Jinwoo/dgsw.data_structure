#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	char data;
	struct tree * leftChild;
	struct tree * rightChild;
} Tree;

void print(Tree * root) {
	Tree * temp = root;

	while (temp->leftChild != NULL) {
		temp = temp->leftChild;
	}

	printf("%c\n", temp->data);
}

void main() {
	Tree * A = (Tree*)malloc(sizeof(Tree));
	Tree * B = (Tree*)malloc(sizeof(Tree));
	Tree * C = (Tree*)malloc(sizeof(Tree));
	Tree * D = (Tree*)malloc(sizeof(Tree));
	Tree * E = (Tree*)malloc(sizeof(Tree));

	//link tree
	A->leftChild = B;
	A->rightChild = C;
	B->leftChild = D;
	B->rightChild = E;
	C->leftChild = NULL;
	C->rightChild = NULL;
	D->leftChild = NULL;
	D->rightChild = NULL;
	E->rightChild = NULL;
	E->rightChild = NULL;

	//node data setting
	A->data = 'A';
	B->data = 'B';
	C->data = 'C';
	D->data = 'D';
	E->data = 'E';

	print(A);
}