#include <stdio.h>

void linear_search(int array[], int n, int key){
    for(int i=0; i<n; i++){
        if(array[i]==key){
            printf("%d found at index %d\n",key, i);
            return;
        }
    }
    printf("element not found!\n");
}

int main(){
    int array[] = {4, 2, 5, 7, 4, 3};
    int n = sizeof(array)/sizeof(array[0]);

    int key = 7;
    linear_search(array, n, key);

    return 0;
}