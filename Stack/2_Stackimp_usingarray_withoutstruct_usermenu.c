#include<stdio.h>
#include<stdlib.h>
#define max 50
int isfull(int top,int  size)
{
    if(top == size-1)
     return 1;
       return 0;
}

int push(int *arr, int size, int top, int val)
{  if(!isfull(top, size))
 { 
   top++;
   arr[top] = val;
 }
 else
 printf("stack overflow\n");
 return top;
}

int isempty(int top)
{
    if(top == -1)
      return 1;
       return 0;
}

int pop(int *arr, int size, int top)
{
  if(!isempty(top))
  {
    printf("element popped is : %d\n",arr[top]);
    top--;
  }
  else
  printf("stack underflow\n");
  return top;
}

void display(int *arr, int top, int size)
{
    while(top != -1)
    {
        printf("%d ", arr[top]);
        top--;
    }
}
int main()
{ 
    int arr[max], size, top = -1;
    int ch, ele;
    char choice;
    printf("Enter the size\n");
    scanf("%d", &size);

do{
    printf("You want to perform what\n");
    printf("1. push 2.pop 3.display\n");

    scanf("%d", &ch);
    
    
        switch(ch)
    {
        case 1:
              printf("Enter elememt you want to push\n");
              scanf("%d" , &ele);
              top = push(arr, size , top, ele);
              break;

        case 2:
              printf("popping....\n");
              top = pop(arr, size , top);
              break;

        case 3:
             printf("Displaying elements\n");
             display(arr, top, size);
             break;


        default:
            printf("Wrong choice\n");
    }

    printf("Want to enter more choices\n");
    scanf("%s", &choice);
    }while(choice == 'y');

    return 0;

}