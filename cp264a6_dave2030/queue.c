#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	if(qp->front==NULL){
		qp->front=np;
	}
	else{
		qp->rear->next=np;
		
	}
	qp->rear=np;
	np->next=NULL;
	
}  

NODE *dequeue(QUEUE *qp) {
NODE *np=NULL;
if (qp->front){
	np=qp->front;
	qp->front=np->next;
}
return np;
}

void clean_queue(QUEUE *qp) {
NODE *np,*temp;
np=qp->front;
if(qp->front){
while(np){
	temp=np;
	np=np->next;
	free(temp);
}
qp->front=NULL;
qp->rear=NULL;
}
}
