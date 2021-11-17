#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    int i=1;
    while (ptr != NULL)
    {
        printf("Element at position %d is  %d\n",i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}
struct Node * createLinkedList(struct Node * head, int val){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
       head = newnode;
    else{
    struct Node *ptr  = head;
    while(ptr->next != NULL)
       {
           ptr = ptr->next;
       }
   
    ptr->next = newnode;  
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
