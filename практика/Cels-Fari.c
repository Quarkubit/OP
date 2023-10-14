#include <stdio.h>
#include <stdlib.h>



int main()
{
    int f=-4, cels;
    int low, up;
    int arr[150];
    low = -4; 
    up = 68; 
    int i=1,x=0;
    while (f <= up) 
    {
        printf("%d\t",x);
        x+=1;
        cels = 5 * (f-32) / 9;
        arr[i-1]=f;
        arr[i]=cels;
        printf("F:%d\tC:%d\n",arr[i-1],arr[i]);
        i+=2;
        f++;
        printf("\n");
    }

    system("pause");
    return 0;
}

