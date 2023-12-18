#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

typedef struct student {
	int number;
	char name[10];
	double grade;
} STUDENT;

void sort_number(STUDENT * p, int size);
void sort_name(STUDENT* p, int size);
void sort_grade(STUDENT* p, int size);

int main() {
	int size, num;

	printf("�л� ��: ");
	scanf("%d", &size);

	system("cls");

	STUDENT* p;
	p = (STUDENT*)malloc(size * sizeof(STUDENT));
	if (p == NULL) {
		printf("�޸� �Ҵ� ����");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		printf("�л� #%d\n", i + 1);
		printf("�й�: ");
		scanf("%d", &((p + i)->number));
		printf("�̸�: ");
		scanf("%s", &((p + i)->name));
		printf("����: ");
		scanf("%lf", &((p + i)->grade));
		printf("\n");
	}
	system("cls");

	while (1) {
		printf("���� ����: 1.�й�		2. �̸�		3. ����\n");
		scanf("%d", &num);
		if (num == 1) {
			sort_number(p, size);
			break;
		}
		else if (num == 2) {
			sort_name(p, size);
			break;
		}
		else if (num == 3) {
			sort_grade(p, size);
			break;
		}
		else {
			system("cls");
			printf("�ٽ� ����\n");
			continue;
		}
	}


	FILE* fp;
	fp = fopen("student.txt", "w");
	if (fp == NULL) {
		printf("���� ����");
		exit(1);
	}

	system("cls");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "�л� #%d\n", i + 1);
		fprintf(fp, "�й�: %d\n", ((p + i)->number));
		fprintf(fp, "�̸�: %s\n", ((p + i)->name));
		fprintf(fp, "����: %.2lf\n", ((p + i)->grade));
		fprintf(fp, "\n");
	}

	fclose(fp);
	free(p);

	return 0;
}

void sort_number(STUDENT* p, int size) {
	int min;
	STUDENT temp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (((p + min)->number) > (p + j)->number) {
				min = j;
			}
		}
		temp = *(p + i);
		*(p + i) = *(p + min);
		*(p + min) = temp;
	}
}

void sort_name(STUDENT* p, int size) {
	int min;
	STUDENT temp;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (((p + min)->number) > (p + j)->number) {
				min = j;
			}
		}
		temp = *(p + i);
		*(p + i) = *(p + min);
		*(p + min) = temp;
	}
}

void sort_grade(STUDENT* p, int size) {
	int max;
	STUDENT temp;
	for (int i = 0; i < size; i++) {
		max = i;
		for (int j = i + 1; j < size; j++) {
			if (((p + max)->grade) < (p + j)->grade) {
				max = j;
			}
		}
		temp = *(p + i);
		*(p + i) = *(p + max);
		*(p + max) = temp;
	}
}