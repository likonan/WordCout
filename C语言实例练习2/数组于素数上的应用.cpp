#include <stdio.h>
int main()
{
	const int maxNumber = 25;
	int isprime[maxNumber];
	int i,x;
	for(i=0;i<maxNumber;i++)
	{
		isprime[i]=1;
	}
	for(x=2;x<maxNumber;x++)
	{
		if(isprime[x])
		{
			for(i=2;i*x<maxNumber;i++)
			{
				isprime[i*x]=0;
			}
		}
	}
	for(i=2;i<maxNumber;i++)
	{
		if(isprime[i])
		{
		printf("%d\t",i);
		}
	}
	printf("\n");
	return 0;
}
