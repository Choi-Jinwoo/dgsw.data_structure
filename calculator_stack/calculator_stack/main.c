#include <stdio.h>

int top = -1;
int resultTop = -1;
char stack[100];
double resultStack[100];

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

void resultPush(double db) {
	if (resultTop + 1 >= 100) {
		printf("stack overflow\n");
		return;
	}
	resultStack[++resultTop] = db;
}

double resultPop() {
	if (resultTop < 0) {
		printf("stack underflow\n");
		return -1;
	}
	return resultStack[resultTop--];
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

int atoi(char ch) {
	return ch - '0';
}

void getPostFix(char * infix, char * postfix) {
	int i = 0;
	int postTop = 0;
	while (infix[i] != NULL) { // �����ϰ��
		if (isdigit(infix[i])) {
			postfix[postTop++] = infix[i];
			i++;
			continue;
		}
		if (infix[i] == '(') { // (�ϰ��
			push('(');
			i++;
			continue;
		}
		if (infix[i] == ')') { // )�ϰ��
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
		if (top == -1 || getRank(stack[top]) < getRank(infix[i])) { // ó���̰ų� �켱������ ������� Ǫ��
			push(infix[i]);
			i++;
			continue;
		}
		while (1) {
			if (stack[top] != NULL && getRank(stack[top]) >= getRank(infix[i])) { // ������ ��� break, �켱������ ������ break
				char popCh = pop();
				postfix[postTop++] = popCh;
			}
			else {
				break;
			}
		}
		push(infix[i]); //���ο� ������ Ǫ��
		i++;
	}

	while (top != -1) { // ��� ������ �������� postfix�� ����
		postfix[postTop++] = pop();
	}

	postfix[postTop] = NULL;
}

double calculate(double op1, double op2, char operator) {
	if (operator == '+') 
		return op1 + op2;
	if (operator == '-')
		return op1 - op2;
	if (operator == '*')
		return op1 * op2;
	if (operator == '/')
		return op1 / op2;
}

double getResult(char * postfix) {
	int i = 0;
	while (postfix[i] != NULL) {
		if (isdigit(postfix[i])) {
			resultPush(atoi(postfix[i]));
			i++;
			continue;
		}

		double op2 = resultPop();
		double op1 = resultPop();

		resultPush(calculate(op1, op2, postfix[i]));
		i++;
	}

	return resultPop();
}

void main() {
	char postfix[100];
	char infix[] = "1+2/4+(4*(3-2))";

	getPostFix(infix, postfix);
	printf("%s\n", postfix);

	printf("��\n");
	printf("%lf", getResult(postfix));
}