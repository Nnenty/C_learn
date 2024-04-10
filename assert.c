#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
    double x, y, z;

    puts("Введите 2 числа(0 0 для завершения)");
    while (scanf("%lf%lf", &x, &y) == 2 &&
           (x != 0 || y != 0))
    {
        z = x * x - y * y;
        assert(z >= 0);
        printf("Результатом является %f.2\n", sqrt(z));
        puts("Введите следующие 2 числа:");
    }
    puts("Программа завершена");

    return 0;
}