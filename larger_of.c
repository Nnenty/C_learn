#include <stdio.h>
void larger_of(int *x, int *y);

int main(void)
{
    int a, b;
    printf("Введите два значения:\n");
    scanf("%d %d", &a, &b);
    larger_of(&a, &b);
}
void larger_of(int *x, int *y)
{
    if (*x > *y)
    {
        *y = *x;
    }
    else
    {
        *x = *y;
    }
}