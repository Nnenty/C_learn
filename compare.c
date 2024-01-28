#include <stdio.h>
#include <string.h>

#define ANSWER "Грант"
#define SIZE 40

char *s_gets(char *str, int size);

int main(void)
{
    char try[SIZE];

    puts("Кто съел деда?(ответ с большой буквы)");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER) != 0)
    {
        puts("Неправильно! Попробуйте еще раз.");
        s_gets(try, SIZE);
    }
    puts("Теперь правильно!");

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