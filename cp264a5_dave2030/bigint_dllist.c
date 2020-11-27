#include "bigint_dllist.h"

NODE *new_node(char data) {
  NODE* np = (NODE *) malloc(sizeof(NODE));
  np->data = data;
  np->prev = NULL; 
  np->next = NULL; 
  return np;
}

void display_forward(NODE *np) {

NODE *ptr=np;
while(ptr!=NULL){
	printf("%c ", ptr->data);    
	ptr = ptr->next;
	}
}

void display_backward(NODE *np) {

NODE *ptr=np;
while(ptr!=NULL){
	printf("%c ", ptr->data);    
	ptr = ptr->prev;
	}
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
  NODE *dlp=*startp,*end=*endp;
  if (dlp == NULL && end==NULL){	
    *startp = new_np;
    *endp=new_np;
	new_np->prev=NULL;
	new_np->next=NULL;
  }  
  else {
    dlp->prev = new_np; 
    new_np->next = dlp; 
	new_np->prev = NULL;
	*startp=new_np;
  }
}


void insert_end(NODE **startp, NODE **endp, NODE *new_np) {
  NODE *dlp=*endp,*start=*startp;
  if (dlp == NULL && start==NULL){	
    *endp = new_np;
    *startp=new_np;
	new_np->prev=NULL;
	new_np->next=NULL;
  }  
  else {
    dlp->next = new_np; 
    new_np->prev = dlp;  
	new_np->next = NULL;
	*endp=new_np;
}
}

void delete_start(NODE **startp, NODE **endp) {
  NODE *np=*startp,*oldnp;
  if (*startp != NULL){
	  if(np->next == NULL){
		  free(np);
		  *startp = NULL;
		  *endp = NULL;
		  }
	  else{
		oldnp = np;
		np = np->next;
		np->prev = NULL;
		*startp = np;
		free(oldnp);
	  }
  }
}


void delete_end(NODE **startp, NODE **endp) {
  NODE *np=*endp,*oldnp;
  if (np != NULL){
	  if(np->prev == NULL) { 
		free(np);
		*startp=NULL;
		*endp=NULL;
	  }	
	  else{
		oldnp = np;
		np= np->prev;
		np->next = NULL;
		*endp = np;
		free(oldnp);
	}
  }
}

void clean(NODE **startp, NODE **endp) {
  NODE *np;
    while(*startp != *endp){
        np = *startp;
        *startp = np->next;
        free(np);
    }
    free(*startp);
    *startp = NULL;
    *endp = NULL;
}