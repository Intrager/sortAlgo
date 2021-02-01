//���� ����(�ּڰ�, �ִ� ����)
#include <stdio.h>
#include <stdlib.h>

void fsort2(int a[], int n, int min, int max)
{
	int i;
	int *f = calloc(max - min + 2, sizeof(int));		//���� ����
	int *b = calloc(n, sizeof(int));					//�۾��� ���� �迭

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

	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("�ּڰ� : ");
	scanf_s("%d", &min);

	while (1)
	{
		printf("�ִ� : ");
		scanf_s("%d", &max);
		if (max > min) break;
		printf("%d���� ū ���� �Է��ϼ���\n", min);
	}

	printf("%d~%d�� ������ �Է��ϼ���\n", min, max);
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < min || x[i] > max);
	}

	fsort2(x, nx, min, max);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}