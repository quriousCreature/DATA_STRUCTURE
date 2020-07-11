#include<stdio.h>

int factorial(int i, int current_fact) {
    // int x=i;
    if (i==1) return current_fact;
    return factorial(i-1, current_fact * i);

}

int fact (int num) {
    if(num == 1) return 1;
    return fact(num-1) * num;
}

int main() {
    // printf("Factorial is %d \n", factorial(5,1) );
    printf("Factorial is %d \n", fact(5) );
} 