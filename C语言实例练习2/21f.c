#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int x,y,z;
	for(i=1;i<=n;i++)
	{
		x=i;
		y=50-4*i;
		z=3*i+50;
		printf("%d个5角 %d两分 %d个一分\n",x,y,z);
	}
	return 0;
}

