#include <stdio.h>
void up_and_down(int);

int main(void)
{
    up_and_down(1);
    return 0;
}
void up_and_down(int n)
{
    printf("Уровень %d: ячейка n %p\n", n, &n);
    if (n < 6)
    {
        up_and_down(n + 1);
    }
    printf("УрОвЕнЬ %d: ячейка n %p\n", n, &n);
}