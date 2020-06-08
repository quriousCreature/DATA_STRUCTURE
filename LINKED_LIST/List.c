#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "ListExtra.c"

#define LIST_EMPTY INT32_MIN

struct Node {
    int data;
    struct Node * next;
};

struct Node * createNode(int data) {
    struct Node *newNode = malloc( sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print list
void pList(struct Node * list) {
    printf("[");
    if(list == NULL){
        printf(" EMPTY ] \n");
        return;
    }
    while(list != NULL){
        printf(" %d ,", list->data);
        list = list->next;
    }
    printf(" ]\n");
}

// Reverse print list 
void reversePrintList(struct Node * list) {
    if(list == NULL) return;
    reversePrintList(list->next);
    printf("- %d -", list->data);

}

// Find the length of list
int listLength( struct Node *list){
    int count = 0;
    while (list != NULL) {
        ++count;
        list = list->next;
    }
    return count;
}

// Insert at front
void listPush(struct Node **ptr2head, int data) {
    struct Node * newNode = createNode(data);
    newNode->next = *ptr2head;
    *ptr2head = newNode;
}

// Remove from front
int listPop(struct Node **ptr2head) {
   if(listLength(*ptr2head) == 0) return LIST_EMPTY;  
   struct Node *node2pop= *ptr2head;
   int data = node2pop->data; 
   *ptr2head = node2pop->next;
   free(node2pop);
   return data;   
}

// Find 
struct Node * listFindData(struct Node * head, int data) {
    struct Node * currentNode = head;
    int count=0;
    for(; currentNode != NULL && currentNode->data != data; currentNode = currentNode->next,++count){
    };
    
    if(currentNode == NULL) printf("DATA NOT FOUND \n");
    else printf("Found data: %d at Node no: %d \n", currentNode->data, count);
    
    return currentNode;
}

// Inster after specified node
void insertAfterNode(struct Node * givenNode, int data) {
    if (givenNode == NULL) { printf("[ERROR] --INSERT AFTER NULL-- "); return; }

    // struct Node * newNode = createNode(data);
    // newNode->next = givenNode->next;
    // givenNode->next = newNode;

    listPush(&(givenNode->next), data);

}

// Insert Before a given node
void insertBeforeKey(struct Node ** head, int key, int data) {
    struct Node * currentNode, *previousNode;
    currentNode = (*head);
    if ((*head) == NULL) { 
        printf("[ERROR] --INSERT BEFORE NULL-- "); 
        return;
    }
    
    if ((*head)->data == key) {
        listPush(head, data);
        return;
    }    

    while(currentNode != NULL && currentNode->data != key){
        previousNode = currentNode;
        currentNode = currentNode->next;
    } 

    struct Node * newNode = createNode(data);
    newNode->next = previousNode->next;
    previousNode->next = newNode;

}

// Add node at the end.
void listAppend( struct Node ** head, struct Node ** tail, int data) {
    struct Node * newNode = createNode(data); 
    if((*head)==(*tail) && (*tail)==NULL ) (*head) = (*tail) = newNode;
    else {
        (*tail)->next = newNode;
        (*tail) = newNode;
    }
}

// Returns the tail of node
struct Node * listFindTail (struct Node * head) {
    struct Node * tail = head;
    while(head != NULL ){
        tail = head;
        head = head->next;
    }
    return tail;
}

// Delete the first occurance of key
void deleteNodeKey (struct Node ** ptr2head, int key ) {
    struct Node * currentNode= (*ptr2head);
    struct Node *previousNode;
    if((*ptr2head) != NULL && (*ptr2head)->data == key) { 
        previousNode = *ptr2head;
        (*ptr2head) = (*ptr2head)->next ;
        free(previousNode);
        return;
    }
    while(currentNode != NULL && currentNode->data != key){
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if( currentNode == NULL) printf("Node Not found \n");
    else {
        previousNode->next = currentNode->next;
        free(currentNode);
    }

}

//  Delete the node a given position
void deleteNodePos (struct Node ** ptr2head, int pos) {
    struct Node * currentNode = (*ptr2head);
    struct Node * prevNode;
    if(pos == 0) {
        prevNode = (*ptr2head);
        (*ptr2head) = (*ptr2head)->next;
        free(prevNode);
        return;
    }
    while(pos-- && currentNode !=NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == NULL) {printf("[ERROR] Postion out of Bound"); return;}

    prevNode->next = currentNode->next;
    free(currentNode);
}

// Delete list reccursive
void deleteList (struct Node **ptr2head) {
    if ((*ptr2head) == NULL) return;

    deleteList(&((*ptr2head)->next));
    free((*ptr2head));
    (*ptr2head)=NULL;
}

// Delete list iterative
void deleteListIterative (struct Node **ptr2head) {
    struct Node * currentNode = *ptr2head;
    struct Node * previousNode;
    while (currentNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        free(previousNode);
        // previousNode = NULL;
    }
    *ptr2head = NULL;

}

// Nth node from last
void printNodeLast (struct Node * head, int pos) {
    static bool reachedLast = false;
    static int posLast = 0;
    
    if(head == NULL) {
        reachedLast = true;
        return;
    }
    
    printNodeLast (head->next, pos);

    if(reachedLast ) {
        if(posLast == pos)
        printf("Data of %d th element from last is : %d \n", pos, head->data);
        
        posLast++;
    }
}

int main(void) {

    struct Node *HEAD, *TAIL;
    TAIL=HEAD = createNode(100);

    listPush(&HEAD, 200);
    listPush(&HEAD, 250);
    listPush(&HEAD, 300);
    listPush(&HEAD, 250);
    pList(HEAD);
    
    // insertAfterNode(listFindData(HEAD, 400), 2222);
    // pList(HEAD);
    printf("Tail is %d \n", (listFindTail(HEAD))->data);
    listAppend(&HEAD, &TAIL, 2020);
    listPush(&HEAD, 400);
    listPush(&HEAD, 350);
    pList(HEAD);
    insertBeforeKey(&HEAD, 300, 1111);
    insertAfterNode(listFindData(HEAD, 400), 8989);
    pList(HEAD);
    // reversePrintList(HEAD);

    // deleteNodeKey(&HEAD, 350);
    // deleteNodeKey(&HEAD, 2020);
    deleteNodePos(&HEAD, 4);
    // deleteListIterative(&HEAD);
    pList(HEAD);
    printNodeLast(HEAD, 0);
    // printf("Tail is %d \n", (listFindTail(HEAD))->data);

    // listAppend(&Head, &tail, 555);


}