#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 40

void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(void)
{
    double vals[SIZE];
    fillarray(vals, SIZE);

    puts("Список случайных чисел:");
    showarray(vals, SIZE);

    qsort(vals, SIZE, sizeof(double), mycomp);
    puts("\nОтсортированный список:");
    showarray(vals, SIZE);

    return 0;
}
void fillarray(double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        ar[i] = (double)rand() / ((double)rand() + 0.1);
    }
}
void showarray(const double ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%9.4f ", ar[i]);
        if (i % 6 == 5)
        {
            putchar('\n');
        }
    }
    if (i % 6 != 0)
    {
        putchar('\n');
    }
}
int mycomp(const void *p1, const void *p2)
{
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if (*a1 < *a2)
    {
        return -1;
    }
    else if (*a1 == *a2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}