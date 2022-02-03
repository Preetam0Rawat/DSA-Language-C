#include<stdio.h>
#include<Stdlib.h>
struct stack
{
    int size;
    int top;
    char stack[];
};

int isempty(struct stack *s)
{
    if(s->top == -1)
    return 1;
    else
    return 0;
}

int isfull(struct stack *s)
{
    if(s->top == s->size-1)
    return 1;
    else
    return 0;
}

void push(struct stack *s,  char ch)
{
   if(isfull(s))
       printf("Stack Overflow \n");
    
    else
    {
     s->top++;
     s->stack[s->top] = ch;
    }
}


char pop(struct stack *s)
{   char val;
    if(isempty(s))
       {
           printf("Error : Stack underflow \n cant't perform paranthesis checking\n");
           exit (0);
       }
       else
       val = s->stack[s->top];
       s->top--;
       return val;

}
 int matching(char a, char b)
 {
     if(a=='{'  && b == '}')
         return 1;
     if(a=='['  && b == ']')
         return 1;
     if(a=='('  && b == ')')
         return 1;

     return 0;
 }
int main()
{
   char str[50], popped_ch;
   struct stack *s;
   s = malloc(sizeof(struct stack));

   s->size = 20;
   s->top = -1;

   printf("Enter a expression in char: \n");
   gets(str);

   for(int i =0; str[i]!='\0'; i++)                                          // Advisable to make a separate function.
   {
       if(str[i] == '(' || str[i] == '{'  ||str[i] == '[')
        push(s,str[i]);

         else 
          if(str[i] == ')' || str[i] == '}'  ||str[i] == ']')
             { popped_ch = pop(s);
               if(!matching(popped_ch, str[i]))
                    {  printf("Error : Paranthesis miss matching \n");
                       exit (0);
                    }
             }
         else
            continue;
   }


   if(isempty(s))
    printf("No problem found in paranthesis checking \n");

    else
        printf("Problem found in paranthesis checking \n");

   return 0;

}