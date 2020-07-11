#include <stdio.h>

#include "List.c"

typedef struct Node Node;


void getIntersection(Node *head1, Node * head2) {
    Node *list1=head1 , *list2=head2;
    if(!(list1 && list2)) {
        printf("List Empty\n");
        return;
    } 

    while(list1 != list2){
        list1 = list1->next;
        list2 = list2->next;
        if(list1 == NULL && list2 != NULL) list1 = head2;
        if(list2 == NULL && list1 != NULL) list2 = head1;


    }

    if(list1) printf("Point of intersection : %d \n", list1->data);
    else printf("No intersection \n");
}

int main(void) {
    Node *common = createList(5);

    Node *head1 = createNode(11);
    head1->next = createNode(22);
    head1->next->next = createNode(33);
    head1->next->next->next = createNode(44);
    head1->next->next->next->next = createNode(55);
    // head1->next->next->next->next->next = common;

    Node *head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = common;


    getIntersection(head2, head1);



    pList(head1);
    pList(head2);
    // pairSwap2(&head);
    // pList(head);

}