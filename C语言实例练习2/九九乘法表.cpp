#include <stdio.h>
int main()
{
   int n;
   n=9;
   int i,j;
   i=1;
   while(i<=9)
   {
   	j=1;
   	while(j<=i)
	   {
 		printf("%d*%d=%d",j,i,j*i);
 		if(i*j<10)
 		printf("   ");
 		else
 		printf("  ");
		 j++;  		
	   }
	   printf("\n");
	   i++;
   }
   return 0;
   
}
