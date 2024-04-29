#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x);
ITEM customertime(long when);

int main(void)
{
    QUEUE line;
    ITEM temp;
    int hours;
    int wait_time = 0;

    int perhour;
    double min_per_cust;

    long cycle, cyclelimit;

    long customers = 0;
    long served = 0;
    long turnaways = 0;

    long sum_line = 0;
    long line_wait = 0;

    InitializeQueue(&line);
    srand((unsigned int)time(0));

    puts("Siegmund consultation kiosk");
    puts("Enter the duration of the simulation in hours:");
    scanf("%d", &hours);
    while (getchar() != '\n')
    {
    }
    cyclelimit = MIN_PER_HR * hours;

    puts("Enter average number of clients per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);

            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;

            served++;
        }
        if (wait_time > 0)
        {
            wait_time--;
        }

        sum_line += QueueItemCount(&line);
    }

    if (customers > 0)
    {
        printf("Accepted clients: %ld\n", customers);
        printf("Serviced clients: %ld\n", served);
        printf("Clients refusals: %ld\n", turnaways);
        printf("Average queue length: %.2f\n",
               (double)sum_line / cyclelimit);
        printf("Average waiting time: %.2f minuts\n",
               (double)line_wait / served);
    }
    else
    {
        puts("No clients :(");
    }

    EmptyTheQueue(&line);

    puts("Programm completed");

    return 0;
}
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ITEM customertime(long when)
{
    ITEM cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}