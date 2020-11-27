#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_REC 100
#define MAX_LINE 100


typedef struct {
    char name[20];
    float score;
} RECORD;

char letter_grade(float s);
int import_data(RECORD dataset[], char *filename); 
int report_data(RECORD dataset[], int n, char *filename); 
void swap(float *first, float *second); 
void quick_sort(float *a, int left, int right);