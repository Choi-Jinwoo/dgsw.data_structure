#include <stdio.h>

int found(int *arr, int num) {
	int i = 0;

	while (arr[i] != num) {
		if (i > 100) {
			return -2; //Ž�� ���н� -2 ��ȯ
		}
		i++;
	}
	
	return i;
}

void insert(int *arr) {
	int cnt;
	printf("������ ������ ���� �Է� : ");
	scanf_s("%d", &cnt);
	
	printf("������ ������ �Է� : ");
	for (int i = 0; i < cnt; i++) {
		scanf_s("%d", &arr[found(arr, -1)]);
	}
}

void print(int *arr) {
	int i = 0;
	
	printf("������ ��� : ");
	while (arr[i] != -1) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void delete (int *arr) {
	int deleteNum;
	printf("������ ������ �Է� : ");
	scanf_s("%d", &deleteNum);
	
	while (found(arr, deleteNum) != -2) { //deleteNum Ž�� ���нñ��� �ݺ�
		int start = found(arr, deleteNum);
		int last = found(arr, -1);
		
		for (int i = start; i < last; i++) {
			arr[i] = arr[i + 1];
		}
	}
}

void main() {
	int arr[100];
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = -1;
	}

	insert(arr);
	print(arr);
	insert(arr);
	delete(arr);
	print(arr);
}