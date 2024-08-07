#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))

typedef struct polar_v
{
    double magnitude;
    double angle;
} Polar_V;
typedef struct rect_v
{
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main(void)
{
    Rect_V input;
    Polar_V result;

    puts("Введите координаты x и y; q для завершения:");

    while (scanf("%lf %lf", &input.x, &input.y) == 2)
    {
        while (getchar() != '\n')
        {
        }
        result = rect_to_polar(input);
        printf("Модуль = %0.2f, угол = %0.2f\n",
               result.magnitude, result.angle);
    }

    puts("Программа завершена.");

    return 0;
}
Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V pv;

    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);

    if (pv.magnitude == 0)
    {
        pv.angle = 0.0;
    }
    else
    {
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
    }

    return pv;
}