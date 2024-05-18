#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d ",&a,&b,&c);
	int max;
	if(a>b)
	{
		max=b;
	}
	else
	{
		max=a;
	}
	if(max<c)
	{
		max=c;
	}
	printf("%d",max);
	return 0;
}
