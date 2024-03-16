#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char *s_gets(char *str, int size);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char *str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfunc)(char *);

    puts("Введите строку([enter] в начале строки для выхода из программы):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice)
            {
            case 'a':
                pfunc = ToLower;
                break;
            case 'b':
                pfunc = ToUpper;
                break;
            case 'c':
                pfunc = Transpose;
                break;
            case 'd':
                pfunc = Dummy;
                break;
            }
            strcpy(copy, line);
            show(pfunc, copy);
        }
        puts("Введите строку снова([enter] в начале строки для выхода):");
    }
    puts("Программа завершена.");

    return 0;
}
char showmenu(void)
{
    char ans;

    puts("Введите выбранный вариант из меню:");
    puts("a. Строку в нижний регистр     b. Строку в верхний регистр");
    puts("c. Поменять регистры местами   d. Исходный регистр");
    puts("n. Следующая строка");

    ans = getchar();
    ans = tolower(ans);
    eatline();

    while (strchr("abcdn", ans) == NULL)
    {
        puts("Введите a, b, c, d или n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}
void eatline(void)
{
    while (getchar() != '\n')
    {
    }
}
void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
void Transpose(char *str)
{
    while (*str)
    {
        if (islower(*str))
        {
            *str = toupper(*str);
        }
        else if (isupper(*str))
        {
            *str = tolower(*str);
        }
        str++;
    }
}
void Dummy(char *str)
{
    // unchanged string
}
void show(void (*fp)(char *), char *str)
{
    (*fp)(str);
    puts(str);
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