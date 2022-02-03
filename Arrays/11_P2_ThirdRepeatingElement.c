#include<stdio.h>
int main()
{
    int i,j,n, d=0, c= 0;
    printf("Enter the size :\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements\n");
    for(i = 0; i<n; i++)
       scanf("%d", &a[i]);

    for(i = 0; i<n; i++)
      {  c = 0;
          for(j = 0;j<n; j++)
          {
               
                if(a[i] != -1)
                {
                 if(a[i] == a[j]  && i != j)
                     {
                        c++;
                        a[j] = -1;
                     }
                }
          }
                if(c>0) 
                d++;
                if(d == 3)
                   {
                      printf("The third repeating number is  %d", a[i]);
                      break;
                    }
       }
       return 0;
      
}


