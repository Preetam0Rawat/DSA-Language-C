#include<stdio.h>
#define max 100 
void insertionsort(int *A, int N)       
{
  int i,j,temp;
  for(i = 1; i< N-1; i++)
  {
     temp = A[i] ;
     j = i-1;
        
         while ((temp < A[j])  && (j>=0))
         {
          A[j+1] = A[j];
          j--;
         }
      A[j+1] = temp;   
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
  
    insertionsort(a, n);
    
      
      printf("Array after sortng \n");
        for(i = 0; i<n; i++)
          printf("%d ", a[i]);     
}