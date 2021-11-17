#include <stdio.h>
#include <stdlib.h>
 
// struct Node
// {
//     int data;
//     struct Node *next;
// };
 
// void linkedListTraversal(struct Node *head)
// {
//     struct Node *ptr = head;
//   do
//   {
//     printf("Element is:  %d\n", ptr->data);
//     ptr = ptr->next;
//   } while (ptr != head);
  
// }
 
// int main()
// {
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;
//     struct Node *fourth;
 
//     // Allocate memory for nodes in the linked list in Heap
//     head = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));
//     fourth = (struct Node *)malloc(sizeof(struct Node));
 
//     // Link first and second nodes
//     head->data = 4;
//     head->next = second;
 
//     // Link second and third nodes
//     second->data = 3;
//     second->next = third;
 
//     // Link third and fourth nodes
//     third->data = 6;
//     third->next = fourth;
 
//     // Terminate the list at the third node
//     fourth->data = 1;
//     fourth->next = head;
 
//     linkedListTraversal(head);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *head)
{
    int i=1;
    struct Node *ptr = head;
    do
    {
        printf("Element at position %d is  %d\n",i, ptr->data);
        ptr = ptr->next;
        i++;
    }while(ptr != head);
}
struct Node * createLinkedList(struct Node * head, int val){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;

    if(head == NULL){
       head = newnode;
       head->next = head;
    }
    else{
    struct Node *ptr  = head;
    while(ptr->next != head)
    {
        ptr  = ptr->next;
    }
      ptr->next = newnode;
      newnode->next = head;
    }
   return head;
}
int main()
{
    int num;
    
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    
    head=createLinkedList(head, 10);
    head=createLinkedList(head, 20);
    head=createLinkedList(head, 30);
    head=createLinkedList(head, 40);
   
    linkedListTraversal(head);
    return 0;
}
