#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

void main()
{
    int n;
    atexit(sign_off);

    puts("Введите целое число:");
    if (scanf("%d", &n) != 1)
    {
        puts("Это не целое число!");

        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d является %s.\n", n, (n % 2 == 0) ? "четным" : "нечётным");
}
void sign_off(void)
{
    puts("\nЗавершение очередной замечательной программы от меня!");
}
void too_bad(void)
{
    puts("Я приношу искринние соболезнования");
    puts("в связи с отказом работы программы.");
}