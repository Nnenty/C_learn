#include <stdio.h>
int main(void)
{
    printf("Тип int имеет размер %zd байта(ов).\n", sizeof(int));
    printf("Тип char имеет размер %zd байта(ов).\n", sizeof(char));
    printf("Тип long имеет размре %zd байта(ов).\n", sizeof(long));
    printf("Тип long long имеет размер %zd байт(ов).\n",
           sizeof(long long));
    printf("Тип double имеет размер %zd байт(ов).\n", sizeof(double));
    printf("Тип long double имеет размер %zd байт(ов).\n", sizeof(long double));

    return 0;
}