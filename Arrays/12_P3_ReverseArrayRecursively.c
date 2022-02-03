// #include<stdio.h>                                 // This code works fine but you have to create an aditional array in this one.
// #include<Stdlib.h>  
// int j =0;
// int arr[100];
// void reverse(int i, int n, int *a)
// {   
//     if(i == n)
//       return;
//     else{
//         reverse(i+1, n, a);
//         arr[j] = a[i]; j++;
//         }

// } 
// int main()
// {
//     int i,j,n;
//     int *array;
//     printf("Enter the size :\n");
//     scanf("%d", &n);
//     int *a = (int*) malloc(n*sizeof(int));
//     printf("Enter elements\n");
//     for(i = 0; i<n; i++)
//        scanf("%d", (a+i));

//     reverse(0,n,a);
    
//     for(i =0; i<n; i++)
//        printf("%d ", arr[i]);


//        free(a);
//        return 0;
      
// }

#include<stdio.h>
#include<stdlib.h>
void reverse(int *a, int start, int end)
{
    if(start < end)
     {
         int temp = a[start];
         a[start] = a[end];
         a[end] = temp;
        reverse(a, start+1, end-1);
     }
     return ;
}


int main()
{
    int i,j,n;
    int *array;
    printf("Enter the size :\n");
    scanf("%d", &n);
    int *a = (int*) malloc(n*sizeof(int));
    printf("Enter elements\n");
    for(i = 0; i<n; i++)
       scanf("%d", (a+i));

       reverse(a, 0, n-1);

    printf("After reversing recursively:\n");
    for(i =0; i<n; i++)
      printf("%d ", a[i]);
    return 0;
}
