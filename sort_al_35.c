//���� ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buff;		//�۾��� �迭

//���� ���� ����
void __mergesort(char *a, size_t left, size_t right, size_t size, int(*compar)(const void *, const void *))
{
	if (left < right) {
		size_t center = (left + right) / 2;
		size_t p = 0;
		size_t i;
		size_t j = 0;
		size_t k = left;

		__mergesort(a, left, center, size, compar);			//���� �κ��� ���� ����
		__mergesort(a, center + 1, right, size, compar);	//���� �κ��� ���� ����

		for (i = left; i <= center; i++)
			memcpy(&buff[p++ * size], &a[i * size], size);

		while (i <= right && j < p)
			memcpy(&a[k++ * size], compar((const void *)&buff[j * size], (const void *)&a[i * size]) <= 0 ?
				&buff[j++ * size] : &a[i++ *size], size);

		while (j < p)
			memcpy(&a[k++ * size], &buff[j++ * size], size);
	}
}

//���� ���� ����
void m_sort(void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	if (nmemb > 0) {
		buff = calloc(nmemb, size);

		__mergesort(base, 0, nmemb - 1, size, compar);		//�迭 ��ü�� ���� ����

		free(buff);
	}
}

int int_cmp(const int *a, const int *b)
{
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main(void)
{
	int i, nx;
	int *x;

	puts("m_sort �Լ��� �����մϴ�.");
	printf("��� ���� :");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	m_sort(x,															//�迭
		nx,																//��� ����
		sizeof(int),													//��� �ϳ��� ũ��
		(int(*)(const void *, const void *))int_cmp						//�� �Լ�
	);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}