#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expeval.h"

/*
 * axillary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * axillary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
	STACK stack = {0};
	NODE *np = NULL;
	QUEUE queue = {0};
	char c;

	while (infixstr && type(*infixstr) != 4) {

		if (type(*infixstr) == 0) {
		
			enqueue(&queue, new_node(*infixstr-'0', 0));
		}

		else if (type(*infixstr) == 1) {
		
			while (stack.top && type(stack.top->data) == 1 && get_priority(*infixstr) <= get_priority(stack.top->data)) {
				np = pop(&stack);
				enqueue(&queue, new_node(np->data, 1));
				free(np);
			}
			
			push(&stack, new_node(*infixstr, 1));

		}


		else if (type(*infixstr) == 2) {
			
			push(&stack, new_node(*infixstr, 2));
		}

		
		else if (type(*infixstr) == 3) {
			
			np = pop(&stack);
			c = np->data;
			free(np);
			while (type(c) != 2) {	
				enqueue(&queue, new_node(c, 1));
				np = pop(&stack);
				c = np->data;
				free(np);
			}
		}
	infixstr++;

	}
	while (stack.top) {
		np = pop(&stack);
		c = np->data;
		free(np);
		enqueue(&queue, new_node(c, 1));
	}
	return queue;

}

int evaluate_postfix(QUEUE queue) {

	STACK stack = {0};
	NODE *np = NULL;
	int c;
	int x, y;
	while (queue.front) {
		np = dequeue(&queue);
		c = np->data;
		free(np);
		if (0 <= c && c <= 9) {
			push(&stack, new_node(c, 0));
		}
		else {
			np = pop(&stack);
			x = np->data;
			free(np);
			np = pop(&stack);
			y = np->data;
			free(np);
			if (c == '+') {
				push(&stack, new_node(x+y, 0));
			}
			else if (c == '-') {
				push(&stack, new_node(y-x, 0));
			}
			else if (c == '*') {
				push(&stack, new_node(x*y, 0));
			}
			else {
				push(&stack, new_node(y/x, 0));
			}
		}
	}
	np = pop(&stack);
	x = np->data;
	free(np);
	return x;
}