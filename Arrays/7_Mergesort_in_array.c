#include<stdio.h>
#define max 100 
void merge(int *A, int low, int mid, int high)
{
  int i, j, k, B[100];
  i = low; j = mid+1; k = low;

  while((i <= mid) && (j <=high))
  {
    if(A[i] < A[j])
    {
      B[k] = A[i];
      i++; k++;
    }
    else
    if(A[j] < A[i])
    {
      B[k] = A[j];
      j++; k++;
    }
  }

  while(i <= mid)
  {
    B[k] = A[i];
    i++; k++;
  } 
  
  while(j <= high)
  {
    B[k] = A[j];
    j++; k++;
  }

  for(int i = low; i<=high; i++)
  {
    A[i] = B[i];
  }
}

void mergesort(int *A, int low, int high)
{
  if(low<high)
  {
    int mid = (low+high)/2;

    mergesort(A,low,mid);
    mergesort(A,mid+1,high);

    merge(A, low, mid, high);
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
  
    mergesort(a, 0, n-1);
    
      
      printf("Array after sortng \n");
        for(i = 0; i<n; i++)
          printf("%d ", a[i]);     
}