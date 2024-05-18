/*#include <stdio.h>
void swap(int *a,int *b);
int main()
{
	int a=100,b=200;
	printf("%d %d",a,b);
	swap(&a,&b);
	printf("%d %d",a,b);
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
/*#include <stdio.h>
int main()
{
	int *p,*q;
	int k;
	int i=3,j=4;
	p=&i;
	q=&j;
	k=p-q;
	printf("p=%x\nq=%x\nk=%d\n",p,q,k);
	return 0;
}*/
/*#include <stdio.h>
const int MAX=3;
int main()
{
	int var[]={10,100,200};
	int i,*ptr;
	ptr=&var[MAX-1];
	for(i=MAX-1;i>=0;i--)
	{
		printf("address:var[%d]=%x\n",i,ptr);
		printf("result:var[%d]=%d\n",i,*ptr);
		ptr--;
	}
	return 0;
}*/
#include <stdio.h>
const int MAX = 3;
int main()
{
	int var[]={10,100,200};
	int i,*ptr;
	ptr=var;
	for(i=0;i<MAX;i++)
	{
		printf("address:var[%d]=%x\n",i,ptr);
		printf("result:var[%d]=%d\n",i,*ptr);
		ptr++;
	}
	return 0;
}
