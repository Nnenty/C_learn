#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 50

struct film
{
    char title[TSIZE];
    int rating;

    struct film *next;
};

char *s_gets(char *str, int size);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    puts("Entr the name of the first film:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));

        if (head == NULL)
        {
            head = current;
        }
        else
        {
            prev->next = current;
        }
        current->next = NULL;

        strcpy(current->title, input);

        puts("Enter the rating of film(1-10):");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
        {
        }

        puts("Enter the name of the next film:");
        prev = current;
    }

    if (head == NULL)
    {
        puts("Data not entered.");
    }
    else
    {
        puts("List of films:");
    }

    current = head;
    while (current != NULL)
    {
        printf("Film: %s; Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }

    current = head;
    while (current != NULL)
    {
        current = current->next;

        free(current);
    }

    puts("\nEnd of the programm.");

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