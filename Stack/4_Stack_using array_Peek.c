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


int peek(struct stack *ptr, int i)
{   int val, pos;
    pos = ptr->top -i +1;
    if( pos < 0)
      printf("Not a valid position\n");
    else
    val = ptr->arr[pos];
    return val;

}


int main()
{   struct stack *s;
    s = (struct stack*) malloc (sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int*) malloc (s->size * sizeof(int)); 

     push(s,10);
     push(s,20);
     push(s,30);
     push(s,40);

     
    for(int j =1; j<= s->top+1; j++)
    {
      printf("Value peeked at podition  %d is : %d\n", j,  peek(s,j));
    }

   return 0;
}
