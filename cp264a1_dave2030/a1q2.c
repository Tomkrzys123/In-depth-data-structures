/*
 -------------------------------------
 File:    a1q2.c
 Project: dave2030_a1
 file description
 -------------------------------------
 Author:  Shyam Dave
 ID:      180332030
 Email:   dave2030@mylaurier.ca
 Version  2020-01-11
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
	int i, n,hold=1;
	int calc=1;
	if (argc > 1) {
		n = atoi(args[1]);
		for (i = 1; i <= n; i++) {
			calc *= i;
			if (hold!=calc/i){
			    printf("overflow at %d!",i);
			    break;
			}
			hold=calc;
			printf("%10d", calc);
			if (i % 3 == 0){
				printf("\n");
			}

		}
	} else
		printf("no argument");

	return 0;
}