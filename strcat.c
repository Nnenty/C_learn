#include <stdio.h>
#include <string.h>

#define SIZE 80

char *s_gets(char *str, int val);

int main(void)
{
    char flower[SIZE];
    char addon[] = " пахнет как старые валенки.";

    puts("Какой у вас любимый цветок?");
    if (s_gets(flower, SIZE))
    {
        strcat(flower, addon);

        puts(flower);
        puts(addon);
    }
    else
    {
        puts("Обнаружен конец файла.\n");
    }

    puts("Программа завершена.\n");

    return 0;
}
char *s_gets(char *str, int val)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(str, val, stdin);

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
            while (getchar != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}