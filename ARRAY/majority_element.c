// Using Moore voting algo

#include<stdio.h>

int find_majority_moore(int * arr, int size){
    int i=0, j=0, curr_element;
    while(i<size){
        if(j==0){ curr_element=arr[i]; j++;}
        else if(curr_element == arr[i]) j++;
        else j--;
        i++;
    }
    return curr_element;
}

void check_majority(int *arr, int size, int maj_ele){
    int i=0, count=0;
    while(i<size){
        arr[i]==maj_ele ? count++ : 0;
        if (count >= size/2+1) break;
        i++;
    }
    if(count >= size/2+1) printf("Majority element:  %d", maj_ele);
    else printf("Majority element does not exists");
}


int main( ){
    int arr[]= {4,5,4,4,4,6,6,6,4};
    int s = sizeof(arr)/sizeof(int);
    check_majority(arr, s, find_majority_moore(arr, s) );

}