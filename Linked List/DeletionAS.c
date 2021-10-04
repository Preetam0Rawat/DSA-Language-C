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

struct Node *deleteatfirst(struct Node *head)            // There is a star or the reason there is a(*)after struct node is because the value that has to be returned is a pointer
{   
    struct Node *ptr = head;  // we created ptr because we wanted to free the memory that we took from the heap            
    head = head->next;        // whether we can free the head and return ptr is still unkown, will tell ya all later 
    free(ptr);
    return head;
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
    head = deleteatfirst(head);
    printf("After deleteion\n");
    linkedListTraversal(head);

    return 0;
}
