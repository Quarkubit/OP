#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;
    i=10;//10-тичная
    j=i+015;//8-ричная
    k=j*j+0xFF;//16-ричная
    printf("%d %d %d\n",i,j,k);

    system("pause");
    return 0;
}