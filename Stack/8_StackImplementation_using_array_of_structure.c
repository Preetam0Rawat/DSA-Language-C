#include<stdio.h>
struct number
{
    int data;
};

int isfull(int top)
{
  if(top == 9)
    return 1;
    else
    return 0;
}


int push (struct number *arr, int top, int val)
{
    if(isfull(top))
      printf("Stack overflow \n");

    else
    { 
        top++;
        arr[top].data = val;
        printf("%d\n", arr[top].data);

    }
    return top;
}

void display(struct number *arr, int top)
{
    while (top != -1)
    {
        printf("%d\n", arr[top].data);
        top--;
    }
    
}
void main()
{
    struct number arr[10];
    int top = -1;


    top = push(arr,top,20);
    top = push(arr,top,10);
    top = push(arr,top,35);
    top = push(arr,top,45);
    top = push(arr,top,55);
    top = push(arr,top,65);
    top = push(arr,top,75);
    top = push(arr,top,85);
    top = push(arr,top,95);
    top = push(arr,top,1);
    


    printf("Elements in stack are : \n");

   display(arr, top);

}