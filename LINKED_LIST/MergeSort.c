#include <stdio.h>

#include "List.c"
// #define max

typedef struct Node Node;

Node *getMid(Node *head);

Node *mergeRev(Node *list1, Node *list2)
{
    // if(list1==NULL && list2 == NULL) return NULL;
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list1->data < list2->data)
    {
        list1->next = mergeRev(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeRev(list2->next, list1);
        return list2;
    }
}

Node *MergeSort(Node *list)
{
    if (list == NULL )
        return NULL;
    if (list->next == NULL)
        return list;
    Node *mid = getMid(list);
    Node *right = mid->next;
    mid->next = NULL;
    // MergeSort(mid->next);
    // mid->next = NULL;
    // MergeSort(list);
    return mergeRev(MergeSort(list), MergeSort(right));
}

Node *getMid(Node *head)
{
    Node *fast = head->next;
    Node *mid = head;
    // while(fast != NULL && fast->next != NULL){
    //     fast= fast->next->next;
    //     mid = mid->next;
    // }
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            mid = mid->next;
            fast = fast->next;
        }
    }

    return mid;
}

// TODO revise
Node *MergeSortItr(Node *head) {
    if (!head) return NULL;
    Node *arr[32]={NULL};
    Node * result, *next;
    int i;
    result = head;
    while(result){
        next = result->next;
        result->next = NULL;

        for (i=0;(i<32) && (arr[i] != NULL); i++) {
            result = mergeRev(arr[i], result);
            arr[i] = NULL;
        }
        if(i == 32) i--;
        arr[i] = result;
        result = next;

    }
    result = NULL;
    for(i=0; i<32; i++)
        result = mergeRev(arr[i], result);
    return result;
}

int main(void)
{
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
    head2->next->next->next->next = head1;
    // pList(head1);
    pList(head2);

    // pairSwap2(&head);
    // pList(mergeRev(head1, head2));
    // pList(mergeItr2(head1, head2));
    // pList(MergeSort(head2));
    pList(MergeSortItr(head2));
}