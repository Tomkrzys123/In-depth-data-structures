#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {

    EDGELIST *elp = (EDGELIST *) malloc(sizeof(EDGELIST));
    elp->size = 0;
    elp->start = NULL;
    elp->end = NULL;
    return elp;

}

EDGE *new_edge(int from, int to, int weight) {

    EDGE *ep = (EDGE *) malloc(sizeof(EDGE));
    ep->from = from;
    ep->to = to;
    ep->weight = weight;
    ep->next = NULL;
    return ep;

}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    
    // empty edge list
    if (g->start == NULL) {
        // append to end of list
        EDGE *ep = new_edge(from, to, weight);
        g->start = ep;
        g->end = ep;
        g->size++;
    // non-empty edge list
    } else {
        // traverse list
        EDGE *current = g->start;
        while (!(current->from == from && current->to == to) && current->next != NULL) current = current->next;
        // edge in list
        if (current->from == from && current->to == to) current->weight = weight;
        // edge not in list
        else {
            // append to end of list
            EDGE *ep = new_edge(from, to, weight);
            current->next = ep;
            g->end = ep;
            g->size++;
        }
    }

}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    
    // empty edge list
    if (g->start == NULL) {
        // insert to front of list
        EDGE *ep = new_edge(from, to, weight);
        g->start = ep;
        g->end = ep;
        g->size++;
    // non-empty edge list
    } else {
        // insert to front of list
        EDGE *ep = new_edge(from, to, weight);
        ep->next = g->start;
        g->start = ep;
        g->size++;
    }

}

int weight_edgelist(EDGELIST *g) {
    
    if (g->start == NULL) return 0;
    int total = 0;
    EDGE *ep = g->start;
    while (ep != NULL) {
        total += ep->weight;
        ep = ep->next;
    }
    return total;

}

void clean_edgelist(EDGELIST **gp) {
    
    if (*(gp) != NULL) {
        EDGELIST *elp = *gp;
        EDGE *ep = elp->start;
        EDGE *temp = NULL;
        while(ep != NULL) {
            temp = ep;
            ep = ep->next;
            free(temp);
        }
        *gp = NULL;
    }

}

void display_edgelist(EDGELIST *g) {

    if (g == NULL) return;
    printf("\nweighted graph in edge list");
    printf("\nsize: %d", g->size);
    printf("\nformat: (from, to, weight)");
    EDGE *p = g->start;
    while (p) {
        printf("\n(%d, %d, %d)", p->from, p->to, p->weight);
        p = p->next;
    }

}