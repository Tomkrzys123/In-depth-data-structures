#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *second);
void display_array(int *a, int n);
void selection_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void copy_array(int *a, int *b, int n);
int is_sorted(int *a, int n);

void display_array(int *a, int n)
{
  int i; 
  for (i=0; i<n; ++i) {
    if (i%10 == 0) printf("\n");
      printf("%3d ", *(a+i));
  }
  printf("\n"); 
}

void swap(int *left, int *second)
{
  int temp = *left;
  *left = *second;
  *second = temp;
}


void copy_array(int *a, int *b, int n)
{
for(int i=0;i<n;i++){
	*(b+i)=*(a+i);
}
}

int is_sorted(int *a, int n)
{
for(int i=0;i<n-1;i++){
	if(*(a+i)>*(a+i+1))return 0;
}
return 1;
}


void selection_sort(int *a, int left, int right)
{	
int i,j, k;
for (i= 0; i<= right; ++i) {
	k = i;
	for(j = i+1; j <= right ; ++j) {
		if (*(a+j) < *(a+k)) {
			k = j;
			}
	}
	if (i!= k)swap(a+k, a+i);      
}
}
void quick_sort(int *a, int left, int right)
{
 int key,i,j,k;
    if( left < right ) {  
        k = (left+right)/2; //midpt
        // use *(a+k) as the pivot; 
        swap(a+left, a+k); //swap left with pivot

        i = left +1; //move to right
        j = right;
        key = a[left];
        while(i <= j) {
            // split  such that elements from left to j  are less or equal *(a+k) 
            while((i <= right) && (a[i] <= key))
                i++; //keep moving to right
                
            //  elements from  j+2 to right  are bigger than  *(a+k) 
            while((j >= left) && (a[j] > key))
                j--; //move to left
            if( i < j)
                swap(a + i, a + j);
        }
        swap(a + left, a + j);

        quick_sort(a, left, j-1);
        quick_sort(a, j+1, right); 
     }
     //do nothing if left > right
// your implementation
}

