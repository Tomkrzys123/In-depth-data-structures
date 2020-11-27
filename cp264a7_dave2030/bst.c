#include "bst.h"
TNODE* search(TNODE *root, char *name) {
	while(root) {
		if(strcmp(name, root->data.name) == 0) return root;
		if(strcmp(name, root->data.name) < 0) root = root->left;
		else root = root->right;
	}
	return NULL;
}



void insert(TNODE **rootp, char *name, float score) {
	TNODE *new = (TNODE *) malloc(sizeof(TNODE));
    new->left = NULL;
    new->right = NULL;
	strcpy(new->data.name, name);
	new->data.score = score;
	if(*rootp==NULL){
		*rootp = new;
	}
	else {
		TNODE *p = *rootp;
		while(1) {
			if(p==NULL)break;
			if(strcmp(new->data.name, p->data.name) == 0) {
				printf("Name already found.\n"); return;
			}
			if(strcmp(new->data.name, p->data.name) < 0) {
				if(!(p->left)) {p->left = new; break;}
				else p = p->left;
			}
			else {
				if(!(p->right)) {p->right = new; break;}
				else p = p->right;
			}
			
		}
	}
}



void delete(TNODE **rootp, char *name) {

	TNODE *tnp, *parentp, *minrn;
	if(!(*rootp)) {
		printf("\nBST is empty");
	} 
	else {
		parentp = NULL;
		tnp = *rootp;
		while(tnp && name != tnp->data.name) { 
			parentp = tnp;
			tnp = (strcmp(name, tnp->data.name) < 0) ? tnp->left : tnp->right;
		}
		if(!(tnp)) { 
			printf("\nName not found.");
		}
		else{ 
			if(!(tnp->right)) { 
				(!(parentp)) ? (*rootp = tnp->left) :
				((parentp->left == tnp) ? (parentp->left = tnp->left) : (parentp->right = tnp->left));
			}
			else if(!(tnp->left)) { 
				(!(parentp)) ? (*rootp = tnp->right) :
				((parentp->left == tnp) ? (parentp->left = tnp->right) : (parentp->right = tnp->right));
			}
			else {
				minrn = extract_smallest_node(&(tnp->right)); 
				minrn->left = tnp->left; 
				minrn->right = tnp->right;
				(!(parentp)) ? (*rootp = minrn) :
				((parentp->left == tnp) ? (parentp->left = minrn) : (parentp->right = minrn));
			}
		}
		free(tnp);
	}
}



TNODE *extract_smallest_node(TNODE **rootp) {
	if(!(*rootp)) return NULL;
	TNODE *tnp = *rootp, *parentp = NULL;
	while(tnp->left) {
		parentp = tnp;
		tnp = tnp->left;
	}
	if(tnp == *rootp) {
		if(!(tnp->right))
			*rootp = NULL;
		else
			*rootp = tnp->right;
	}
	else{
		parentp->left = tnp->right;
	}
	return tnp;
}



void display_inorder(TNODE *root) {
    if (root) {
        if (root->left) display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right) display_inorder(root->right);
    }
}

void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_tree(&root->left);
        if (root->right)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}
