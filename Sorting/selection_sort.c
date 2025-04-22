#include <stdio.h>

void selection_sort(int array[], int n){
   for(int i=0; i<n-1; i++){
    int min_index = i;
    for(int j=i+1; j<n; j++){
        if(array[j]<array[min_index]){
            min_index = j;
        }
    }
    if(min_index!=i){
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
   }
}

int main(){
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array)/sizeof(array[0]);

    selection_sort(array, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}