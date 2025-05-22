#include <stdio.h>

void heap_sort(int array[], int n)
{
    build_heap(array, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, i, 0); 
    }
}

void build_heap(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
}

void heapify(int array[], int n, int i) //parameters(array, size_of_array, index_to_heapify)
{
    int largest = i; //these are indexes not a value it self
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

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
