// finds maximum sum for a contigious sub-array in an array.
// Dynamic programming 

#include<stdio.h>
#define MAX(a,b) a>b ? a : b

int max_sum_kadane(int *arr, int size){
    int i, current_sum, best_sum, current_start, best_start, best_end;
    i=current_sum=best_sum=current_start=0;
    
    while(i<size){
        current_sum = MAX(0, (current_sum+arr[i]));
        if(current_sum == arr[i]){
           current_start = i; 
        }
        best_sum = MAX(best_sum, current_sum);
        if(best_sum == current_sum){
            best_start=current_start;
            best_end = i;
        }
        i++;
    }
    printf("Index start: %d     end: %d\n", best_start, best_end);
    return best_sum;
}

int main(){
    int size, arr[]={-2, 1, -3, -4, -1, 2, 1, 5, 4};
    size = sizeof(arr)/sizeof(arr[0]);
    // size = max_sum_kadane(arr, size);
    printf("%d\n", max_sum_kadane(arr, size));

}