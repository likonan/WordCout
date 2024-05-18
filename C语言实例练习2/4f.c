/*
#include <stdio.h>
int main()
{
	int i;
	double lfmy=0,cost;
	double sgmy=0;
	for(i=1;i<=12;i++)
	{
		printf("请输入%d月花销。\n",i);
		scanf("%lf",&cost);
		lfmy+=300-cost;
		if(lfmy<=0)
		{
			printf("%d月花销超过拥有。\n",i);
			goto end;
		}
		if(lfmy>=100&&lfmy<=199)
		{
			sgmy+=100;
			lfmy=lfmy-100;
		}
		else if(lfmy>=200&&lfmy<=299)
		{
			sgmy+=200;
			lfmy=lfmy-200;
		}
		else if(lfmy==300)
		{
			sgmy+=300;
			lfmy=lfmy-300;
		}
	}
	sgmy*=1.2;
	printf("年末他共有%f元。\n",sgmy+lfmy);
	end:
	return 0;
}*/
