#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} NODE;

void insert(NODE ** head, int scanData) {
	NODE * newNode = (NODE*)malloc(sizeof(NODE));
	NODE * preNode = *head;
	newNode->data = scanData;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	if ((*head)->data > scanData) { //head�� ���� input�� ��
		newNode->next = *head;
		*head = newNode;
		return;
	}

	while (preNode->next && preNode->next->data < scanData) { //���� ��尡 �ְ� ���� ����� �����Ͱ� input������ ���� -> ��带 �������� ����
		preNode = preNode->next;
	}

	//preNode�� ������ newNode ����
	newNode->next = preNode->next;
	preNode->next = newNode;
}

void _delete(NODE ** head, int scanData) {
	NODE * currentNode = *head;
	NODE * delNode;

	if (*head == NULL) { //head�� NULL���� Ȯ��, return
		return;
	}
	
	if ((*head)->data == scanData) { //head�� �����Ͱ� ������ �������� ��� head����, return
		delNode = *head;
		*head = (*head)->next;
		free(delNode);
		return;
	}

	while (currentNode->next && currentNode->next->data != scanData) { 
		currentNode = currentNode->next;
	}
	if (currentNode->next == NULL) { //���� �����Ͱ� �������, return
		return;
	}
	//currentNode(���� �� ����� pre���)
	delNode = currentNode->next;
	currentNode->next = currentNode->next->next;
	free(delNode);
}

void main() {
	NODE *head = NULL;
	int scanData;
	int deleteData;

	while (1) {
		scanf_s("%d", &scanData);
		if (scanData == 0) {
			break;
		}
		insert(&head, scanData);
	}

	printf("������ ������: ");
	scanf_s("%d", &deleteData);
	_delete(&head, deleteData);
}