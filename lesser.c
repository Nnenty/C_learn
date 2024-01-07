#include <stdio.h>
int imin(int, int);
int main(void)
{
    int evil, evil2;
    printf("Введите два целых числа (q для завершения):\n");
    while (scanf("%d %d", &evil, &evil2) == 2)
    {
        printf("Меньшим из %d и %d является %d.\n",
               evil, evil2, imin(evil, evil2));
        printf("Введите два целых числа (q дла звершения):\n");
    }
    printf("Программа завершена.\n");
}
int imin(int num1, int num2)
{
    int min;
    if (num1 < num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}