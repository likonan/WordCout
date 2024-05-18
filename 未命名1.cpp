#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	double xn=1.0,sum=0.0,x;
	scanf("%lf",&x);
	for(i=1;fabs(xn)>=0.000001;i++)
	{
		sum = sum+xn;
		xn = xn*x*((0.5-(i-1))/i);
	}
	printf("%lf",sum);
	return 0;
}
