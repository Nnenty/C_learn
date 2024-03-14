#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    blue,
    dark_blue,
    violet
};
char *s_gets(char *str, int size);
const char *colors[] = {"red", "orange", "yellow", "green",
                        "blue", "dark blue", "violet"};

#define LEN 50

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool find_color = false;

    puts("Введите цвет([enter] в начале строки для выхода):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                find_color = true;
                break;
            }
        }
        if (find_color)
        {
            switch (color)
            {
            case red:
                puts("Люблю красные розы.");
                break;
            case orange:
                puts("Оранжевые маки очень необычные!");
                break;
            case green:
                puts("Яркое солнце светит на зеленую траву.");
                break;
            case yellow:
                puts("Желтые подсолнухи так похожи на солнце!");
                break;
            case blue:
                puts("Голубые колокольчики выглядят необычно.");
                break;
            case dark_blue:
                puts("Синий ирис выглядит очень красиво.");
                break;
            case violet:
                puts("Фиолетовые фиалки выглядят экзотично.");
                break;
            }
        }
        else
        {
            printf("Цвет \"%s\" не известен.\n", choice);
        }
        find_color = false;
        puts("Введите следующий цвет([enter] в начале строки для выхода):");
    }
    puts("Программа завершена.");

    return 0;
}
char *s_gets(char *str, int size)
{
    char *ret_val, *find;

    ret_val = fgets(str, size, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
            }
        }
    }
    return ret_val;
}