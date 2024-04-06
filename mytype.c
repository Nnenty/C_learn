#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
    int: "int",                 \
    float: "float",             \
    double: "double",           \
    long: "long",               \
    default: "other")

int main(void)
{
    int d = 0;

    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE((double)d));
    printf("%s\n", MYTYPE((long)d));
    printf("%s\n", MYTYPE((short)d));

    return 0;
}