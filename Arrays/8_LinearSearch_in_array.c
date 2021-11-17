#include<stdio.h>
#define max 100
void linearsearch(int *A, int N, int ele)
{   int pos, flag = 0;
    for(int i =0; i<N; i++)
    {
        if(A[i] == ele)
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if(flag)   printf("Element is there at index %d\n", pos);
    else       printf("Element was not found \n");
}



int main()
{
    int a[max], n, i, ele;
    printf("Enter the size \n");
    scanf("%d", &n);

    printf("Enter elements \n");
    for(i = 0; i<n; i++)
      scanf("%d", &a[i]);
    
    printf("Enter element to be searched \n");
    scanf("%d", &ele);

    linearsearch(a, n, ele);
    
}