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
    if( isempty(top)){
      printf("Stack underflow \n");
      return top;
    } 
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

void traverse(struct node *top)
{   if(top == NULL)
        printf("Stack empty \n");
    else
    {
      int i=1;
    while(top != NULL)
      {   
          printf("Element %d is :%d\n", i, top->data);
          top = top->next;
          i++;
    }
  }

}

int main()
{                                
    struct node *top;                          // Here i made the whole top NuLL, I could have just pointed top to null and give top->data a value in  main and then pushed values in new node using push function. 
    top = malloc(sizeof(struct node));         // Program's algorithm depends on the need of user.
    top = NULL;
   
      top  = push(top, 10);
      top  = push(top, 20);                      
      top  = push(top, 30);
      top  = push(top, 40);
      top  = push(top, 50);

      traverse(top);

      top = pop(top);          
      top = pop(top);          
      top = pop(top);          
      top = pop(top);          
      top = pop(top);          
      top = pop(top);          
      top = pop(top);          
               

      printf("After popping: \n");
      traverse(top);


    return 0;
}