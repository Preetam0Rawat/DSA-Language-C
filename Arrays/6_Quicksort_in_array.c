#include<stdio.h>
#define max 100 
int partition(int *A, int low, int high)
{
  int pivot = A[low];
  int i = low+1,  j= high, temp;

  do
  {
    while (A[i] <= pivot)    i++;
    
    while(A[j]  >  pivot)    j--;

    if(i < j)
    {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  } while(i < j);

  // swapping A[low] and A[j]
     temp = A[low];
     A[low] = A[j];
     A[j] = temp;
     return j;
  
}
void quicksort(int *A, int low, int high)       
{
  int partitionIndex;             //Index of pivot after partition
  if(low < high)
  {
    partitionIndex = partition(A, low, high);
    quicksort(A, low, partitionIndex-1);       //To sort left subarray
    quicksort(A, partitionIndex+1, high);      //To sort right subarray

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
  
    quicksort(a, 0, n-1);
    
      
      printf("Array after sortng \n");
        for(i = 0; i<n; i++)
          printf("%d ", a[i]);     
}