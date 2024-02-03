#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 20

void ststr(char *stings[], int num);
char *s_gets(char *str, int size);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];

    printf("Введите до %d строк, и они будут отсортированы в алфавитном порядке.\n", LIM);
    puts("Чтобы остановить ввод, нажмите \"Enter\" в начале строки:");
    int ct = 0;
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    ststr(ptstr, ct);

    puts("\nОтсортированный список строк:");
    int i = 0;
    while (i < ct)
    {
        puts(ptstr[i]);
        i++;
    }

    return 0;
}
void ststr(char *strings[], int num)
{
    char *temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
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
    }

    return ret_val;
}