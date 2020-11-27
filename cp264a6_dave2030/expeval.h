#ifndef EXPEVAL_H
#define EXPEVAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"
#include "queue.h"

/* 
 * convert infix expression in string to postfix expression represented by QUEUE and return the postfix expression queue 
*/
QUEUE infix_to_postfix(char *infixstr);

/* 
 * evaluate postfix expression passed by queue
*/
int evaluate_postfix(QUEUE queue);

#endif