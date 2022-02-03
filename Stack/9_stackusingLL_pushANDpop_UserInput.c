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
{   int a[10], x;
    struct node *top;
    top = malloc(sizeof(struct node));
    top = NULL;
    printf("Enter 5 elements you want to push:\n");
    for(int i=0; i<5; i++)
      scanf("%d", &a[i]);
    
    for(int i =0 ;i<5;i++)
    {
        top = push(top,a[i]);
    }
           
    traverse(top);

    printf("How many elements do you want to pop\n");
     scanf("%d", &x);

     for(int i = 0; i< x; i++)
        top = pop(top);
        
     printf("After popping: \n"); 
        
         
         traverse(top);
     

    return 0;
}