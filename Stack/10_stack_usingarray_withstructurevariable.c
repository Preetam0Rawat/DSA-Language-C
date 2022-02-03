#include<stdio.h>
#define max 100

struct stack
{
   int size;
   int top;
   int arr[max];
};

void display_stack(struct stack *psp)
{
    while(psp->top != -1)
    {
        printf("%d\n", psp->arr[psp->top]);
        psp->top--;
    }
}

void push(struct stack *psp, int val)
{
    psp->top++;
    psp->arr[psp->top] = val;
}
int main()
{
    struct stack sp;
    sp.size = 20;
    sp.top = -1;

    push(&sp, 10);
    push(&sp, 20);
    push(&sp, 30);
    push(&sp, 40);
    push(&sp, 50);


    display_stack(&sp);

    return 0;

}
