#include <stdio.h>

static unsigned long int next = 1;

int rand0(void)
{
    next = next * 1103515245 + 12345;

    return (unsigned int)(next / 65536) % 32768;
}
int main(void)
{
    int num = rand0();
    printf("%d, %d", num, rand0());

    return 0;
}