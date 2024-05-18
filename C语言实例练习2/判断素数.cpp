#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,isprime;
    if(n<=1)
        isprime=0;
    else if(n==2)
        isprime=1;
    else{
    for(i=2;i<=n-1;i++)
    {
        if(n%i==0)
        {isprime=0;
         break;}
        else
            isprime=1;
    }
        }
    if(isprime)
        printf("%d is a prime.",n);
    else
        printf("%d is not a prime.",n);
        return 0;
}
