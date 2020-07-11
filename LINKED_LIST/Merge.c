#include <stdio.h>

#include "List.c"
// #define max

typedef struct Node Node;


Node * mergeRev(Node * list1, Node * list2){
    // if(list1==NULL && list2 == NULL) return NULL;
    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->data < list2->data){ 
        list1->next = mergeRev(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeRev(list2->next, list1);
        return list2;
    }

}

Node * mergeItr(Node * list1, Node * list2){
    if(!list1) return list2;
    if(!list2) return list1;

    Node * list = NULL;
    Node ** tail = &list;

    while(1) {
        if(!list1) { 
            *tail = list2;
            break;
        }
        if(!list2) { 
            *tail = list1;
            break;
        }

        if( list1->data < list2->data){
            *tail = list1;
            list1 = list1->next;
        }
        else
        {
            *tail = list2;
            list2 = list2->next;
        }
        
        tail = &((*tail)->next);
    }
    return list;
}

Node* mergeItr2(Node * list1, Node * list2) {

    Node *curr = list1;

    while(1){
        if(curr->next == NULL) {
            curr->next = list2;
            break;
        }
        if(list2 == NULL) {
            break;
        }
        if(curr->next->data < list2->data){
            curr = curr->next;
        }
        else
        {   
            Node * temp = list2;
            list2 = list2->next;
            temp->next = curr->next;
            curr->next = temp;
            curr = temp;
        }
        
    }
    return list1;

    
}


int main(void) {
    // Node *head = createList(10);
    Node *head1 = createNode(11);
    head1->next = createNode(22);
    head1->next->next = createNode(33);
    head1->next->next->next = createNode(44);
    head1->next->next->next->next = createNode(55);
    // head1->next->next->next->next->next = common;

    Node *head2 = createNode(1);
    head2->next = createNode(15);
    head2->next->next = createNode(34);
    head2->next->next->next = createNode(200);

    pList(head1);
    pList(head2);

    // pairSwap2(&head);
    // pList(mergeRev(head1, head2));
    pList(mergeItr2(head1, head2));

}