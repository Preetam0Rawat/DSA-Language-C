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

char* infixToPrefix(char* infix)
{
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->stack = (char *) malloc(sp->size * sizeof(char));
    char * prefix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    strrev(infix);



      int i=0; // Track infix traversal
    int j = 0; // Track prefix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }
        else if(infix[i] == ')')                       //if my infix was(a+b), then the reverse will be )b+a(, hence i changed '(' to ')' and vis-a-ver copying from infixtopostfix
        {
            push(sp,infix[i]);
            i++;
        }

        else if(infix[i] == '(')
        {
          while(stackTop(sp) != ')')
          {
              prefix[j] = pop(sp);
              j++;
          }
          pop(sp);
          i++;
        }

        else
        {
            if(precedence(infix[i]) >= precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else{
                prefix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        prefix[j] = pop(sp);
        j++;
    }
    prefix[j] = '\0';

        strrev(prefix);
        return prefix;


}

int main()
{
    char  infix[50];                                //"(a+b)*(c+d)"
    printf("Enter infix expression\n");
    scanf("%s", &infix);
    printf("prefix is %s", infixToPrefix(infix));
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 
// struct stack
// {   
//     int size;
//     int top;
//     char *stack;
// };
 
// int stackTop(struct stack* sp)
// {
//     return sp->stack[sp->top];
// }
 
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// void push(struct stack* ptr, char val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->stack[ptr->top] = val;
//     }
// }
 
// char pop(struct stack* ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         char val = ptr->stack[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
// int precedence(char ch){
//     if(ch == '*' || ch=='/')
//         return 3;
//     else if(ch == '+' || ch=='-')
//         return 2; 
//     else if(ch == '^')
//         return 1; 
//     else
//         return 0;
// }
 
// int isOperator(char ch){
//     if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch =='^' || ch == '(' || ch == ')') 
//         return 1;
//     else
//         return 0;
// }
// char *reversestring(char *str)
// {
//    static char revstr[50];
//    int len, j =0;
//    len = strlen(str);
//    for(int i = len-1; i>=0; i-- )
//    {
//        if(str[i] == '(')
//        {
//            revstr[j] = ')';
//            j++;
//        }

//        else if(str[i] == ')')
//         {
//            revstr[j] = '(';
//            j++;
//        }
//        else
//           {
//               revstr[j] = str[i];
//               j++;
//           }
//    }
//    return revstr;                      
// }
// char* infixToPrefix(char* infix)
// {
//     struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
//     sp->size = 10; 
//     sp->top = -1;
//     sp->stack = (char *) malloc(sp->size * sizeof(char));
//     char * prefix = (char *) malloc((strlen(infix)+1) * sizeof(char));
//     char *newinfix; 
//     newinfix = reversestring(infix);

// int i=0; // Track infix traversal
//     int j = 0; // Track postfix addition 
//     while (newinfix[i]!='\0')
//     {
//         if(!isOperator(newinfix[i]))
//         {
//             prefix[j] = newinfix[i];
//             j++;
//             i++;
//         }
//         else if(newinfix[i] == '(')
//         {
//             push(sp,newinfix[i]);
//             i++;
//         }

//         else if(newinfix[i] == ')')
//         {
//           while(stackTop(sp) != '(')
//           {
//               prefix[j] = pop(sp);
//               j++;
//           }
//           pop(sp);
//           i++;
//         }

//         else
//         {
//             if(precedence(newinfix[i]) >= precedence(stackTop(sp)))
//             {
//                 push(sp, newinfix[i]);
//                 i++;
//             }
//             else{
//                 prefix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty(sp))    
//     {
//         prefix[j] = pop(sp);
//         j++;
//     }
//     prefix[j] = '\0';
//     strrev(prefix);
//     return prefix;


// }

// int main()
// {
//     char  infix[50];                                //"(a+b)*(c+d)"
//     printf("Enter infix expression\n");
//     scanf("%s", &infix);
//     printf("prefix is %s", infixToPrefix(infix));
//     return 0;
// }


//BOTH are correct with slight difference but i prefer first one