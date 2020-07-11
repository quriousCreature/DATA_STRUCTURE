/* #include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node * next;
};


void printNthNodeLast (struct Node * head, int pos) {
    static bool reachedLast = false;
    static int posLast = 0;
    
    if(head == NULL) {
        reachedLast = true;
        return;
    }
    
    printNthNodeLast (head->next, pos);

    if(reachedLast && posLast == pos) {
        printf("Data of %d th element from last is : %d", pos, head->data);
        posLast++;
    }
} */