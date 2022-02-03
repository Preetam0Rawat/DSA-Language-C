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
void createLinkedList(struct Node **bighead, int val){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(*bighead == NULL)
       *bighead = newnode;
    else{
    struct Node *ptr  = *bighead;
    while(ptr->next != NULL)
       {
           ptr = ptr->next;
       }
   
    ptr->next = newnode;  
    }
}

void showhead(struct Node **bighead)
{
        printf("%d\n", (*bighead)->data);
    *bighead = (*bighead)->next;               // Here the bighead is not a pointer equal to head, but a pointer that has the address of head pointer, to reach head we need to use '*' in *bighead.
        printf("%d\n", (*bighead)->data);
    *bighead = (**bighead).next;               //WITHOUT ARROW
        printf("%d\n", (*(*bighead)).data);

}
int main()
{
    int num;
    
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    
    createLinkedList(&head, 10);
    createLinkedList(&head, 20);
    createLinkedList(&head, 30);
    createLinkedList(&head, 40);
   
    linkedListTraversal(head);

    showhead(&head);
    return 0;
}
