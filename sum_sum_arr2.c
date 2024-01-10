#include <stdio.h>
#define SIZE 10

int sump(int *start, int *end);
int main(void)
{
    int marbles[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 10};
    long answer;

    answer = sump(marbles, marbles + SIZE);
    printf("Общаая сумма элементов массива marbles равна %ld.\n",
           answer);

    return 0;
}
int sump(int *start, int *end)
{
    int total = 0;

    while (start < end)
    {
        total += *start;
        start++;
    }
    return total;
}