#include <stdio.h>

void bubble_sort(int array[], int n){
    for(int i=0; i<n-1; i++) //(n-1) because in first pass the the left most element may goes to second index
    {
        for(int j=0; j<n-1-i; j++) //(n-1-i) because at each pass the right most element get it's final position
        {
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array)/sizeof(array[0]);

    bubble_sort(array, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}