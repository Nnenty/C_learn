#include <stdio.h>
#include "names_st.h"

void get_names(names *pn)
{
    printf("Введите свое имя: ");
    s_gets(pn->first, SLEN);
    printf("Введите свою  фамилию: ");
    s_gets(pn->last, SLEN);
}
void show_names(const names *pn)
{
    printf("%s %s", pn->first, pn->last);
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
}