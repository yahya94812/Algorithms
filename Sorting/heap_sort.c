#include <stdio.h>

void heap_sort(int *, int);

int main(){
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array)/sizeof(array[0]);

    heap_sort(array, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}

void heap_sort(int array[], int n)
{
    build_heap(array, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(&array[0], &array[i]); //sort by rightmost elements from max heap
        heapify(array, i, 0); //heapify with out including (sorted) rightmost element
    }
}

void build_heap(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) //parent nodes are starting from "n/2 - 1" in 0-based index;
        heapify(array, n, i); //we are building max head; max elements are bubble up from bottom
}

void heapify(int array[], int n, int i) //parameters(array, size_of_array, index_to_heapify)
{
    int largest = i; //these are indexes not a value it self; here largest is the root node
    int left = 2 * i + 1; //index of left child in 0-based index
    int right = 2 * i + 2; //index of right child in 0-based index

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest); //now heapify from modified node i.e.. at "largest index"
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
