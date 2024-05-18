#include <stdio.h>
int main()
{
	int i,n;
	double t,son=2.0,mom=1.0,sum=0.0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=son/mom;
		t=son;
		son=son+mom;
		mom=t;
		
	}
	printf("%.2f",sum);
	return 0;
 } 
