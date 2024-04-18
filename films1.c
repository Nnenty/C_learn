#include <stdio.h>
#include <string.h>

#define TSIZE 45
#define FMAX 5

struct film
{
    char title[TSIZE];
    int rating;
};

char *s_gets(char *str, int size);

int main(void)
{
    struct film movies[FMAX];
    int i = 0;
    int j;

    puts("Введите название первого фильма:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
           movies[i].title[0] != '\0')
    {
        puts("Введите значение рейтинга (0-10):");

        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n')
        {
        }

        puts("Введите название следующего фильма(или пустую строку для выхода):");
    }
    if (i == 0)
    {
        puts("Вы не ввели ни одного фильма; список пуст.");
    }
    else
    {
        puts("Список фильмов:\n");

        for (j = 0; j < i; j++)
        {
            printf("Фильм: %s; Рейтинг: %d\n", movies[j].title,
                   movies[j].rating);
        }
    }
    puts("\nПрограмма завершена.");

    return 0;
}
char *s_gets(char *str, int size)
{
    char *find, *ret_val;
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