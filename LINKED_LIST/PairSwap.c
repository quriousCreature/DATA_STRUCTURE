#include <stdio.h>

#include "List.c"

typedef struct Node Node;


void pairSwap(Node ** head){
    Node * curr = *head , *next=NULL;

    if(!curr && !curr->next){
        printf("List have less than two elements");
        return;
    }
    *head = curr->next;
    Node * prev = curr;

    while(curr != NULL && curr->next != NULL){
        prev->next = curr->next;
        prev = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        prev = curr;
        curr = curr->next;   
    }

}

void pairSwap2(Node ** head) {
    while( *head != NULL && (*head)->next != NULL) {
        Node * curr = *head;
        *head = curr->next;
        curr->next = (*head)->next;
        (*head)->next = curr;
        
        head = &(curr->next);
    } 
}



int main(void) {
    Node *head = createList(10);
    pList(head);

    pairSwap2(&head);
    pList(head);

}