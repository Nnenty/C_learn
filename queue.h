#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#define MAXQUEUE 10

typedef int ITEM;
typedef struct node
{
    ITEM item;

    struct node *next;
} NODE;
typedef struct queue
{
    NODE *front;
    NODE *rear;

    int items;
} QUEUE;

void InitializeQueue(QUEUE *pq);

bool QueueIsFull(const QUEUE *pq);
bool QueueIsEmpty(const QUEUE *pq);

int QueueItemCount(const QUEUE *pq);
bool EnQueue(ITEM item, QUEUE *pq);
bool DeQueue(ITEM *pitem, QUEUE *pq);
void EmptyTheQueue(QUEUE *pq);

#endif