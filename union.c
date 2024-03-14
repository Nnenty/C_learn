#include <stdio.h>

typedef enum
{
    NODE_STRING,
    NODE_INT
} node_type;

typedef union
{
    int int_value;
    char *str_value;
} node_data;

typedef struct
{
    node_type type;
    node_data data;
} node;

void print_mode(node var)
{
    if (var.type == NODE_STRING)
    {
        printf("String: %s\n", var.data.str_value);
    }
    else if (var.type == NODE_INT)
    {
        printf("Int: %d\n", var.data.int_value);
    }
}
int main(void)
{
    node var1;
    var1.type = NODE_INT;
    var1.data.int_value = 22;

    node var2;
    var2.type = NODE_STRING;
    var2.data.str_value = "The union is very interesting type!";

    print_mode(var1);
    print_mode(var2);

    return 0;
}