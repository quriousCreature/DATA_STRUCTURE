#include <stdio.h>

#include "List.c"

typedef struct Node Node;

void swap2Node( Node ** ptr2head, int x, int y){
    int foundBothNode = 0;
    if (x == y ) {
        printf("Nodes are same \n");
        return;
    }

    Node *prevX, *currX, *prevY, *currY, *prev;
    prevX = currX =  prevY = currY = prev = NULL;
    Node *curr = *ptr2head;
    while(curr && foundBothNode != 2){
        
        if(!currX){
        if(curr->data == x && ++foundBothNode) currX = curr;
        else prevX = curr;
        }

        if(!currY){
        if(curr->data == y && ++foundBothNode) currY = curr;
        else prevY = curr;
        }

        curr = curr->next;
    }

    if(!( currY && currX)) {
        printf("Node not present \n");
        return;
    }

    if(prevX == NULL) *ptr2head = currY;
    else  prevX->next = currY;

    if(prevY == NULL) *ptr2head = currX;
    else  prevY->next = currX;

    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;


    printf("X = %d,  Y = %d \n", currX->data, currY->data);

}

void swap2Node1(Node ** ptr2head, int x, int y) {
    if(*ptr2head == NULL){
        printf("[ EMPTY LIST ]");
        return;
    }
        if (x == y ) {
        printf("Nodes are same \n");
        return;
    }
    Node ** ptr2x, ** ptr2y;
    ptr2x= ptr2y= NULL;

    while(*ptr2head != NULL) {
        if((*ptr2head)->data == x) ptr2x = ptr2head;
        else if((*ptr2head)->data == y) ptr2y = ptr2head;

        ptr2head = &((*ptr2head)->next);
    }
    if( ptr2y == NULL || ptr2x ==NULL) {
        printf("Node not found \n");
        return;
    }

    Node *temp = *ptr2y;
    *ptr2y = *ptr2x;
    *ptr2x = temp;

    temp = (*ptr2y)->next;
    (*ptr2y)->next = (*ptr2x)->next;
    (*ptr2x)->next = temp;

    printf("X = %d,  Y = %d \n", (*ptr2x)->data, (*ptr2y)->data);
}

int main(void) {
    Node *head = createList(10);
    pList(head);

    swap2Node1(&head, 100, 000);
    pList(head);

}