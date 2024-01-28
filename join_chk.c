#include <stdio.h>
#include <string.h>

#define SIZE 60
#define BUGSIZE 20

char *s_gets(char *str, int size);

int main(void)
{
    char flower[SIZE];
    char addon[] = " пахнет как старые валенки";
    char bug[BUGSIZE];

    int aviable;

    puts("Какой у вас любимый цветок?");
    s_gets(flower, SIZE);

    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
    {
        strcat(flower, addon);
    }
    puts(flower);

    puts("Какое у вас любимое насекомое?");
    s_gets(bug, BUGSIZE);
    aviable = BUGSIZE - strlen(bug) - 1;

    strncat(bug, addon, aviable);
    puts(bug);

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