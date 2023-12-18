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
		printf("학점: ");
		scanf("%lf", &((p + i)->grade));
		printf("\n");
	}
	system("cls");

	while (1) {
		printf("정렬 기준: 1.학번		2. 이름		3. 학점\n");
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
			printf("다시 선택\n");
			continue;
		}
	}


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
		fprintf(fp, "학점: %.2lf\n", ((p + i)->grade));
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