#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * link;
} NODE;

NODE * front = NULL;
NODE * rear = NULL;

void enqueue(int input) {
	NODE * newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->link = NULL;
	if (front == NULL) {
		front = newNode;
		rear = newNode;
		return;
	}

	rear->link = newNode;
	rear = newNode;
}

void dequeue() {
	if (front == NULL) {
		printf("Queue Underflow\n");
		return;
	}

	NODE * temp = front;
	front = front->link;
	free(temp);
}

void print_queue() {
	NODE *p = front;

	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
}

void main() {

}