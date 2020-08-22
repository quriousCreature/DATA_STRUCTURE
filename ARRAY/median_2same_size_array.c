#include<stdio.h>
#include<assert.h>

#define MAX(a,b) (a>b ? a : b)
#define MIN(a,b) (a>b ? b :a)

float median(int *arr, int size){
    if(size & 0x01) return arr[size>>1];
    return (arr[size>>1]+arr[(size>>1)-1])/2.0f;
    
}


float find_median(int *arr1, int *arr2, int size){
if(size <= 0) return -1;
if(size == 1) return (arr1[0]+arr2[0])/2;
// if(size==2)printf("MAX : %d \t Min %d \n",MAX(arr1[0], arr2[0]),MIN(arr1[1], arr2[1]) );
if(size == 2) return (MAX(arr1[0], arr2[0]) + MIN(arr1[1], arr2[1]))/2.0f;

float m1 = median(arr1, size);
float m2 = median(arr2, size);
// printf("Median 1 : %.2f, median 2 : %.2f , size: %d\n", m1, m2, size);
if (m1 == m2) return m1;

if (m1 < m2) 
{   if(size %2 == 0)return find_median(arr1 +size/2-1, arr2 , size/2+1);
    return  find_median(arr1 + size/2, arr2, size-size/2);
}
if (size %2 == 0) return find_median(arr2 +size/2-1, arr1, size/2+1);
    return find_median(arr2 +size/2, arr1, size-size/2);

}

int main () {
    int arr1[]={1, 3, 7,10,15,17}, arr2[]= {2,5,9,16,20,24}, size;
    size = sizeof(arr1)/sizeof(int);

    // printf("Median %f", median(arr1,4));
    printf("Median %.2f", find_median(arr1, arr2, size));
}