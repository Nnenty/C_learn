#include <stdio.h>
#include <string.h>

char *s_gets(char *str, int size);

#define MAXTITL 40
#define MAXAUTL 100
#define MAXBKS 100

struct books
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float price;
};

int main(void)
{
    struct books library[MAXBKS];
    int count = 0;
    int index;

    puts("Введите название книги:");
    puts("Чтобы выйти из программы, нажмите [enter] в начале строки.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Введите ФИО автора:");
        s_gets(library[count].author, MAXAUTL);

        puts("Теперь введите цену книги:");
        scanf("%f", &library[count++].price);

        while (getchar() != '\n')
        {
        }
        if (count < MAXBKS)
        {
            puts("Введите название следующей книги.");
        }
    }
    if (count > 0)
    {
        puts("Каталог ваших книг:");
        for (index = 0; index < count; index++)
        {
            printf("\"%s\" авторства %s: %.2f\n", library[index].title,
                   library[index].author, library[index].price);
        }
    }
    else
    {
        puts("Книги полезны.");
    }
}
char *s_gets(char *str, int size)
{
    char *ret_val;
    char *find;

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