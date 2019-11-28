#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int key;
	struct tree* leftChild;
	struct tree* rightChild;
	
} Tree;

Tree * root = NULL;

Tree * modifySearch(Tree * parent, int input) {
	Tree * temp = parent;
	if (temp == NULL)
		return temp;
	if (input < temp->key)
		return modifySearch(temp->leftChild, input);
	else if (input > temp->key)
		return modifySearch(temp->rightChild, input);
}

void insert(input) {
	Tree * parent = modifySearch(root, input);
	Tree * newNode = (Tree*)malloc(sizeof(Tree));
	newNode->key = input;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	if (parent == NULL) {
		root = newNode;
		return;
	}

	if (parent->key > input) {
		parent->leftChild = newNode;
	}
	else {
		parent->rightChild= newNode;
	}
}

void main() {
	int input;
	Tree * temp = NULL;

	while (1) {
		scanf_s("%d", &input);
		if (input == 0) {
			break;
		}
		insert(input);
	}

}