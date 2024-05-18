#include <stdio.h>
int main()
{
	int m,n;
	int i;
	int sum=0,cnt=0;
	scanf("%d %d",&m,&n);
	if(m==1)
		m=2;
	for(i=m;i<=n;i++)
	{
		int isprime=1;
		int j;
		for(j=2;j<=i-1;j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}
		}
		if(isprime)
			{
				cnt++;
				sum+=i;
			}
	}
	printf("%d %d",cnt,sum); 
	return 0;
}
