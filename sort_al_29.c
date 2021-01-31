// qsort 함수를 사용하여 정수 배열을 오름차순으로 정렬
#include <stdio.h>
#include <stdlib.h>

//int형 비교 함수(오름차순 정렬에 사용)
int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i, nx;
	int *x;
	
	printf("qsort에 의한 정렬\n");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	qsort(x,											//배열		
		nx,												//요소의 개수
		sizeof(int),									//요소의 크기
		(int(*)(const void *, const void *))int_cmp		//비교 함수
	);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);		//배열을 해제

	return 0;
}