#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traverse(struct node *head)
{   struct node *ptr = head;
    int i=1;
    while (ptr != NULL)
    {
        printf("Element at position %d is  %d\n",i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

struct node* createlist_and_insertatbeg( struct node *head, int val)
{   
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    if(head == NULL){
      newnode->next = NULL;
      newnode->prev = NULL;
      head = newnode;
      return head;
    }
    else
    {
       newnode->prev = NULL;
       newnode->next = head;
       head->prev = newnode;
       head = newnode;
       return head;
    }
}

struct node* insertatend(struct node*head, int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr= ptr->next;
    }
   newnode->data = val;
   newnode->next  = NULL;
   newnode->prev = ptr;
   ptr->next  = newnode;

   return head;

}

struct node* insertatindex(struct node*head, int val, int pos)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node* ptr = head;
    for(int i = 0; i < pos-1; i++)
    {
        ptr = ptr->next;
    }
    newnode->data = val;
    newnode->next = ptr->next;
    ptr->next = newnode;
    newnode->prev = ptr;

    return head;
}

struct node* deleteatstart(struct node*head)
{
    struct  node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);

    return head;
}  

struct node* deleteatend(struct node*head)
{   
    struct  node *ptr = head;
    struct node *q;
    while(ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    q = ptr->prev;
    q->next = NULL;
    free(ptr);
    return head;
}  
struct node* deleteatindex(struct node*head, int pos)
{   
    struct  node *ptr = head;
    struct node *q;
    for(int i =0; i < pos-1; i++){    
      ptr = ptr->next;
    }
   q = ptr->next;
   ptr->next = q->next;

   return head;

}  

int main()
{
  struct node *head = malloc(sizeof(struct node));
  head = NULL;

  head = createlist_and_insertatbeg(head, 50);
  head = createlist_and_insertatbeg(head, 40);
  head = createlist_and_insertatbeg(head, 30);
  head = createlist_and_insertatbeg(head, 20);
  head = createlist_and_insertatbeg(head, 10);

  head = insertatend(head, 60);
  head = insertatend(head, 70);
  head = insertatend(head, 80);

  head = insertatindex(head, 65, 6);

  traverse(head);

  head = deleteatstart(head); 
  head = deleteatend(head);
  head = deleteatindex(head, 5);


  
  printf("List after deletion \n");
  traverse(head);
}