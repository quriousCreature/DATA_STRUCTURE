#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int top;
    size_t capacity;
    int *ptr;
} stack;

stack * create_stack(size_t capacity) {
    stack *s = malloc(sizeof (stack));
    s->capacity = capacity;
    s->top = -1;
    s->ptr = malloc(sizeof(int)* capacity);
    return s;
}

bool isFull(stack * s){
    return s->top == s->capacity-1;
}

bool isEmpty(stack * s) {
    return s->top == -1;
}

void push(stack * s, int data) {
    if(!isFull(s)) s->ptr[++(s->top)] = data;
    else printf("[Stack FULL] can't push. \n");
}

int pop(stack *s ){
    if(isEmpty(s)){
        printf("[STACK EMPTY] can't pop.\n");
        return INT_MIN;
    }
    return s->ptr[s->top--];
}

int peek(stack *s) {
    if(isEmpty(s)){
        printf("[STACK EMPTY] can't peek.\n");
        return INT_MIN;
    }
    return s->ptr[s->top];
}

void pStack (stack *s ) {
    int i=0;
    if(isEmpty(s)) printf("Empty Stack \n ");
    while(i <= s->top) printf("%d, ", s->ptr[i++]);
    printf("\n");
}

// int main(){

//     stack *  S = create_stack(10);
//     for(int i=0; i<11; i++ ) {
//         push(S, i*i);
//     }
//     for(int i=0; i<11; i++ ) {
//         pop(S);
//     }
    
//     pop(S);
//     printf("%d \n", peek(S));
//     pStack(S);


// }