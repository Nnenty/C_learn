#include <stdio.h>
#include <limits.h>

_Static_assert(CHAR_BIT == 16, "Error on char size");

int main(void)
{
    puts("Char занимает 16 битов");

    return 0;
}