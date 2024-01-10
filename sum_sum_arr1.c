#include <stdio.h>
#define SIZE 10
int sum(int *, int);
int main(void)
{
    int marbles[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    int answer;

    answer = sum(marbles, SIZE);
    printf("Общая сумма элементов массива marbles равна %d.\n", answer);
    printf("Объем памяти, отведенной под массив marbles, составляет %zd байтов.\n",
           sizeof marbles);

    return 0;
}
int sum(int *ar, int n)
{
    int i;
    int total = 0;
    for (i = 0; i < n; i++)
    {
        total += *(ar + i);
    }
    printf("Размер ar[] составляет %zd байтов.\n", sizeof ar);

    return total;
}