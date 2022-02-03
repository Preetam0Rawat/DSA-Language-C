#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    int *stack;
};
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->stack[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->stack[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int  prefixeva(char *prefix)
{   int i =0, val1, val2;
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50; 
    sp->top = -1;
    sp->stack = (int *) malloc(sp->size * sizeof(int));
    
    while(prefix[i] != '\0')
   {
        if(!isOperator(prefix[i]))
        {
           push(sp, prefix[i] - '0');
           i++;
        }

        else
        {
            val1 = pop(sp);
            val2 = pop(sp);

            switch(prefix[i])
            {
                case '+' : push(sp, val2 + val1);   break;
                case '-' : push(sp, val2 - val1);   break;
                case '*' : push(sp, val2 * val1);   break;
                case '/' : push(sp, val2 / val1);   break;

            }
           i++;
        }
     
    }

     return pop(sp);


}

int main()
{   
    char  prefix[50];                         //  "*+23+45";
    printf("Enter an prefix expression: \n");
    scanf("%s", prefix);
    strrev(prefix);

    printf("Resultant expression is : %d", prefixeva(prefix));
    return 0;
}
 