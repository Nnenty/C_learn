#include <stdio.h>
#include <string.h>

#define SIZE 80
#define LIM 10
#define STOP "quit"

char *quit(char *str);
char *s_gets(char *str, int size);

int main(void)
{
    char input[LIM][SIZE];
    int ct = 0;

    printf("Введите до %d строк (или quit дла завершения):\n", LIM);
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           strcmp(input[ct], STOP))
    {
        ct++;
    }
    printf("Введено %d строк(и).\n", ct);

    return 0;
}
char *s_gets(char *str, int size)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(str, size, stdin);
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