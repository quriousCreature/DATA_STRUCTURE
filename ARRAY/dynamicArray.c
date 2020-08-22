//  1 - Using single pointer. (single malloc call)
//  2 - Using array of pointers. (malloc for each rows).
//  3 - Using pointer to pointer. (double pointer {2 malloc call} 1.[for array of pointer for each row], 2.[for each 1-d array]).
//  4 - Using pointer to pointer. (similar to 3. but using single pointer call).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row=4,col=3;

void printArray(int *ptr){
    for(int i =0; i<row; i++)
        for(int j=0; j<col; j++)
            printf("%d, ", *(ptr + i*col + j));
}

int main() {
    int row=4, col=3;

    //single pointer contigious.  
      
    int arr[4][3] = {{12, 11, 10},{ 9, 8, 7},{ 6, 5, 4}, {3, 2, 1}};    // 0
    int (*p)[3];
    int **pt;
    pt = arr;
    p = arr;
    // int arr1[12] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int *ptr1 = malloc(row* col * sizeof(int));   // 1
    
    // double pointer non contigious.
    // array of pointer to point to each 1-D array. //each 1-D array needs to be allocated seperately
    // int * ptr2[row];                                            // 2
    // int ** ptr3 = malloc(row * sizeof(int *));                  // 3

    // double pointer non contigious.
    // array of pointers with space for all 1-D array.
    // But we need to intitialize each pointer to correct memory location.
    // int ** ptr4 = malloc(row * sizeof(int *) + row * col *(sizeof(int)));       // 4

    // Initializing 1 since it is similar to 0;

    for(int i =0; i<row; i++)
        for(int j=0; j<col; j++)
            *(ptr1 + i*col +j) = arr[i][j]; 
    
     for(int i =0; i<row; i++)
        for(int j=0; j<col; j++)
            printf(".%d. ,", pt[i][j]); 
            // printf("%d ,", p[i][j]); 

    // printf(" \n %zu \n", sizeof(*p));
    // printf(" \n %zu \n", sizeof(arr[0]));
    // printArray((int*)arr);

}