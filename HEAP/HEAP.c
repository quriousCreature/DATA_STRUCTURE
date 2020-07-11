#include<stdio.h>

#include "../../SORTING/myArray.c"

#define getParent(i) ((i-1)/2)
#define getLeftChild(i) (2*i+1)
#define getRightChild(i) (2*i+2)

void MaxHeapify(int *Arr, int index, int size){
    int largest = index;
    int left = getLeftChild(index);
    int right = getRightChild(index);

    if(left < size && Arr[left] > Arr[largest])
        largest = left;
    if(right < size && Arr[right] > Arr[largest])
        largest = right;
    
    if(largest != index) {
        swap(&Arr[largest], &Arr[index]);
        MaxHeapify(Arr, largest, size);
    }
    
}

void BuildMaxHeap(int *Arr, int size){
    for(int i= size/2-1; i>=0 ; i--) {
        MaxHeapify(Arr, i, size);
    }
}

int ExtractMax(int *Arr, int size) {
    
    swap(Arr, &Arr[--size]);
    MaxHeapify(Arr, 0, size);
    return Arr[size];
}

void BubbleUp(int *arr, int index){
    int parent = getParent(index);
    if(parent >= 0 && arr[parent] < arr[index]){
        swap(&arr[parent], &arr[index]);
        BubbleUp(arr, parent);
    }
}

void Insert(int *arr, int size, int key) {
    arr[size++] = key;
    BubbleUp(arr, size-1);
}

int main(void) {
    int arr[50] = {0,1,2,3,5,4,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    pArray(arr,25);
    BuildMaxHeap(arr, 20);
    pArray(arr, 25);
    ExtractMax(arr, 20);
    pArray(arr, 25);
    Insert(arr, 19, 100);
    pArray(arr, 25);
}
