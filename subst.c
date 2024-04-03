#include <stdio.h>

#define PSQR(x) printf("Квадрат " #x " равен %d.\n", ((x) * (x)))

int main(void)
{
    int y = 5;

    PSQR(y);
    PSQR(2 + 4);
    PSQR(88);

    return 0;
}