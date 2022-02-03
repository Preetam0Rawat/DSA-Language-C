#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int  top;
    int *arr;
};

int isempty(struct stack *ptr)
{ 
   if(ptr->top == -1)
     return 1;
   else 
     return 0;
 
}

int isfull(struct stack *ptr)
{ 
   if(ptr->top == ptr->size-1)
     return 1;
   else 
     return 0;
 
}

void push(struct stack *ptr, int val)
{
   if(isfull(ptr))  printf("Stack Overflow\n");
  
   else
      ptr->top++;
      ptr->arr[ptr->top] = val;
}

void pop(struct stack *ptr)
{
   if(isempty(ptr) == 1)  printf("Stack Underflow\n");
  
   else
   { 
      printf("%d Popped successfully\n", ptr->arr[ptr->top]);
      ptr->top--;
   }
}
void display(struct stack *ptr)
{    printf("Elements int the stack are: \n");
     while(ptr->top != -1)
    {
        printf("%d\n", ptr->arr[ptr->top]);
        ptr->top--;
    }
}

int main()
{   struct stack *s;
    s = (struct stack*) malloc (sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int*) malloc (s->size * sizeof(int)); 

    if(isempty(s))
     printf("Stack is empty\n");
    else
     printf("Stack is not empty\n");

     push(s,10);                                  // I made push a void type and not a return type because here i am working on an array so the changes I made there will reflect here automatically
     push(s,20);                                  // if u want, u can make this a return type function and return s from above
     push(s,30);                                  // I did the same for pop
     push(s,40);
     push(s,50);


   if(isempty(s))
     printf("Stack is empty\n");
   else
     printf("Stack is not empty\n");

     pop(s);
     pop(s);
    
     display(s);
     
   return 0;
}
