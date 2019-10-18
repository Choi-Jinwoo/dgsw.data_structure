#include <stdio.h>

int top = -1;
char stack[100];
char infix[] = "(1/(2-3+4))*(5-1)*3";
char postfix[100];

void push(char ch) {
	if (top + 1 >= 100) {
		printf("stack overflow\n");
		return;
	}
	stack[++top] = ch;
}

char pop() {
	if (top < 0) {
		printf("stack underflow\n");
		return -1;
	}
	return stack[top--];
}

int getRank(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '/':
	case '*':
		return 2;
	default:
		return -1;
	}
}

void get() {
	int i = 0;
	int postTop = 0;
	while (infix[i] != NULL) {
		if (isdigit(infix[i])) {
			postfix[postTop++] = infix[i];
			i++;
			continue;
		}
		else if (infix[i] == '(') {
			push('(');
			i++;
			continue;
		}
		else if (infix[i] == ')') {
			while (1) {
				char popCh = pop();
				if (popCh == '(') {
					break;
				}
				else if (!(popCh == ')')) {
					postfix[postTop++] = popCh;
				}
			}
			i++;
			continue;
		}

		if (top == -1 || getRank(stack[top]) < getRank(infix[i])) {
			push(infix[i]);
			i++;
			continue;
		}

		while (1) {
			if (stack[top] != NULL && getRank(stack[top]) >= getRank(infix[i])) {
				char popCh = pop();
				postfix[postTop++] = popCh;
			}
			else {
				break;
			}
		}

		push(infix[i]);
		i++;
	}

	while (top != -1) {
		postfix[postTop++] = pop();
	}
}
void main() {
	get();
	for (int i = 0; i < 20; i++) {
		printf("%c ", postfix[i]);
	}
}