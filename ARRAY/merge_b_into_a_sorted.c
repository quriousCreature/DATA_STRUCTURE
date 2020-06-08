#include <stdio.h>
#define NA -1

void printArray(int arr[], int size) 
{ 
  int i; 
  for (i=0; i < size; i++) 
    printf("%d ", arr[i]); 
  
  printf("\n"); 
} 

void move_to_end(int *arr, int size) {
    int i= --size;
    while(i>=0){
        if(arr[i] != NA) arr[size--] = arr[i];
        i--;
    }
    // printf("%d")
    // printArray(arr, 9 );
}


void merge(int *arr, int *N, int a, int b){
    int i,j,k;
    k=j=0;
    i=b;

    while(k<a+b){

        if(( i<a+b && arr[i]<N[j] ) || (j==b)){
            arr[k++] = arr[i++];
        }
        else
        {
            arr[k++] = N[j++];
        }
        
    }

}

int main(){
    int a,b, arr[]={2, 8, NA, NA, NA, 13, NA, 15,NA, 20, NA, NA, NA},
    N[] = {1,5, 7, 9,11, 14,19, 25}; 
    b = sizeof(N)/4;
    a = sizeof(arr)/4 - b;
   

    move_to_end(arr, a+b);
    printArray(arr, a+b);

    merge(arr, N, a, b);

    printArray(arr, a+b);


}

