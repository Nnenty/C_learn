#include <stdio.h>
#include <stdlib.h>

#define LIM 30

char *s_gets(char *str, int size);

int main(void)
{
    char number[LIM];
    char *end;
    long value;

    puts("Введите число(или пустую строку для выхода из программы):");
    while (s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10);

        printf("десятичный ввод, вывод: %ld, прекращен на %s (%d)\n",
               value, end, *end);
        value = strtol(number, &end, 16);
        printf("шестнадцатеричный ввод, вывод: %ld, прекращен на %s (%d)\n",
               value, end, *end);
        puts("Следующее число:");
    }
    puts("Программа завершена");

    return 0;
}
char *s_gets(char *str, int size)
{
    char *ret_val;

    ret_val = fgets(str, size, stdin);

    int i = 0;
    if (ret_val)
    {
        while (str[i] != '\0' && str[i] != '\n')
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

        return ret_val;
    }
}