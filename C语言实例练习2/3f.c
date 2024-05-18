/*#include <stdio.h>
#include <math.h>
int main()
{
	int numf,nump;
	printf("请输入屋顶数。\n");
	scanf("%d",&numf);
	double sum=0,x,y;
	int i;
	for(i=1;i<=numf;i++)
	{
		printf("请分别输入屋顶坐标和人数。\n");
		scanf("%lf,%lf %d",&x,&y,&nump);
		double d=sqrt(x*x+y*y);
		double t=d*2/50+nump*1.5;
		sum+=t;
	 } 
	 printf("总共用时%f\n",sum);
	return 0;
}*/
