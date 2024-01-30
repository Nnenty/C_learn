#include <stdio.h>
#include <string.h>

#define SIZE 40
#define LIM 5

char *s_gets(char *str, int size);

int main(void)
{
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Введите %d слов, которые начинаются с буквы к:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'k')
        {
            printf("%s не начинается с буквы к. Повторите ввод:\n", temp);
        }
        else
        {
            strcpy(qwords[i], temp);
            i++;
        }
    }
    puts("Список принятых слов:");
    for (i = 0; i < LIM; i++)
    {
        puts(qwords[i]);
    }

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