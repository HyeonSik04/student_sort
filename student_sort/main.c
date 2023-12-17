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

	printf("학생 수: ");
	scanf("%d", &size);

	system("cls");

	STUDENT* p;
	p = (STUDENT*)malloc(size * sizeof(STUDENT));
	if (p == NULL) {
		printf("메모리 할당 오류");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		printf("학생 #%d\n", i + 1);
		printf("학번: ");
		scanf("%d", &((p + i)->number));
		printf("이름: ");
		scanf("%s", &((p + i)->name));
		printf("\n");
	}

	sort(p, size);

	FILE* fp;
	fp = fopen("student.txt", "w");
	if (fp == NULL) {
		printf("파일 오류");
		exit(1);
	}

	system("cls");
	for (int i = 0; i < size; i++) {
		fprintf(fp, "학생 #%d\n", i + 1);
		fprintf(fp, "학번: %d\n", ((p + i)->number));
		fprintf(fp, "이름: %s\n", ((p + i)->name));
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