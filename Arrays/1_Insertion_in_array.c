#include<stdio.h>
#define max 100

void insertion(int *A, int *N, int pos, int ele)                    // N is a pointer here , holding the address of n from main
{
  for(int i = (*N)-1; i>=pos; i--)
  {
       A[i+1] = A[i];
  }
  
   A[pos] = ele;

   (*N)++;
}


int main()
{
  int a[max], n, i;
  int pos, ele;
  printf("Enter the size \n");
  scanf("%d", &n);

  printf("Enter the elements \n");
  for(i = 0; i<n ; i++)
     scanf("%d", &a[i]);
 
  printf("Enter the index and the element to be inserted \n");
  scanf("%d%d", &pos, &ele);

  insertion(a, &n, pos, ele);                                      // I sent the address of n because i incremented it there in the insertion function and want it here to reflect

  printf("Array after insertion \n");
       for(int i = 0; i<n ; i++)
         printf("%d ", a[i]);

}