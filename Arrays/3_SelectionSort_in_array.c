#include<stdio.h>
#define max 100 
void selectionsort(int *A, int N)       
{
  int i, min, j, pos, temp;
  for(i =0 ; i<N; i++)
  {
    min = A[i];
    pos = i; 
      for(j = i+1; j<N; j++)
      {
        if(A[j] < min)
          {  min = A[j];
             pos = j;
          }
      }
   temp = A[i];
   A[i] = min;
   A[pos] = temp; 

  }
}

int main()
{
    int a[max], n, i, temp, j;
    printf("Enter the size \n");
    scanf("%d", &n);

    printf("Enter elements \n");
    for(i = 0; i<n; i++)
      scanf("%d", &a[i]);
  
    selectionsort(a, n);
    
      
      printf("Array after sortng \n");
        for(i = 0; i<n; i++)
          printf("%d ", a[i]);     
}