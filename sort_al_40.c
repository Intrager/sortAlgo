//도수 정렬(최솟값, 최댓값 지정)
#include <stdio.h>
#include <stdlib.h>

void fsort2(int a[], int n, int min, int max)
{
	int i;
	int *f = calloc(max - min + 2, sizeof(int));		//누적 도수
	int *b = calloc(n, sizeof(int));					//작업용 목적 배열

	for (i = 0; i <= max - min + 1; i++) f[i] = 0;			//step 0
	for (i = 0; i < n; i++) f[a[i] - min]++;				//step 1
	for (i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];	//step 2
	for (i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];	//step 3
	for (i = 0; i < n; i++) a[i] = b[i];					//step 4

	free(b);
	free(f);
}

int main(void)
{
	int i, nx;
	int *x;
	int min, max;

	puts("도수 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("최솟값 : ");
	scanf_s("%d", &min);

	while (1)
	{
		printf("최댓값 : ");
		scanf_s("%d", &max);
		if (max > min) break;
		printf("%d보다 큰 값을 입력하세요\n", min);
	}

	printf("%d~%d의 정수를 입력하세요\n", min, max);
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < min || x[i] > max);
	}

	fsort2(x, nx, min, max);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}