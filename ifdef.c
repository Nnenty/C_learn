#include <stdio.h>

#define CHECKING
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i * i + 1;

#ifdef CHECKING
        printf("i = %d, промежуточная сумма = %d\n", i, total);
#endif
    }
    printf("Итоговая сумма = %d\n", total);

    return 0;
}