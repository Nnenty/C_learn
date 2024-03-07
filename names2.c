#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char *str, int size);

int main(void)
{
    struct namect person;

    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

    return 0;
}
struct namect getinfo(void)
{
    struct namect temp;
    puts("Введите свое имя:");
    s_gets(temp.fname, NLEN);
    puts("Введите свою фамилию:");
    s_gets(temp.lname, NLEN);

    return temp;
}
struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);

    return info;
}
void showinfo(struct namect info)
{
    printf("%s %s, ваше имя и фамилия содержат %d символов.\n",
           info.fname, info.lname, info.letters);
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