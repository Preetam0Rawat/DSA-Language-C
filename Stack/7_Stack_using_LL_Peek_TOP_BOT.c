#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isfull(struct node *top)
{  
    struct node *n = malloc(sizeof(struct node));
    if(n == NULL)
      return 1;
    else
      return 0;
}

int isempty(struct node *top)
{
    if(top == NULL)
      return 1;
    else
      return 0;
}

struct node * push(struct node *top, int val)
{  
    if( isfull(top))
      printf("Stack overflow \n");
    else 
    {
    struct node *nnode = (struct node*) malloc (sizeof(struct node));
    nnode->next = top;
    nnode->data = val;
    top = nnode;
    return top;
    }

}

struct node *pop(struct node *top)
{  
    if( isempty(top))
      printf("Stack underflow \n");
    else 
    {
      struct node *ptr;
      ptr = top;
      top = top->next;
      printf("Popped element is : %d\n", ptr->data);
      free(ptr);
      return top;
   
    }

}

int peek(struct node *top, int val)
{   struct node* ptr = top;
    int i =1;
    while(i!=val && ptr != NULL)       // ptr != NULL is here in case user input a position that does not exist in the stack
    {
        ptr = ptr->next;
        i++;
    }
    
    if(ptr != NULL)
      return ptr->data;
    else
    return -1;
}

int stacktop(struct node *top)
{
    return top->data;
}

int stackbot(struct node *top)
{   struct node *bot = top;
    while(bot->next != NULL)
    {
        bot = bot->next;
    }
    return bot->data;
}

void traverse(struct node *top)
{   int i=1;
    while(top != NULL)
      {   
          printf("Element %d is :%d\n", i, top->data);
          top = top->next;
          i++;
      }
}

int main()
{                                
    struct node *top;                           
    top = malloc(sizeof(struct node));         
    top = NULL;
   
      top  = push(top, 10);
      top  = push(top, 20);                      
      top  = push(top, 30);
      top  = push(top, 40);
      top  = push(top, 50);

      traverse(top);

      printf("Peeked value is : %d \n",peek(top,3));
      printf("Stack top is    : %d\n",stacktop(top));
      printf("Stack top is    : %d\n",stackbot(top));
      traverse(top);



    return 0;
}