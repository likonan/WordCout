#include <stdio.h>
int main()
{
    int sum=0;
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=0;
            for(j=1;j<i;j++)
            {
                if(i%j==0)
                   sum+=j;}//未加完时相等
                if(sum==i)
                   printf("%d\n",i);
    }
    return 0;
}
