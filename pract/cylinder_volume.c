#include <stdio.h>
#include <stdlib.h>



int main()
{
    float R, h,v,pi;
    pi=3.14;
    printf("input \'R\', than \'h\'\n");
    scanf("%f %f\n",&R,&h);
    v=R*R*h*pi;
    printf("%.2f\n",v);

    system("pause");
    return 0;
}