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

// Deleteing when a data is given. Data is also called key
struct Node * deleteatvalue(struct Node *head, int data)
{
    struct Node *p = head;   
    struct Node *q = head->next;     
   
    while(q->data != data && q->next != NULL)  // If there would be no NULL checking then loop will keep on going
    {
        p = p->next;
        q = q->next;
    }
     
     if(q->data == data)
        { p->next = q->next;
          free(q); 
        }
        return head;               
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
    head = deleteatvalue(head, 41);
    printf("After deletion\n");
    linkedListTraversal(head);

    return 0;
}
