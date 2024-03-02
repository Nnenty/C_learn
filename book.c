#include <stdio.h>
#include <string.h>

char *s_gets(char *str, int size);

#define MAXTITL 41
#define MAXAUTL 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library;

    puts("Введите название книги:");
    s_gets(library.title, MAXTITL);

    puts("Введите ФИО автора:");
    s_gets(library.author, MAXAUTL);

    puts("Введите цену книги:");
    scanf("%f", &library.value);

    printf("%s: \"%s\", ($%.2f)\n" library.author,
           library.title, library.value);

    return 0;
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
}