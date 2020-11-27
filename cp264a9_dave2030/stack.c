#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
void push(STACK *sp, NODE *np) {
if (sp == NULL || np == NULL) return;
if (sp->top == NULL) {
sp->top = np;
sp->top->next = NULL;
}
else{
    np->next=sp->top;
    sp->top=np;
}
}


NODE *pop(STACK *sp) {
NODE *np=NULL;
if(sp->top){
	np=sp->top;
	sp->top=sp->top->next;
}
return np;
}

void clean_stack(STACK *sp) {
NODE *np,*temp;
if (sp->top){
np=sp->top;
while(np){
	temp=np;
	np=np->next;
	free(temp);
}
sp->top=NULL;
}
}

