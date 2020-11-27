#include <stdio.h>
#include <stdlib.h> 
#include "heap.h"
#include "graph.h"
#include "edgelist.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *g, int start) {
    if(g == NULL) return NULL;
    int heapindex, u, n = g->order;
    int t[n];

    for(int i=0; i<n; i++) t[i] =0;
    int p[n];

    HNODE hn;
    HEAP *h = new_heap(4); 

    t[start] =1;

    ADJNODE *temp = g->adjlist[start];

    while(temp){
        hn.key = temp->weight;
        hn.data = temp->vertex;
        insert(h,hn);
        p[temp->vertex] = start;
        temp = temp->next;

    }

    EDGELIST *mst = new_edgelist();
    int i;
    while(h->size >0){
        hn = extract_min(h);
        i = hn.data;
        t[i] =1;
        add_edge_end(mst, p[i], i, hn.key);

        temp = g->adjlist[i];
        while(temp){
            heapindex = find_index(h, temp->vertex);
            if(heapindex >= 0){
                if(t[temp->vertex] == 0 && temp->weight < h->hnap[heapindex].key){
                    decrease_key(h, heapindex, temp->weight);
                    p[temp->vertex] =i;
                }

            }else{
                if(t[temp->vertex] == 0){
                    hn.key = temp->weight;
                    hn.data = temp->vertex;
                    insert(h,hn);
                    p[temp->vertex] = i;

                }
            }
            temp = temp->next;
        }
    }
    return mst;
}


EDGELIST *spt_dijsktra(GRAPH *g, int start) {
    if(g == NULL) return NULL;
    int i, heapindex, u, n = g->order;
    int t[n], p[n], label[n];
    for(i =0; i<n;i++){t[i] =0; label[i]= 9999;}
    HNODE hn;
    HEAP *h = new_heap(4);

    ADJNODE *temp = g->adjlist[start];
    t[start] = 1;
    label[start] =0;

    while(temp){
        hn.key = temp->weight + label[start];
        hn.data = temp->vertex;
        insert(h, hn);

        p[temp->vertex] = start;
        temp = temp->next;
    }

    EDGELIST *spt = new_edgelist();
    while(h->size > 0){
        hn = extract_min(h);
        i = hn.data;
        t[i] =1;
        label[i] = hn.key;
        add_edge_end(spt, p[i],i,hn.key);
        temp = g->adjlist[i];
        while(temp){
            heapindex = find_index(h, temp->vertex);
            if(heapindex >= 0){
                if(t[temp->vertex] == 0 && temp->weight + label[temp->vertex] < h->hnap[heapindex].key){
                    decrease_key(h, heapindex, temp->weight + label[temp->vertex]);
                    p[temp->vertex] = i;
                }
            }
            else{
                if(t[temp->vertex] == 0){
                    hn.key = temp->weight ;
                    hn.data = temp->vertex;
                    insert(h, hn);
                    p[temp->vertex] = i;
                }
            }
            temp = temp->next;
        }

    }

    return spt;
}

EDGELIST *sp_dijsktra(GRAPH *g, int start, int end) {
    if(g == NULL) return NULL;

    int i, heapindex, u, n = g->order;
    int t[n], p[n], label[n];
    for(i =0; i<n;i++){t[i] =0; label[i]= 9999;}
    HNODE hn;
    HEAP *h = new_heap(4);

    ADJNODE *temp = g->adjlist[start];
    t[start] = 1;
    label[start] =0;

    while(temp){
        hn.key = temp->weight + label[start];
        hn.data = temp->vertex;
        insert(h, hn);

        p[temp->vertex] = start;
        temp = temp->next;
    }

    EDGELIST *spt = new_edgelist();

    while(h->size > 0){
        hn = extract_min(h);
        i = hn.data;
        t[i] =1;
        label[i] = hn.key;
        add_edge_end(spt, p[i],i,hn.key);
        if(i != end){
            temp = g->adjlist[i];

            while(temp){
                heapindex = find_index(h, temp->vertex);
                if(heapindex >= 0){
                    if(t[temp->vertex] == 0 && temp->weight + label[temp->vertex] < h->hnap[heapindex].key){
                        decrease_key(h, heapindex, temp->weight + label[temp->vertex]);
                        p[temp->vertex] = i;
                    }
                }
                else{
                    if(t[temp->vertex] == 0){
                        hn.key = temp->weight + label[i] ;
                        hn.data = temp->vertex;
                        insert(h, hn);
                        p[temp->vertex] = i;
                    }
                }

                temp = temp->next;
            }
        }
        else{
            break;
        }
    }

    i = end;
    EDGELIST *sp = new_edgelist();
    while(1){
        if(i == start) break;
        add_edge_start(sp,p[i],i, label[i]-label[p[i]]);
        i = p[i];
    }
    return sp;
}