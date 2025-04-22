#include <stdio.h>

void binary_search(int array[], int n, int key){
    int high = n-1;
    int low = 0;

    while (low <= high)//Keep searching as long as there's at least one element to check (i.e. low == high may be the element we are looking for).
    {
        int mid = (high+low)/2;
        if(array[mid]==key){
            printf("%d found at index %d\n", key, mid);
            return;
        }
        else if(key < array[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    printf("element not found!\n");
    
}

int main(){
    int array[] = {2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(array)/sizeof(array[0]);

    int key = 7;
    binary_search(array, n, key);

    return 0;
}