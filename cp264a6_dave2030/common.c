#include <stdio.h>
#include <malloc.h>
#include "common.h"

NODE *new_node(int data, int type) {
	NODE* np = (NODE *) malloc(sizeof(NODE));
	np->data=data;
	np->type=type;
	return np;
}

void display(NODE *start) {
  while (start) {
    if (start->type == 0) 
      printf("%d ", start->data);
    else 
      printf("%c ", start->data);      
    
    start = start->next;
  }
}

void clean(NODE **topp) {
	NODE *np,*temp;
	np=*topp;
    while(np!=NULL){
        temp=np;
        np= np->next;
        free(temp);
    }
    *topp = NULL;	
}