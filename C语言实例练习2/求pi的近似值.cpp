#include <stdio.h>
int main()
{
    double eps,items=1,itemm=1,sum=1;
    int i=1;
    double item=1;
    scanf("%le", &eps);
    while(item>=eps)
    {
        items*=i;
        itemm*=(2*i+1);
        item=items/itemm;
        i++;
        sum+=item;
    }
    printf("PI = %.5lf",sum*2);
    return 0;
    
    
}
