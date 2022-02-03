#include<stdio.h>
int main()
{
    int i,j,n,t = 0;
    printf("Enter the size :\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements\n");
    for(i = 0; i<n; i++)
       scanf("%d", &a[i]);

    for(i = 0; i<n; i++)
      { 
          for(j = 0;j<n; j++)
          {
              if(a[j] == a[i] && i != j)
              break;
          }
          if(j==n)
          t++;
          if(t == 2)
           break;
      }

      if(t == 2)
       printf("Secnod non repeating number is %d", a[i]);

       return 0;
}



