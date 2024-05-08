#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define SLEN 32

char menu(void);

void addpet(TREE *pt);
void droppet(TREE *pt);
void showpets(const TREE *pt);
void findpet(const TREE *pt);
void printitem(ITEM item);
void uppercase(char *str);

char *s_gets(char *str, int size);

int main(void)
{
    TREE pets;
    char choice;

    initialize_tree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            addpet(&pets);
            break;
        case 's':
            showpets(&pets);
            break;
        case 'f':
            findpet(&pets);
            break;
        case 'n':
            printf("%d pets in club\n", tree_item_count(&pets));
            break;
        case 'd':
            droppet(&pets);
            break;
        default:
            puts("Error in switch");
        }
    }
    delete_all(&pets);
    puts("Program completed");

    return 0;
}
char menu(void)
{
    int ch;

    puts("Nerfville Pet Club");
    puts("Enter the letter corresponding your choice:");
    puts("a - add pets; s - show pets");
    puts("f - find pet in the list; n - number of pets");
    puts("d - delete the pet; q - exit");

    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
        {
        }

        ch = tolower(ch);
        if (strchr("asfndq", ch) == NULL)
        {
            puts("Please enter the a, s, f, n, d or q:");
        }
        else
        {
            break;
        }
    }
    if (ch == EOF)
    {
        ch = 'q';
    }

    return ch;
}
void addpet(TREE *pt)
{
    ITEM temp;

    if (tree_is_full(pt))
    {
        puts("No more places on the club");
    }
    else
    {
        puts("Enter name of the pet:");
        s_gets(temp.petname, SLEN);
        puts("Enter the kind of the pet:");
        s_gets(temp.petkind, SLEN);

        uppercase(temp.petname);
        uppercase(temp.petkind);

        add_item(&temp, pt);
    }
}
void showpets(const TREE *pt)
{
    if (tree_is_empty(pt))
    {
        puts("No pets in club");
    }
    else
    {
        traverse(pt, printitem);
    }
}
void printitem(ITEM item)
{
    printf("Pet: %-19s | Kind: %-19s\n", item.petname,
           item.petkind);
}
void findpet(const TREE *pt)
{
    ITEM temp;

    if (tree_is_empty(pt))
    {
        puts("No pets in club");
        return;
    }
    puts("Enter the name of pet you want to find:");
    s_gets(temp.petname, SLEN);

    puts("Enter the kind of pet:");
    s_gets(temp.petkind, SLEN);

    uppercase(temp.petkind);
    uppercase(temp.petname);

    printf("%s named %s ", temp.petkind, temp.petname);
    if (in_tree(&temp, pt))
    {
        puts("in club");
    }
    else
    {
        puts("not in club");
    }
}
void droppet(TREE *pt)
{
    ITEM temp;

    if (tree_is_empty(pt))
    {
        puts("No pets in club");
        return;
    }
    puts("Enter the name of pet you want to delete:");
    s_gets(temp.petname, SLEN);

    puts("Enter the kind of pet:");
    s_gets(temp.petkind, SLEN);

    uppercase(temp.petkind);
    uppercase(temp.petname);

    printf("%s named %s ", temp.petkind, temp.petname);
    if (delete_item(&temp, pt))
    {
        puts("is deleted from the club");
    }
    else
    {
        puts("not in club");
    }
}
void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
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