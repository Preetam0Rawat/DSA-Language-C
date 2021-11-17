#include<stdio.h>
#define max 100

void deletion(int *A, int *N, int pos)                    
{
  for(int i = pos; i<(*N); i++)
  {
       A[i] = A[i+1];
  }

   (*N)--;
}

int main()
{
  int a[max], n, i;
  int pos;
  printf("Enter the size \n");
  scanf("%d", &n);

  printf("Enter the elements \n");
  for(i = 0; i<n ; i++)
     scanf("%d", &a[i]);
 
  printf("Enter the index whose element you want to remove \n");
  scanf("%d", &pos);

  deletion(a, &n, pos);                                     

  printf("Array after deletion \n");
       for(int i = 0; i<n ; i++)
         printf("%d ", a[i]);

}