#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * link;
} NODE;

NODE * top = NULL;

void push(int input) {
	NODE * newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->link = top;
	top = newNode;
}

void pop() {
	if (top == NULL) {
		printf("\nStack Underflow");
		return;
	}
	NODE * temp = top;
	top = top->link;
	free(temp);
}

void main() {
	push(3);
	push(2);
	pop();
}