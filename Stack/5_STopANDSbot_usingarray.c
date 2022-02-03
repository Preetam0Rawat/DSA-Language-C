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
   if(isfull(ptr) == 1)  printf("Stack Overflow\n");
  
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
int stacktop(struct stack *ptr)
{
    int val;
    val = ptr->arr[ptr->top];
    return val;
}


int stackbot(struct stack *ptr)
{
    int val;
    val = ptr->arr[0];
    return val;
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

     push(s,10);
     push(s,20);
     push(s,30);
     push(s,40);
     push(s,50);

     printf("Top's current value is %d\n", s->top);

     
     printf("Stack's top value is %d\n", stacktop(s));
     printf("Stack's bottom value is %d\n", stackbot(s));


     pop(s);
     pop(s);
     pop(s);
     pop(s);
     pop(s);

   return 0;
}
