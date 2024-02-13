#include <stdio.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    unsigned seed;

    puts("Введите желаемое начальное число:");
    while (scanf("%u", &seed) == 1)
    {
        srand1(seed);
        for (int count = 0; count < 5; count++)
        {
            printf("%d\n", rand1());
        }
        puts("Введите следующее начальное число(q для завершения):");
    }

    return 0;
}