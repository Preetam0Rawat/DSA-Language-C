#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{   
    int size;
    int top;
    char *stack;
};
 
char stackTop(struct stack* sp)
{
    return sp->stack[sp->top];
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
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else if(ch == '^')
        return 1; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch =='^' || ch == '(' || ch == ')') 
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix)
{
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->stack = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if(infix[i] == '(')
        {
            push(sp,infix[i]);
            i++;
        }

        else if(infix[i] == ')')
        {
          while(stackTop(sp) != '(')
          {
              postfix[j] = pop(sp);
              j++;
          }
          pop(sp);
          i++;
        }

        else
        {
            if(precedence(infix[i])> precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char  infix[50];                                //"(a+b)*(c+d)"
    printf("Enter a infix expression\n");
    scanf("%s", &infix);
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
