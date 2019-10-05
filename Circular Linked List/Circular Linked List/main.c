#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *lLink;
	struct Node *rLink;
} NODE;

void insert(NODE ** node, NODE ** newNode) {
	(*newNode)->rLink = (*node)->rLink;
	(*newNode)->lLink= (*node);
	(*node)->rLink->lLink = *newNode;
	(*node)->rLink = *newNode;
}

void insertSearch(NODE ** head, int input) {
	NODE * newNode;
	NODE * first;

	newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->lLink = NULL;
	newNode->rLink = NULL;

	first = *head;
	while (newNode->data >= first->rLink->data) {
		if (first->rLink == *head) {
			break;
		}
		first = first->rLink;
	}

	insert(&first, &newNode);
}

void _delete(NODE ** deleted) {
	(*deleted)->rLink->lLink = (*deleted)->lLink;
	(*deleted)->lLink->rLink = (*deleted)->rLink;
	free(*deleted);
}

void deleteSearch(NODE ** head, int input) {
	NODE * first;
	first = *head;
	while (input != first->rLink->data) {
		if (first->rLink == *head) {
			return;
		}
		first = first->rLink;
	}
	_delete(&(first->rLink));
}

void main() {
	NODE * tail = NULL;
	NODE * head = (NODE*)malloc(sizeof(NODE));
	head->lLink = head;
	head->rLink = head;
	head->data = 0;
	int input;

	while (1) {
		scanf_s("%d", &input);
		if (input == 0) {
			break;
		}

		insertSearch(&head, input);
	}
	deleteSearch(&head, 1);

}