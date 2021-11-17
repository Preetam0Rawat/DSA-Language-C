#include<stdio.h>
#define max 100
void selectionsort(int *A, int N)       
{
  int min, i, j, temp, pos;
  for(i=0; i<N; i++)
  {
    min = A[i];
    pos =i;                            
    for(j = i+1; j<N; j++)
    {                                 
      if(A[j] < min)                
       { min = A[j];
         pos = j;
       }
    }
    temp = A[i];
    A[i] = min;
    A[pos] = temp;

  }
}

void binarysearch(int *A, int N, int ele)
{   
    int beg, end, mid;
    beg = 0; end = N-1, mid = (beg+end)/2;
    
    while((beg <= end) && (A[mid] != ele))           // If element not present then beg become greater than end and if present a[mid] = element.
    {
      if( ele < A[mid])
        end = mid-1;

      else
        beg = mid+1;
    
      mid = (beg+end)/2;
    }

    if(A[mid] == ele)
     printf("Data is present\n");
    else
     printf("Data is not present\n");
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

    selectionsort(a,n);
    binarysearch(a, n, ele);
    
}
