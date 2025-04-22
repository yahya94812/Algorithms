#include <stdio.h>

void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // merge two sorted arrays
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            array[k++] = L[i];
            i++;
        }
        else
        {
            array[k++] = R[j];
            j++;
        }
    }

    if (i == n1)
    {
        while (j < n2)
        {
            array[k++] = R[j];
            j++;
        }
    }
    else
    {
        while (i < n1)
        {
            array[k++] = L[i];
            i++;
        }
    }
}


void merge_sort(int array[], int left, int right)
{
    if(left < right){
        int mid = left + (right - left) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    merge(array, left, mid, right);
    }
    
}


int main()
{
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array) / sizeof(array[0]);

    merge_sort(array, 0, n-1);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}