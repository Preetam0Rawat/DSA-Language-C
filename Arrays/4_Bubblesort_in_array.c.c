#include<stdio.h>
#define max 100
void bubblesort(int *A, int N)
{  int i, j, temp;
   for(i = 0; i<N; i++)
   {
    for(j = 0; j<N; j++)
    {
      if(A[j] > A[j+1])         // In bubble sort two adjacent values are sorted at a time. It is a lengthy process with lot of passes.
      {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  
  } 
}
int main()
{
    int a[max], n, i;
    printf("Enter the size \n");
    scanf("%d", &n);

    printf("Enter elements \n");
    for(i = 0; i<n; i++)
      scanf("%d", &a[i]);

      bubblesort(a, n);
  
   
      
      printf("Array after sortng \n");
        for(i = 0; i<n; i++)
          printf("%d ", a[i]);     
}