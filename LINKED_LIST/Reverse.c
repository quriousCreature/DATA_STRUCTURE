#include<stdio.h>

#include "List.c"
// typedef struct Node * Node;

int printNthLast(struct Node *list, int Nth) {
    
    if (list==NULL) return Nth;
    
    Nth = printNthLast(list->next, Nth);

    if(Nth == 0 ) printf("Nth node is %d \n", list->data);

    return --Nth;

}
// my original
void listReverse(struct Node ** ptr2head, struct Node * head){

    if((*ptr2head)==NULL) printf("Can not reverse EMPTY LIST ! \n");

    if(head->next == NULL) {
        (*ptr2head) = head;
        return;
    }
    listReverse(ptr2head, head->next);

    head->next->next = head;
    head->next = NULL;
}

struct Node * listReverseReturn(struct Node * list) {
    if( list == NULL || list->next ==NULL ) return list;
    struct Node * head = listReverseReturn(list->next);
    list->next->next = list;
    list->next = NULL;

    return head;
}

// Using iteration and 2 pointers
void listRevIterative( struct Node ** ptr2head) {
    struct Node *current = *ptr2head;
    struct Node *prev = NULL;
    struct Node *next = NULL ;
    if((current) == NULL) printf("Can not reverse EMPTY LIST ! \n");
    if(current->next == NULL) return;

/*     while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
 */
// using only two pointers;
    while(current) {
        // swap prev with current->next;
        prev = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current->next);
        current -> next = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current->next);
        prev = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current->next);

        // Swap prev with current;
        prev = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current);
        current = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current);
        prev = (struct Node *) ((uintptr_t)prev ^ (uintptr_t)current);
    }

    *ptr2head = prev;
    // while(ptr2head != NULL)
}

// Tail resursion
struct Node* reverseList(struct Node* curr, struct Node* prev)
{
if (!curr) {
return prev;
}
struct Node* next = curr->next;
curr->next = prev;
return reverseList(next, curr);
}

// swap function
void swap(struct Node** pRoot, struct Node** pNew){
 /*    struct Node * temp =createNode((*pRoot)->data);
    temp->next = (*pRoot)->next;

    (*pRoot)->data = (*pNew)->data;
    (*pRoot)->next = (*pNew)->next;
    (*pNew)->data = temp->data;
    (*pNew)->next = temp->next; */

    struct Node * temp = *pRoot;
    *pRoot  = *pNew;
    *pNew = temp;
}

// using swaps.
void reverse(struct Node **pRootPtr)
{
struct Node *pNew = NULL;
struct Node *pRoot = *pRootPtr;

while (pRoot)
{
swap(&pRoot, &pNew);
swap(&pNew->next, &pRoot);
}

pRoot = pNew;
pList(pRoot);
}

//TODO implement using swaps and recursion
// struct Node * rev(struct Node * head) {
//     struct Node *new = NULL;
//     if(!head) return;
//     return 
// }

int main (void) {
    struct Node * head = createList(3);
    pList(head);

    // printNthLast(head, 19);
    // listReverse(&head, head);
    // head = listReverseReturn(head);
    // reverse(&head);
    listRevIterative(&head);
    pList(head);

}