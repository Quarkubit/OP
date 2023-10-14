#include <stdio.h>
#include <stdlib.h>

int main() {
    float a,b,res;
    int x;
    printf("input digits\n");
    scanf("%f %f",a,b);
    printf("1. addition \n2. subtraction \n3. multiplication \n4. division\n");
    scanf("%d",x);
    
    switch (x)
    {
    case 1:
        res=a+b;
        break;
    case 2:
        res=a+b;
        break;
    case 3:
        res=a+b;
        break;
    case 4:
        res=a+b;
        break;
    default:
        return -1;
    }

    printf("result: %.2f\n",res);



    system("pause");
    return 0;
}