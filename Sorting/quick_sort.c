#include <stdio.h>

int partition(int array[], int low, int high)
{
    int pivot_value = array[low];
    int i = low + 1;
    int j = high;
    while (1)
    {
        while (i <= high && array[i] < pivot_value)
            i++;
        while (array[j] > pivot_value)
            j--;

        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        else
        {
            int temp = array[low];
            array[low] = array[j];
            array[j] = temp;
            return j;
        }
    }
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
    }
}

int main()
{
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, n - 1);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}