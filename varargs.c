#include <stdio.h>
#include <stdarg.h>

double sum(int, ...);

int main(void)
{
    double s, t;

    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);

    printf("Возвращаемое значение "
           "sum(3, 1.1, 2.5, 13.3):%5g\n",
           s);
    printf("Возвращаемое значение "
           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1):%5g\n",
           t);

    return 0;
}
double sum(int lim, ...)
{
    va_list ap;
    double tot = 0;
    int i;

    va_start(ap, lim);
    for (i = 0; i < lim; i++)
    {
        tot += va_arg(ap, double);
    }
    va_end(ap);

    return tot;
}