#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertatindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    int i =0;
    struct Node *p = head;      /* p pointer mai head copy islie kra kyuki hume last mai head return krna hai to hum starting se queue print krna chahte hai
                                   agar ni kiya hota to queue wha se print hoti jha head pahuchta while loop chalne k baad, yha 2nd index se print hota agar 
                                   humne p ki jagah head ko traverse kiya hota
                                */
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;

    return head;                /* return head krte hai kyuki hume apni queue starting se print krni hai, agar ptr ko return krte to queue uss index  se print 
                                   hoti jha humne nya data dhala, idhar 3rd index se hta print 
                                */
}
 
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
 
    linkedListTraversal(head);
    head = insertatindex(head, 56, 3);
    printf("After insertion\n");
    linkedListTraversal(head);

    return 0;
}
