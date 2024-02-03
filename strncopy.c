#include <stdio.h>
#include <string.h>

#define SIZE 40
#define LIM 5
#define TARGSIZE 10

char *s_gets(char *str, int size);
int main(void)
{
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];

    printf("Введите %d слов, которые начинаются с буквы \"к\":\n", LIM);
    int i = 0;
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (strncmp(temp, "k", 1) != 0)
        {
            printf("\"%s\" не начинается с буквы \"к\".\n", temp);
        }
        else
        {
            strncpy(qwords[i], temp, TARGSIZE - 1);
            qwords[i][TARGSIZE - 1] = '\0';
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
    int i;

    ret_val = fgets(str, size, stdin);
    i = 0;

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