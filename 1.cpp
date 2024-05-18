/*#include <stdio.h>
#include <math.h>
int main()
{
	double i;
	double xn = 1.0,sum = 1.0, x;
	scanf("%lf",&x);
	for(i=1;abs(xn)>=0.000001;i++)
	{
		xn=xn*x*((0.5-(i-1))/i);
		sum+=xn;
	}
	printf("%lf",sum);
	return 0;
}*/
#include <stdio.h>
#include <math.h>
int main()
{
	double i;
	double sn = 1.0,s,an = 1.0,x;
	scanf("%lf",&x);
	for(i=1.0;;i++)
	{
		s = sn;
		an = (an*x*(0.5-(i-1)))/i;
		sn = sn + an;
		if(abs(an)>=0.000001)
		{
			break;
		}
	}
	printf("%.6f\n",sn);
	return 0;
}
