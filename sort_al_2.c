//���� ����
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
	int i, j;
	
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				swap(int,a[j], a[j + 1]);
	}
}

int main(void)
{
	int i, nx;
	int *x;		//�迭�� ����Ű�� ������

	puts("���� ����");
	printf("��Ҽ� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));	//��ڼ� nx�� int�� �迭�� ����

	for (i = 0; i < nx; i++) {
		printF("x[%d] : ", i);
		scnaf_s("%d", &x[i]);
	}

	bubble(x, nx);		//�迭 x�� ���� ����

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	//�迭 ����
	return 0;
}