#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "hash.h"

int hash(char* word) {
  unsigned int hash = 0, i;
  for (i = 0; word[i] != '\0'; i++) {
    hash = 31 * hash + word[i];
  }
  return hash % htsize;
}

HTNODE *new_hashnode(char *name, int value) {
 HTNODE *hn = (HTNODE*) malloc(sizeof(HTNODE));
 hn->value=value;
 strcpy(hn->name,name);
 hn->next=NULL;
 return hn;
}

HASHTABLE *new_hashtable(int size) {
   // allocate space for hashtable structure
  HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));  
  // allocate memory to hold the array of hashnode pointers
  ht->hnp = (HTNODE**) malloc(sizeof(HTNODE**)*size);  
      
  // initialize each pointers of array to NULL;   
  int i;
  for (i=0; i<size; i++) 
    *(ht->hnp+i) =  NULL;   //ht->hnp[i] = NULL; 

  // set the size property
  ht->size = size;
  
  // set the count property  
  ht->count = 0;   

  return ht;
}

HTNODE *search(HASHTABLE *ht, char *name) { 
  int i = hash(name);
  HTNODE *p = *(ht->hnp + i); //hashnode *p = ht->hnp[i]; 
    while ( p != NULL) {
      if (strcmp(name,p->name)==0)  // return the first data element matching the key
        return p;
      p = p->next;
  }  
  return NULL;
}

int insert(HASHTABLE *ht, HTNODE *np) {
    int index = hash(np->name);
    if (ht->hnp[index]){
        HTNODE *temp = ht->hnp[index];
        while (temp){
            if (strcmp(temp->name, np->name) == 0){
                temp->value = np->value;
                return 0;
            }
            temp = temp->next;
        }
        temp = np;
        ht->count++;
        return 1;
    }
    *(ht->hnp + index) = np;
    ht->count++;
    return 1;
}

int delete(HASHTABLE *ht, char *name) {
if (ht->count == 0) return 0;  // empty (underflow), can not insert
  int i = hash(name);
  HTNODE *p = *(ht->hnp + i), *pp = NULL;  

  if (p != NULL) {
    while (p && strcmp(name,p->name)<0) {
      pp = p;
      p = p->next;
    }
    
    if (p && strcmp(name,p->name)==0) {
      if (pp) 
        pp->next = p->next;  
      else 
        *(ht->hnp + i) = NULL;  
      free(p);
      ht->count--;
      return 1;
    }  
  }
  return 0;
}

void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HTNODE *sp = ht->hnp[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hnp[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
  ht->hnp[i] = NULL;
  }
  free(ht->hnp);
  ht->hnp = NULL;
  *htp = NULL;
}

void display_hashtable(HASHTABLE *ht, int option) {
  int i = 0;
  HTNODE *p;
  if (option == 0) {
  printf("size:  %d\n", ht->size);
  printf("count: %d\n", ht->count);
  printf("hash data: \nindex: list of the data elements");
  for (i = 0; i < ht->size; i++) {
    p = *(ht->hnp + i);
    if (p)
      printf("\n%2d: ", i);
    
    while (p) {
      printf("(%s, %d) ", p->name, p->value);
      p = p->next;
    }
  }
  printf("\n");
  }
  else {
      
  for (i = 0; i < ht->size; i++) {
    p = *(ht->hnp + i);
    while (p) {
      printf("%s=%d\n", p->name, p->value);
      p = p->next;
    }
  }
      
  }
  
}