#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *ptd;
    int max = 0;
    int number;
    int i = 0;

    puts("Введите максимальное количество элементов типа double.");
    if (scanf("%d", &max) != 1)
    {
        puts("Количество введено некорректно -- программа завершена.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *)malloc(max * sizeof(double));

    if (ptd == NULL)
    {
        puts("Не удалось выделить память -- программа завершена");
        exit(EXIT_FAILURE);
    }

    puts("Введите значения (q для выхода):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
    {
        i++;
    }
    printf("Введено %d элементов.\n", number = i);

    for (i = 0; i < number; i++)
    {
        printf("%7.2f ", ptd[i]);
        if (i % 7 == 6)
        {
            putchar('\n');
        }
    }
    putchar('\n');

    puts("Программа завершена.");
    free(ptd);

    return 0;
}