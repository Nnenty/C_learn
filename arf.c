#include <stdio.h>
#define SIZE 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
int main(void)
{
    double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("Исходный массив dip:\n");
    show_array(dip, SIZE);
    mult_array(dip, SIZE, 2.5);
    printf("Массив dip после  вызова функции mult_array():\n");
    show_array(dip, SIZE);

    return 0;
}
void show_array(const double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%2.3f ", ar[i]);
    }
    putchar('\n');
}
void mult_array(double ar[], int n, double mult)
{
    int i;

    for (i = 0; i < n; i++)
    {
        ar[i] *= mult;
    }
}