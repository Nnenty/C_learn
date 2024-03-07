#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char *s_gets(char *str, int size);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}
void getinfo(struct namect *pst)
{
    puts("Введите свое имя:");
    s_gets(pst->fname, NLEN);
    puts("Введите свою фамилию:");
    s_gets(pst->lname, NLEN);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) +
                   strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, ваше имя и фамилия содержат %d символов.\n",
           pst->fname, pst->lname, pst->letters);
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