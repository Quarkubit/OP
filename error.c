#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int fahr, celsius;
    int lower, upper;
    int mas[150];
 
    lower = -4;
    upper = 68;
    int i = 1;
 
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        mas[i - 1] = fahr;
        mas[i] = celsius;
 
        printf("first:\t%d\t%d\n", mas[i - 1], mas[i]);                 //line 1.
        printf("second\t!%d!\t%d\t%d\n", fahr, mas[i - 1], mas[i]);     //line 2.
        printf("%d\t%d\n", mas[i - 1], mas[i]);                         //LINE 3!? почему не выводится?
 
        i += 2;
        ++fahr;
        break;
    }
 
    system("pause");
    return 0;
}