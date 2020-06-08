//  given a list of n-1 integers and these integers are in the range of 1 to n.

#include<stdio.h>

int find_missing(int *arr, int size){
    int i,sum,total;
    i=sum=total=0;
    while(i<size){
        total += (i-arr[i]);
        // sum += arr[i];
        i++;
    }   
    return total+i; 
}

// int find_missing_xor(int *arr, int size){
    
// }

int main(){
    int size, arr[]= {0, 1, 2, 4, 5, 6, 7,8 };
    size = sizeof(arr)/sizeof(int);
    printf("M: %d \n", find_missing(arr, size));
}