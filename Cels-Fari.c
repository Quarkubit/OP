#include <stdio.h>
#include <stdlib.h>



int main()
{
   int f, cels, low, up, arr[150];
   low = -4; 
   up = 68; 
   f = low;
    /*while (f <= up) {
       cels = 5 * (f-32) / 9;
       printf ("%d\t%d\n", f, cels);
       f = f + step;
   }*/

   int i = 1;
   while (f <= up) 
   {
       cels = 5 * (f-32) / 9;
       arr[i-1]=f;
       arr[i]=cels;
       printf("%d\t%d\n",arr[i-1],arr[i]);
       i+=2;
       f+=1;
   }



    return 0;
}

