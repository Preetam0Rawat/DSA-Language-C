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


void deletealtnode(struct Node *head)
{
    struct Node *prev = head;
    struct Node *node = head->next;

    while(prev != NULL && node != NULL)
    {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if(prev != NULL)
        {
          node = prev->next;
        } 
    }
}
int main()
{
    int num;
    
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    
    head = createLinkedList(head, 10);
    createLinkedList(head, 20);
    createLinkedList(head, 30);
    createLinkedList(head, 40);
    createLinkedList(head, 50);
    createLinkedList(head, 60);
   
    linkedListTraversal(head);

    deletealtnode(head);
   
    printf("After deletion of alternate nodes\n");
    linkedListTraversal(head);

    return 0;
}
