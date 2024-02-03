#include <stdio.h>

#define MAX 10

char *s_gets(char *str, int size);
int main(void)
{
    char first[MAX];
    char last[MAX];
    char formal[2 * MAX + 10];
    double prize;

    puts("Введите свое имя:");
    s_gets(first, MAX);
    puts("Введите фамилию:");
    s_gets(last, MAX);
    puts("Введите сумму денежного приза:");
    scanf("%lf", &prize);

    sprintf(formal, "%s %-19s: $%6.2lf\n", last, first, prize);
    puts(formal);

    return 0;
}
char *s_gets(char *str, int size)
{
    char *ret_val;

    ret_val = fgets(str, size, stdin);

    int i = 0;
    if (ret_val)
    {
        while (str[i] != '\n' && str[i] != '\0')
        {
            i++;
        }
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}