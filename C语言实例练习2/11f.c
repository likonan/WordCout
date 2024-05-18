/*
#include <stdio.h>
 
int main(){
	int x, n;
	int i;
	scanf("%d%d", &x, &n);
	int rst = x;
	for(i=0; i<n-1; i++){
		rst *= x;
		rst %= 1000;
	}
	if(rst == 0) printf("000");
	else if(rst < 10) printf("00%d", rst);
	else if(rst < 100) printf("0%d", rst);
	else printf("%d", rst);
	return 0;
}*/
