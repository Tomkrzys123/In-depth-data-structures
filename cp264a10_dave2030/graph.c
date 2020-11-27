#include <stdio.h>
#include <stdlib.h> 
#include "graph.h"

GRAPH *new_graph(int vertex_number) {
GRAPH *gp = malloc(sizeof(GRAPH));   
ADJNODE **np = malloc(vertex_number * sizeof(ADJNODE*));  
int i;
for (i = 0; i < vertex_number; i++)  
	np[i] = NULL;gp->adjlist = np;  
gp->order = vertex_number;
gp->size = 0;
return gp;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
if (*(g->adjlist + from) == NULL) {
		// add edge
		ADJNODE *np = (ADJNODE *) malloc(sizeof(ADJNODE));
		np->vertex = to;
		np->weight = weight;
		np->next = NULL;
		*(g->adjlist + from) = np;
		g->size++;
	// non-empty adjaceny list
	} else {
		// traverse list
		ADJNODE *current = *(g->adjlist + from);
		while (!(current->vertex == to && current->weight == weight) && current->next != NULL) current = current->next;
		// edge in list
		if (current->vertex == to && current->weight == weight) current->weight = weight;
		// edge not in list
		else {
			// add edge
			ADJNODE *np = (ADJNODE *) malloc(sizeof(ADJNODE));
			np->vertex = to;
			np->weight = weight;
			np->next = NULL;
			current->next = np;
			g->size++;
		}
	}

}

int get_weight(GRAPH *g, int from, int to) {

	if (*(g->adjlist + from) == NULL) return INFINITY;
	else {
		
		ADJNODE *current = *(g->adjlist + from);
		while (current->vertex != to && current != NULL) current = current->next;
	
		if (current->vertex == to) return current->weight;
		else return INFINITY;
	}
}

void clean_graph(GRAPH **gp) {
if (*gp) {
	
		GRAPH *graph = *gp;
		ADJNODE *current = NULL;
		ADJNODE *temp = NULL;
	
		for (int i = 0; i < graph->order; i++) {
		
			current = *(graph->adjlist + i);
			while (current != NULL) {
				
				temp = current;
				current = current->next;
				free(temp);
			}
		}
		*gp = NULL;
	}
}

void display_graph(GRAPH *g) {
  if (g == NULL) return;
  printf("\nweighted graph in adjacency list");
  printf("\norder: %d", g->order);
  printf("\nsize: %d", g->size);
  printf("\nnode from: (to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\nnode %d:", i);
    ptr = g->adjlist[i];
    while (ptr != NULL) {
      printf(" (%d, %d)", ptr->vertex, ptr->weight);
      ptr = ptr->next;
    }
  }
}