#include <stdio.h>
#include <math.h>
int main()
{
	double sum,m,n;
	scanf("%lf %lf",&m,&n);
	if(m<=1000)
	{
		sum=8;
	}
	else if(m>1000)
	{
		sum=8+ceil((m-1000)/500)*4;
	}
	if(n==1)
		sum+=5;
		printf("%f",sum);
	return 0;
}
