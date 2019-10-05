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

	if ((*head)->data > scanData) { //head의 값과 input값 비교
		newNode->next = *head;
		*head = newNode;
		return;
	}

	while (preNode->next && preNode->next->data < scanData) { //다음 노드가 있고 다음 노드의 데이터가 input값보다 작음 -> 노드를 다음노드로 변경
		preNode = preNode->next;
	}

	//preNode의 다음에 newNode 연결
	newNode->next = preNode->next;
	preNode->next = newNode;
}

void _delete(NODE ** head, int scanData) {
	NODE * currentNode = *head;
	NODE * delNode;

	if (*head == NULL) { //head가 NULL인지 확인, return
		return;
	}
	
	if ((*head)->data == scanData) { //head의 데이터가 삭제할 데이터일 경우 head삭제, return
		delNode = *head;
		*head = (*head)->next;
		free(delNode);
		return;
	}

	while (currentNode->next && currentNode->next->data != scanData) { 
		currentNode = currentNode->next;
	}
	if (currentNode->next == NULL) { //삭제 데이터가 없을경우, return
		return;
	}
	//currentNode(삭제 할 노드의 pre노드)
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

	printf("삭제할 데이터: ");
	scanf_s("%d", &deleteData);
	_delete(&head, deleteData);
}