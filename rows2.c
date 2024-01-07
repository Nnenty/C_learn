#include <stdio.h>
void main()
{
    const int rows = 10;
    const int chars = 10;
    int row;
    int ch;

    for (row = 0; row < rows; row++)
    {
        for (ch = ('A' + row); ch < ('A' + chars); ch++)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}