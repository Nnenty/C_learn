#include <stdio.h>

int units = 0;

void critic(void);

int main(void)
{
    extern int units;

    puts("Сколько фунтов весит маленький бочонок масла?");
    scanf("%d", &units);

    while (units != 56)
    {
        if (units + 1 == 56 || units - 1 == 56)
        {
            puts("Близко, но неверно!");
        }
        critic();
    }
    puts("Харош!");

    return 0;
}
void critic(void)
{
    puts("Неверно, попробуй еще раз:");
    scanf("%d", &units);
}