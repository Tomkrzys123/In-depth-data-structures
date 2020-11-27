#include "myrecord.h"
#include <stdio.h>

char letter_grade(float s) {

	if (s >= 85 && s <= 100) {
		return 'A';
	} else if (s < 85 && s >= 70) {
		return 'B';
	} else if (s < 70 && s >= 60) {
		return 'C';
	} else if (s < 60 && s >= 50) {
		return 'D';
	} else {
		return 'F';
	}

}

int import_data(RECORD dataset[], char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	int i = 0;
	char temp[MAX_LINE];

	if (fp == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%s", temp);
		strcpy(dataset[i].name, strtok(temp, ","));
		dataset[i].score = atof(strtok(NULL, ","));
		i++;
	}
	fclose(fp);
	return 0;
}

int report_data(RECORD dataset[], int n, char *filename) {
	FILE *fp;
	fp = fopen(filename, "w");
	int i = 0;
	float mean = 0.0;
	float median = 0.0;
	int count = n;
	float std = 0.0;
	float a[n];

	for (i = 0; i < count; i++) {
		fprintf(fp, "%-15s%c\n", dataset[i].name,
				letter_grade(dataset[i].score));
		mean += dataset[i].score;
	}
	mean /= count;

	for (i = 0; i < count; i++) {
		std += (mean - dataset[i].score) * (mean - dataset[i].score);
	}
	float std_dev = sqrt(std / count);

	fprintf(fp, "\nStats summary\n");
	fprintf(fp, "%-20s%d\n", "count:", n);
	fprintf(fp, "%-20s%3.1f\n", "average:", mean);
	fprintf(fp, "%-20s%3.1f\n", "standard deviation:", std_dev);

	for (i = 0; i < count; i++) {
		a[i] = dataset[i].score;
	}

	quick_sort(a, 0, n - 1);
	if (n % 2 == 0) {
		median = (a[(n - 1) / 2] + a[n / 2]) / 2.0;
	} else {
		median = a[n / 2];
	}
	fprintf(fp, "%-20s%3.1f", "median:", median);
	fclose(fp);
	return 0;
}

void swap(float *first, float *second) {
	float temp = *first;
	*first = *second;
	*second = temp;
}

void quick_sort(float *a, int left, int right) {
	int i;
	float *last;
	if (right <= left) {
		return;
	} else {
		last = a + left;
		for (i = left + 1; i < right + 1; i++) {
			if (*(a + i) < *(a + left)) {
				swap(++last, a + i);
			}
		}
		swap(a + left, last);
		quick_sort(a, left, last - a);
		quick_sort(a, last - a + 1, right);
	}
}