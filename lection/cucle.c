#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, x, c;
    a=1;
    x=a++;
    a=1;
    c=++a;
    printf("a: %d | x: %d | c: %d\n",a,x,c);   

    system("pause");
    return 0;
}