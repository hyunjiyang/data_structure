#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int compare(int x, int y) {
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int binsearch(int list[], int search) {
	int l = 0;
	int middle;
	int r = 29;
	while (l <= r) {
		middle = (l + r) / 2;
		printf("left= %2d middle = %2d right = %2d\n", l, middle, r);
		switch (compare(list[middle], search)) {
		case -1: l = middle + 1; break;
		case 0: return middle;
		case 1: r = middle - 1; break;
		}
	}
	return -1;
}

void main() {

	int list[] = { 1, 3, 5, 6, 7, 8, 11, 12, 14, 15, 24, 26, 42, 43, 49, 48, 51, 55, 56, 59, 66, 67, 69, 70, 71, 73, 75, 80, 96, 99 };
	int search;

	printf("찾을 숫자 : ");
	scanf_s("%d", &search);

	binsearch(list, search);

	return 0;
}
