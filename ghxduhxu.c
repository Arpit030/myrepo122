#include<stdio.h>
int main()
{
    int n,i,j,q;
    printf("enter the number\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
          q=n/i;
          for(j=2;j<=q/2;j++){
            if(q%j==0){
                printf("%d\t",q);
            }
          }
            }
        }
    }

