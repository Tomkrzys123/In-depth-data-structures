#include "heap.h"

HEAP *new_heap(int capacity)
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->capacity = capacity;
    heap->size = 0;
    heap->hnap = (HNODE *)malloc(sizeof(HNODE) * capacity);
}

void insert(HEAP *heap, HNODE new_node)
{

    if (heap->size < heap->capacity)
    {
        heap->hnap[heap->size] = new_node;
    }
    else
    {
        heap->capacity *= 2;
        HNODE *temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
        if (temp)
        {
            heap->hnap = temp;
        }
        else
        {
            temp = malloc(sizeof(HNODE) * heap->capacity);
            if (temp)
            {
                memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
                free(heap->hnap);
                heap->hnap = temp;
            }
            else
            {
                printf("array resize failed\n");
            }
        }
        heap->hnap[heap->size] = new_node;
    }
    heap->size++;
    int curr_index = heap->size - 1;
    int parent_index = (curr_index - 1) / 2;
    while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1)
    {
        HNODE temp = heap->hnap[curr_index];
        heap->hnap[curr_index] = heap->hnap[parent_index];
        heap->hnap[parent_index] = temp;
        curr_index = parent_index;
        parent_index = (curr_index - 1) / 2;
    }
    return;
}

HNODE extract_min(HEAP *heap)
{
    HNODE min = heap->hnap[0];
    heap->hnap[0] = heap->hnap[heap->size - 1];
    free(heap->hnap + heap->size - 1);
    heap->size--;
    int curr_index = 0;
    int child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
    while (cmp(heap->hnap[curr_index].key, heap->hnap[child_index].key) == 1)
    {
        HNODE temp = heap->hnap[curr_index];
        heap->hnap[curr_index] = heap->hnap[child_index];
        heap->hnap[child_index] = temp;
        curr_index = child_index;
        child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
    }
    if (heap->size < heap->capacity / 2)
    {
        heap->capacity /= 2;
        HNODE *temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
        if (temp)
        {
            heap->hnap = temp;
        }
        else
        {
            temp = malloc(sizeof(HNODE) * heap->capacity);
            if (temp)
            {
                memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
                free(heap->hnap);
                heap->hnap = temp;
            }
            else
            {
                printf("array resize failed\n");
            }
        }
    }
    return min;
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
    if (heap->hnap[node_index].key > key_value)
    {
        heap->hnap[node_index].key = key_value;
        int curr_index = 0;
        int child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
        while (cmp(heap->hnap[curr_index].key, heap->hnap[child_index].key) == 1)
        {
            HNODE temp = heap->hnap[curr_index];
            heap->hnap[curr_index] = heap->hnap[child_index];
            heap->hnap[child_index] = temp;
            curr_index = child_index;
            child_index = 2 * curr_index + 2 < heap->size ? cmp(heap->hnap[2 * curr_index + 1].key, heap->hnap[2 * curr_index + 2].key) == -1 ? 2 * curr_index + 1 : 2 * curr_index + 2 : 2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
        }
    }
    else
    {
        heap->hnap[node_index].key = key_value;
        int curr_index = heap->size - 1;
        int parent_index = (curr_index - 1) / 2;
        while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1)
        {
            HNODE temp = heap->hnap[curr_index];
            heap->hnap[curr_index] = heap->hnap[parent_index];
            heap->hnap[parent_index] = temp;
            curr_index = parent_index;
            parent_index = (curr_index - 1) / 2;
        }
    }
}

int find_index(HEAP *heap, DATA value)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (heap->hnap[i].data == value)
            return i;
    }
    return -1;
}

void display_heap(HEAP *hp)
{
    printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
    printf("(index, key, data):\n");
    int i;
    for (i = 0; i < hp->size; i++)
    {
        printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
        if (i % 10 == 9)
            printf("\n");
    }
    printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b)
{
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}