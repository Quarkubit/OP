#include <stdio.h>
#include <stdlib.h>



int main()
{
    char c;
    char *s="";
    
    FILE *f;
    f = fopen("Data.txt", "r"); //открываем файл для чтения
    
    int i = -1;//устанавливаем указатель в предпоследнюю позицию
    while (fseek(f, i, SEEK_END) != -1)//пока положение указателя корректно
    {
        c = fgetc(f);//читаем посимвольно
        s += c;//формируем строку
        i--;//смещаемся к началу
    }
    
    fclose(f);
    printf("%c",s);

    system("pause");
    return 0;
}