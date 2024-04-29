#include <stdio.h>
#include "queue.h"

int main(void)
{
    QUEUE line;
    ITEM temp;
    char ch;

    InitializeQueue(&line);

    puts("Queue test. Enter:");
    puts("\"a\" to add value; \"d\" to delete value;");
    puts("\"q\" to quit from programm.");

    while ((ch = getchar()) != 'q')
    {
        while (getchar() != '\n')
        {
        }
        if (ch != 'a' && ch != 'd')
        {
            continue;
        }

        if (ch == 'a')
        {
            puts("Enter integer num to add:");

            scanf("%d", &temp);
            while (getchar() != '\n')
            {
            }

            if (!QueueIsFull(&line))
            {
                printf("Placing a %d to queue\n", temp);
                EnQueue(temp, &line);
            }
            else
            {
                puts("The queue is full!");
            }
        }
        else
        {
            if (QueueIsEmpty(&line))
            {
                puts("Queue is empty!");
            }
            else
            {
                DeQueue(&temp, &line);
                printf("Delete %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("\nEnter:");
        puts("\"a\" to add value; \"d\" to delete value;");
        puts("\"q\" to quit from programm.");
    }
    EmptyTheQueue(&line);
    puts("Programm completed");

    return 0;
}