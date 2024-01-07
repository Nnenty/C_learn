#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
void main()
{
    int choice;
    void count(void);
    while ((choice = get_choice()) != 'd')
    {
        switch (choice)
        {
        case 'a':
            printf("Никогда не качай Dota 2!\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            count();
            break;
        default:
            printf("Ошибка!\n");
            break;
        }
    }
    printf("Программа завершена.\n");
    return 0;
}
void count(void)
{
    int n, i;
    printf("До какого предела вести подсчет? "
           "Введите целое число:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    while (getchar() != '\n')
    {
        continue;
    }
}
char get_choice(void)
{
    int ch;
    printf("Введите букву, соответствующую выбранному варианту:\n");
    printf("a. совет         b. звонок\n"
           "c. подсчет       d. выход\n");
    ch = get_first();
    while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd')
    {
        printf("Выберите a, b, c или d\n");
        ch = get_first();
    }
    return ch;
}
char get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
    {
        continue;
    }
    return ch;
}
int get_int(void)
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" не является целочисленным.\nВведите "
               "целое число, такое как 25, 190 или 3: ");
    }
    return input;
}
