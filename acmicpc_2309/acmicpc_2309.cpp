#include <stdio.h>
#include <Windows.h>
#define MAX 9
#define FIT 7

void main() {
	int array[MAX];
	int ans[FIT];
	int a, temp;
	for (int i = 0; i < MAX; i++) {
		scanf_s("%d", &a);
		array[i] = a;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	int start_point = 0, sum = 0;
	for (int i = 0; i < FIT; i++)
		ans[i] = array[i];
	for (int i = 0; i < FIT; i++)
		sum += ans[i];
	if (sum == 100) {
		for(int i = 0; i < FIT; i++)
			printf("%d", ans[i]);
	}
	if (sum < 100)
	system("pause");
}