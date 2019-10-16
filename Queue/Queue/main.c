#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int input) {
	if ((rear + 1) % MAX == front) {
		printf("Queue Overflow\n");
		return;
	}

	rear = ++rear % MAX;
	queue[rear] = input;
}

int dequeue() {
	if (front == rear) {
		printf("Queue Underflow\n");
		return -1;
	}
	front = ++front % MAX;
	return queue[front];
}

void printQueue(void) {
	int i = (front + 1) % MAX;

	while (i % MAX != (rear + 1)% MAX) {
		printf("%d ", queue[i % 5]);
		i++;
	}
}

void main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	printf("dq : %d\n", dequeue());
	printf("dq : %d\n", dequeue());

	enqueue(6);

	printQueue();
}