#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showmovies(ITEM item);
char *s_gets(char *str, int size);

int main(void)
{
    LIST movies;
    ITEM temp;

    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No free memory. Program completed.\n");
        exit(1);
    }

    puts("Enter the title of first film:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter the rating of film(0-10):");

        scanf("%d", &temp.rating);
        while (getchar() != '\n')
        {
        }

        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem with memory allocation\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is full.");
            break;
        }

        puts("Enter the title of the next film(enter empty string for exit):");
    }

    if (ListIsEmpty(&movies))
    {
        puts("The list is empty.");
    }
    else
    {
        puts("The list of films:");
        Traverse(&movies, showmovies);
    }

    printf("\nYou enter %d films.\n", ListItemCount(&movies));

    FreeTheList(&movies);

    puts("Program completed.");

    return 0;
}
void showmovies(ITEM item)
{
    printf("Film: %s ::: Rating: %d\n", item.title, item.rating);
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

    return ret_val;
}