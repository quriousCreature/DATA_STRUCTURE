// works with negative numbers

#include<stdio.h>
#define MAX 1000
#define ORIGIN 500

void print_pairs(int *a, int size, int sum){
    char hash_map[MAX]={0};
    char *hash_map_neg = &hash_map[ORIGIN];
    int i=0, temp;
    while(i<size){
        if(hash_map_neg[sum-a[i]]==1) printf("Pair exists:     %d, %d     \n", a[i], sum-a[i]);
        else hash_map_neg[a[i]]=1;
        i++;
    }
}

int main(){
    int a[]={10, 20, -25, 40, 50, 85, 35};

    print_pairs(a, sizeof(a)/sizeof(int), 60);
}