
#include "tree.h"

TNODE *new_node(int value) {
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return NULL;
  np->data = value;
  np->left = NULL;
  np->right = NULL;
  return np;
}

int get_count(TNODE *root) {
	int count=1;
	if(root->left && root->right==NULL){
		count+=1;
	}
	else{
		if(root->left)count+=get_count(root->left);
		if(root->right)count+=get_count(root->right);
	}
	return count;
}
		
		
int get_height(TNODE *root) {
	if (root==NULL)return 0;
	else{
		int left=get_height(root->left);
		int right=get_height(root->right);
		if (left>right)return (1+left);
		else return (1+right);
	}
}

void clean_tree(TNODE **rootp) {
TNODE *root=*rootp;
if (root){
	if (root->left)clean_tree(&root->left);
	if (root->right)clean_tree(&root->left);
	free (root);
}
*rootp=NULL;
}

void display_preorder(TNODE *root) {
	if(root){
		printf("%c",root->data);
		display_preorder(root->left);
		display_preorder(root->right);
	}

}

void display_inorder(TNODE *root) {
	if(root){
		display_inorder(root->left);
		printf("%c",root->data);
		display_inorder(root->right);
		
	}
}

void display_postorder(TNODE *root) {
 if(root){
	 display_postorder(root->left);
	 display_postorder(root->right);
	 printf("%c",root->data);
 }
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%c\n", root->data);
    display_tree(root->right, prelen + 4);
    display_tree(root->left, prelen + 4);
  }
}

/* use auxiliary queue data structure for the algorithm */
void iterative_bf_display(TNODE *root) {

	QUEUE np={0};
	TNODE *nd;
	if (!root)return;
	enqueue(&np,root);
	while(np.front){
			nd=dequeue(&np);
			printf("%c",nd->data);
			if(nd->left)enqueue(&np,nd->left);
			if(nd->right)enqueue(&np,nd->right);	
	}
}

/* use auxiliary queue data structure for the algorithm */
TNODE *iterative_bf_search(TNODE *root, int val) {
TNODE *np;
QUEUE q={0};
if(!root)return NULL;
enqueue(&q,root);
while(q.front){
		np=dequeue(&q);
		if(np->data==val){
			return np;
			clean_queue(&q);
		}
		else{
			if(np->left)enqueue(&q,np->left);
			if(np->right)enqueue(&q,np->right);	
	}
}
}

/* use auxiliary stack data structure for the algorithm */
TNODE *iterative_df_search(TNODE *root, int val) {
if(!root)return NULL;
TNODE *p=NULL,*cp=NULL;
STACK s={0};
push(&s,root);
while(s.top){
		p=peek(&s);
		if(p->data==val){
			clean_stack(&s);
			return p;	
		}
		else if(cp==NULL){
			if(p->left!=NULL){
				push(&s,p->left);
				p=peek(&s);
			}
			else if(p->right!=NULL){
				push(&s,p->right);
				p=peek(&s);
			}
			else{
				cp=p;
				pop(&s);
				
			}	
		}
		else if(cp!=NULL){
			if(cp==p->left && p->right!=NULL){
				cp=NULL;
				push(&s,p->right);
			}
			else{
				cp=p;
				pop(&s);
			}
		}
				
	}
	return NULL;
}

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
   QNODE *p = (QNODE*) malloc(sizeof(QNODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}
void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    QNODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}
void clean_queue(QUEUE *qp) {
  QNODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {
  SNODE *p = (SNODE*) malloc(sizeof(SNODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}
void pop(STACK *sp) {
  if (sp->top != NULL) {
    SNODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}
void *peek(STACK *sp) {
  if (sp->top != NULL) {
     return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp) {
  SNODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}	
