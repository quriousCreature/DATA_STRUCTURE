#include <stdio.h>

#include "List.c"


void listDetectLoop(struct Node *list)
{
    struct Node *hare, *tortoise;
    hare = tortoise = list;
    int count = 0;

    while (hare && hare->next)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        // printf("Hare at -- %d \t Tortoise at -- 5d",hare->data, tortoise->data) 
        if (hare == tortoise)
        {
            printf("Loop Exists at -- %d \n", hare->data);
            break;
        }
    }
    if (hare != tortoise)
    {
        printf("Loop Does not Exist \n");
        return;
    };
    //
    if (hare == tortoise)
        while (tortoise->next != hare)
            tortoise = tortoise->next, ++count;
    printf("Length of loop %d \n", ++count);
    tortoise = list;
    while (tortoise != hare)
        tortoise = tortoise->next, hare = hare->next;
    if (hare == tortoise)
        printf("Loop starts at -- %d \n", hare->data);
}

void listDetectLoopBrent(struct Node *list)
{
    if (list == NULL)
    {
        printf(" [--EMPTY LIST--] ");
        return;
    }
    struct Node *hare, *tortoise;
    int pow = 1, len = 0;

    tortoise = hare = list;
    while (hare)
    {
        hare = hare->next;
        ++len;
        if (hare == tortoise)
        {
            printf(" Loop Exists \n");
            break;
        }
        if (len == pow)
        {
            pow *= 5;
            len = 0;
            tortoise = hare;
        }
    }
    if (hare != tortoise || hare == NULL )
        printf("NO LOOP EXIST \n");
    else
    {
        tortoise = hare = list;
        pow = len;
        while (len--)
        {
            hare = hare->next;
        }
        while (hare != tortoise){
            tortoise=tortoise->next;
            hare=hare->next;
            ++len;
        }
        if(hare == tortoise) printf("LOOP STARTS AT: %d   of  length : %d \n", tortoise->data, pow);
    }
    
}

int main(void)
{
    struct Node *head = createList(100);
    struct Node *tail = listFindTail(head);
    pList(head);
    listDetectLoopBrent(head);
    tail->next = head->next->next->next->next->next->next;
    //creating loop
    listDetectLoopBrent(head);

    // pList(head);

    return 0;
}