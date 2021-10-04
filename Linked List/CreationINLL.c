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
struct Node * createLinkedList(int n,struct Node * head){
    struct Node *tmp=head;
    struct Node *ptr;
    int num;

    for (int i=2;i<=n;i++){
        printf("value at position %d : ",i);
        scanf("%d",&num);
        ptr=malloc(sizeof(struct Node));
        ptr->data=num;
        ptr->next=NULL;
        tmp->next=ptr;
        tmp=ptr;
    }
    return head;
}
int main()
{
    int n,num;
    printf("Enter total number of elements you want to print\n");
    scanf("%d",&n);
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    printf("value at 1: ");
    scanf("%d",&num);
    head->data=num;
    head->next=NULL;
    
    head=createLinkedList(n,head);
   
    linkedListTraversal(head);
    return 0;
}
