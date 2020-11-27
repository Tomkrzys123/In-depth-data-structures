#ifndef BIGINT_H
#define BIGINT_H

#include "bigint_dllist.h"

typedef struct bigint {
    NODE *start;
    NODE *end;
} BIGINT;

BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

BIGINT bigint(char *digitstr);
void display_bigint(BIGINT bignumber);
void clean_bigint(BIGINT *bignumberp);
#endif