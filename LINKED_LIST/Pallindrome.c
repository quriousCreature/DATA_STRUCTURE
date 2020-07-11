#include<stdio.h>

#include "List.c"

void listIsPallindrome(struct Node * list) {
    struct Node * fakeStack = NULL; 
    struct Node * itr = list;
    while(itr) {
        listPush(&fakeStack, itr->data);
        itr = itr->next;
    }
    // pList(fakeStack);
    itr = list;
    while(itr && fakeStack) {
        if(itr->data != fakeStack->data) break;
        itr= itr->next;
        fakeStack = fakeStack->next;
    }
    if((itr == fakeStack && itr ==NULL)){
        printf("Its a pallindrome, \n");
    }
    else printf("NOT a pallindrome");

}
// Initial parameters to this function are &head and head 
bool isPalindromeUtil(struct Node** left, struct Node* right) 
{ 
    /* stop recursion when right becomes NULL */
    if (right == NULL) 
        return true; 
  
    /* If sub-list is not palindrome then no need to 
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next); 
    if (isp == false) 
        return false; 
  
    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data); 
  
    /* Move left to next node */
    *left = (*left)->next; 
  
    return isp1; 
} 
  
// A wrapper over isPalindromeUtil() 
bool isPalindrome(struct Node* head) 
{ 
    return isPalindromeUtil(&head, head); 
} 


bool checkPallindromeRec (struct Node** left, struct Node* right) {
    bool flag;
    if(!right) return true;

    if ( !checkPallindromeRec (left, right->next ) )
        return false;
    
    flag = ((*left)->data == right->data);
    *left = (*left)->next;
    return flag;
}

struct Node * getMidNode (struct Node * list) {
    int count=0;
    struct Node * mid=list;
    while(list) {
        if(!(count & 0x1)) mid = mid->next;
        ++count;
        list = list->next;
    }
    return mid;
}

int main(void) {
    struct Node * head = createList(6);
    

    head->next->next->next->data = 300;
    head->next->next->next->next->data = 200;
    head->next->next->next->next->next->data=200;

    struct Node * mid = getMidNode(head);
    pList(head);
    // listIsPallindrome(head);
    // mid && printf("Mid is %d \n", mid->data);
    checkPallindromeRec(&head, head) ? printf("Yes \n") : printf("No \n");

}
