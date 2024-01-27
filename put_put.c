#include <stdio.h>

void put1(const char *);
int put2(const char *);

int main(void)
{
    put1("Если бы у меня было столько денег,");
    put1(" сколько я мог бы потратить,\n");
    printf("Получилось %d символов.\n",
           put2("то я бы никогда не заботился о починке сломанных вещей.\n\n"));

    return 0;
}
void put1(const char *strg)
{
    while (*strg)
    {
        putchar((*strg++));
    }
}
int put2(const char *strg)
{
    int count = 0;

    while (*strg)
    {
        putchar(*strg++);
        count++;
    }

    return count;
}