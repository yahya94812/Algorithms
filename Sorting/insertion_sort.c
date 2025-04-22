#include <stdio.h>

void insertion_sort(int array[], int n){
   for(int i=1; i<n; i++){
    int key = array[i];
    int j = i-1;
    while(j>=0 && array[j]>key){
        array[j+1] = array[j];
        j--;
    }
    array[j+1] = key;
   }
}

int main(){
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array)/sizeof(array[0]);

    insertion_sort(array, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}