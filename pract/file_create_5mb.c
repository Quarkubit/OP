#include <stdio.h>
#include <stdlib.h>



int main()
{
    int Size = 5 * 1024 * 1024 - 1;
    FILE *fp = fopen("5mb_file", "w");
    fseek(fp, Size , SEEK_SET);
    fputc('\0', fp);
    fclose(fp);

    system("pause");
    return 0;
}