#include <stdio.h>
void interchange(int *u, int *v);

int main(void)
{
    int x = 5, y = 10;

    printf("Первоначально x = %d, y = %d\n", x, y);
    interchange(&x, &y);
    printf("Теперь x = %d, y = %d\n", x, y);
}
void interchange(int *u, int *v)
{
    int temp;

    temp = *u;
    *u = *v;
    *v = temp;
}