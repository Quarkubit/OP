#include <stdio.h>
#include <stdlib.h>



int main()
{
    printf("start of code\n\n");
    int f=-4, cels;
    int low, up;
    int arr[150];
    low = -4; 
    up = 68; 
    int i=1;
    //f = low;
    //printf(" %d\n",f);
    while (f <= up) 
    {
        //printf(" %d\t",f);
        cels = 5 * (f-32) / 9;
        //printf(" %d\n",cels);
        arr[i-1]=f;
        arr[i]=cels;
        printf("%d\t%d\n",arr[i-1],arr[i]);
        printf("F:%d\tC:%d\n",arr[i-1],arr[i]);
        i+=2;
        ++f;
        printf("\n");
    }
    printf("\n \nend of code\n");

    return 0;
}

