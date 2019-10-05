#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} NODE;

void insert(NODE ** head, NODE ** tail, int data) {
	NODE * newNode;
	newNode = newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;

	if (*head == NULL && *tail == NULL) {
		*head = newNode;
		*tail = newNode;
	}
	else {
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

void delete(NODE ** head, NODE ** tail) {
	if (head == NULL) {
		return;
	}
	else {
		NODE * delNode = *tail;
		NODE * delPreNode = *head;

		while (delPreNode->next != *tail) {
			delPreNode = delPreNode->next;
		}

		delPreNode->next = *tail;
		*tail = delPreNode;
		free(delNode);
	}
}

void main() {
	NODE * head = NULL;
	NODE * tail = NULL;
	int scanData;
	
	while (1) {
		scanf_s("%d", &scanData);

		if (scanData == 0) {
			break;
		}

		insert(&head, &tail, scanData);
		
	}

	delete(&head, &tail);
}

/* delete
	if (head == NULL) {
		return;
	}
	else {
		NODE * delNode, *delNextNode;

		delNode = head;
		delNextNode = delNode->next;
		head = delNextNode;
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			free(delNode);
		}
	}
*/

/* tail
while (1) {
	scanf_s("%d", &scanData);

	if (scanData == 0) {
		break;
	}

	NODE * newNode;
	newNode = newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = scanData;

	if (head == NULL && tail == NULL) {
		head = newNode;
		tail = newNode;
	}

	tail->next = newNode;
	tail = newNode;
}
*/

/* head * tail (insert & delete)
while (1) {
		scanf_s("%d", &scanData);

		if (scanData == 0) {
			break;
		}

		NODE * newNode;
		newNode = newNode = (NODE *)malloc(sizeof(NODE));
		newNode->data = scanData;

		if (head == NULL && tail == NULL) {
			head = newNode;
			tail = newNode;
		}

		tail->next = newNode;
		tail = newNode;
	}


	if (head == NULL) {
		return;
	}
	else {
		NODE * delNode = tail;
		NODE * delPreNode = head;

		while (delPreNode->next != tail) {
			delPreNode = delPreNode->next;
		}

		delPreNode->next = tail;
		tail = delPreNode;
		free(delNode);
	}
	*/