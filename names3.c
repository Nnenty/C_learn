#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 81

struct namect
{
    char *fname;
    char *lname;
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);
char *s_gets(char *str, int size);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}
void getinfo(struct namect *pst)
{
    char temp[SLEN];

    puts("Введите свое имя:");
    s_gets(temp, SLEN);
    pst->fname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);

    puts("Введите свою фамилию:");
    s_gets(temp, SLEN);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s %s, ваше имя содержат %d букв.\n",
           pst->fname, pst->lname, pst->letters);
}
void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
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