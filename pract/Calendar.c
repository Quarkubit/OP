#include <stdio.h>
#include <stdlib.h>



int main()
{
    int se=0, mi=0, h=0, da, we=0, mo=0, ye=0;
    printf("input the number of days\n");
    scanf("%d",&da);
    //h=da*24;
    //mi=h*60;
    //se=mi*60;
    ye=(da-da%365)/365;
    mo=(da-ye*365)/30;
    we=(da-ye*365-mo*30)/7;
    da=da-ye*365-mo*30-we*7;


    printf("%d year\n%d month\n%d week\n%d days\n",ye,mo,we,da);

    system("pause");
    return 0;
}