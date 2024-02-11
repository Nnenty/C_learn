#include <stdio.h>

void trystat(void);

void main()
{
    int count;

    for (count = 1; count <= 3; count++)
    {
        printf("Начало итерации %d:\n", count);
        trystat();
    }
}
void trystat(void)
{
    int fade = 1;
    static int stay = 1;

    printf("fade = %d, stay = %d\n", fade++, stay++);
}