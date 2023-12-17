#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct student {
	int number;
	char name[10];
} STUDENT;

void sort(STUDENT* p, int size);

int main() {
	int size;

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
		printf("\n");
	}

	sort(p, size);

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
		fprintf(fp, "\n");
	}

	fclose(fp);
	free(p);

	return 0;
}

void sort(STUDENT* p, int size) {
	int least;
	STUDENT temp;
	for (int i = 0; i < size; i++) {
		least = i;
		for (int j = i + 1; j < size; j++) {
			if (((p + least)->number) > (p + j)->number) {
				least = j;
			}
		}
		temp = *(p + i);
		*(p + i) = *(p + least);
		*(p + least) = temp;
	}
}