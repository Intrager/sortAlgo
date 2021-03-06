//셸 정렬 (버전 2)
#include <stdio.h>
#include <stdlib.h>

int shell(int a[], int n)
{
	int i, j, h;
	int count = 0;

	for (h = 1; h < n / 9; h = h * 3 + 1);

	for(; h>0; h/=3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	return count;
}

int main(void)
{
	int i, nx;
	int *x;
	int count;

	puts("셸 정렬");
	printf("요소수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	count = shell(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	printf("요소의 이동 횟수는 %d회 입니다.\n", count);

	free(x);
	return 0;
}