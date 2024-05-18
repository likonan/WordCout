#include <stdio.h>
int main()
{
	int t,a,b;
	scanf("%d/%d",&a,&b);
	while(b>0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	printf("%d/%d",a/t,b/t);
	return 0;
}
