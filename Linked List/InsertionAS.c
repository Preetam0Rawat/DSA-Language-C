#include <stdio.h>
#include <stdlib.h>
struct Node
{   int data;
    struct Node *next;
};
  void linkedListTraversal(struct Node *ptr)
{   while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertatfirst(struct Node *head, int data)            // There is a star or the reason there is a(*)after struct node is because the value that has to be returned is a pointer
{   struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;           /* These two can
                                replace themselves */
    ptr->next = head;              
    return ptr;
}
 int main()
{   struct Node *head;
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
    head = insertatfirst(head, 56);          //It is not necessary to make this function return type, just make copy of head in the insertatend function body.  CHECK "InsertAN" PROGRAM
    printf("After insertion\n");
    linkedListTraversal(head);

    return 0;
}
