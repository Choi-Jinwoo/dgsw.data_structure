#include <stdio.h>

int found(int *arr, int num) {
	int i = 0;

	while (arr[i] != num) {
		if (i > 100) {
			return -2; //탐색 실패시 -2 반환
		}
		i++;
	}
	
	return i;
}

void insert(int *arr) {
	int cnt;
	printf("삽입할 데이터 갯수 입력 : ");
	scanf_s("%d", &cnt);
	
	printf("삽입할 데이터 입력 : ");
	for (int i = 0; i < cnt; i++) {
		scanf_s("%d", &arr[found(arr, -1)]);
	}
}

void print(int *arr) {
	int i = 0;
	
	printf("데이터 출력 : ");
	while (arr[i] != -1) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void delete (int *arr) {
	int deleteNum;
	printf("삭제할 데이터 입력 : ");
	scanf_s("%d", &deleteNum);
	
	while (found(arr, deleteNum) != -2) { //deleteNum 탐색 실패시까지 반복
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