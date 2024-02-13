#include <stdio.h>

extern int count;

static int total;

void accumulate(int num)
{
    static int subtotal = 0;

    if (num <= 0)
    {
        printf("Итерация цикла: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;
    }
    else
    {
        subtotal += num;
        total += num;
    }
}