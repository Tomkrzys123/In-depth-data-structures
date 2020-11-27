/*
 -------------------------------------
 File:    a1q1.c
 Project: dave2030_a1
 file description
 -------------------------------------
 Author:  Shyam Dave
 ID:      180332030
 Email:   dave2030@mylaurier.ca
 Version  2020-01-10
 -------------------------------------
 */
#include <stdio.h>

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char c = 0;
	char temp;
	do {
		printf("Please enter a character:\n");
		scanf("%c", &c);
		do {
			scanf("%c", &temp);
			if (temp == '\n')
				break;
		} while (1);
		if (c >= 'a' && c <= 'z') {
			printf("%c %d %c\n", c, c, c - 32);
		} else if (c >= 'A' && c <= 'Z') {
			printf("%c %d %c\n", c, c, c + 32);
		} else if (c >= '0' && c <= '9') {
			printf("%c %d %c\n", c, c, c);
		} else {
			printf("Invalid Input\n");
		}

	} while (c != '*');

	printf("Goodbye");
	return 0;
}

