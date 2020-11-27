/*
 -------------------------------------
 File:    a1q3.c
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
#include <math.h>  // need this library for maths functions fabs() and sqrt()

int main() {
	float a, b, c, disc, x1, x2;
	int inn;
	char temp;

// do-while for repeated input
	do {
		// do-while loop to get correct input of three floating number coefficient
		do {
			printf("Please enter the coefficients a,b,c:\n");
			inn = scanf("%f,%f,%f", &a, &b, &c);

			if (inn != 3) {
				printf("Invalid input\n");
			} else
				break;

			do {  // flush the input buffer
				scanf("%c", &temp);
				if (temp == '\n')
					break;
			} while (1);

		} while (1);
		disc = (b * b) - (4 * a * c);
		if (fabs(a) < 1e-6 && fabs(b) < 1e-6 && fabs(c) < 1e-6) {
			printf("Goodbye\n");
			break;
		} else if (fabs(a) < 1e-6) {
			printf("not a quadratic equation\n");
		} else if (disc > 0) {  //2 distinct real roots
			x1 = (-b + sqrt(disc)) / (2 * a);
			x2 = (-b - sqrt(disc)) / (2 * a);
			printf("The equation has two distinct real roots:\n");
			printf("%.6f\n", x1);
			printf("%.6f\n", x2);
		} else if (disc == 0) { //2 equal real roots
			x1 = x2 = -b / (2 * a);
			printf("The equation has two equal real roots:\n");
			printf("%.6f\n", x1);
		} else { //complex roots
			x1 = -b / (2 * a); //real part
			x2 = sqrt(-disc) / (2 * a); //imaginary part
			printf("The equation has two complex roots:\n");
			printf("%.6f+%.6fi\n", x1, x2);
			printf("%.6f-%.6fi\n", x1, x2);
		}

	} while (1);

	return 0;
}
