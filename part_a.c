#include <stdio.h>

void report_count();
void accumulate(int num);

int count = 0;

int main(void)
{
    int value;
    register int i;

    puts("Введите положительное целое число(0 для завершения):");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count;
        for (i = value; i >= 0; i--)
        {
            accumulate(i);
        }
        puts("Введите еще одно положительное целое число(0 для завершения):");
    }
    report_count();

    return 0;
}
void report_count()
{
    printf("Цикл выполнен %d раз.\n", count);
}