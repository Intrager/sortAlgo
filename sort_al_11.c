//�ܼ� ���� ���� (a[0]�� ���ʷ� ���)
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[0] = a[i];
		for (j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		if (j) a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x;

	puts("�ܼ� ���� ����");
	printf("��Ҽ� : ");
	scanf_s("%d", &nx);
	x = calloc(nx + 1, sizeof(int));	//a[0]�� ���ʷ� ����ϱ� ������ n + 1���� �迭�� ����

	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	insertion(x, nx + 1);

	puts("������������ �����߽��ϴ�.");
	for (i = 1; i < nx + 1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	return 0;
}