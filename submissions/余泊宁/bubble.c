#include <stdio.h>

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Swap arr[j] and arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int numbers[8];
	printf("Please input 8 numbers:");

	for (int i = 0; i < 8; i++) {
		scanf("%d", &numbers[i]);
	}

	bubbleSort(numbers, 8);

	printf("After sorting:");
	for (int i = 0; i < 8; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

	return 0;
}
