#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 100
#define MAXAUTL 150
#define MAXBKS 15

char *s_gets(char *str, int size);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float price;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Не удалось открыть файл book.dat\n",
              stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count],
                                   size, 1, pbooks) != 0)
    {
        if (count == 0)
        {
            puts("Текущее содержимое файла book.dat:");
        }
        printf("\"%s\": %s ($%.2f)\n", library[count].title,
               library[count].author, library[count].price);
        count++;
    }

    filecount = count;
    if (count == MAXBKS)
    {
        fputs("Файл book.dat заполнен.", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Введите названия книг.");
    puts("Нажмите [enter] в начале строки чтобы выйти:");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Введите имя автора:");
        s_gets(library[count].author, MAXAUTL);
        puts("Введите цену книги:");
        scanf("%f", &library[count++].price);
        while (getchar() != '\n')
        {
        }

        if (count < MAXBKS)
        {
            puts("Введите название следующей книги:");
        }
        else
        {
            puts("Файл заполнен.");
        }
    }
    if (count > 0)
    {
        puts("Каталог ваших книг:");
        for (index = 0; index < count; index++)
        {
            printf("\"%s\": %s ($%.2f)\n", library[index].title,
                   library[index].author, library[index].price);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
    {
        puts("В вашем каталоге нет ни одной книги(\n");
    }

    puts("Программа завершена.");
    fclose(pbooks);

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
    return ret_val;
}