#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(ITEM item, NODE *pn);
static void CopyToItem(NODE *pn, ITEM *pi);

void InitializeQueue(QUEUE *pq)
{
    pq->front = pq->rear = NULL;

    pq->items = 0;
}
bool QueueIsFull(const QUEUE *pq)
{
    return pq->items == MAXQUEUE;
}
bool QueueIsEmpty(const QUEUE *pq)
{
    return pq->items == 0;
}
int QueueItemCount(const QUEUE *pq)
{
    return pq->items;
}
bool EnQueue(ITEM item, QUEUE *pq)
{
    NODE *pnew;

    if (QueueIsFull(pq))
    {
        return false;
    }

    pnew = (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (QueueIsEmpty(pq))
    {
        pq->front = pnew;
    }
    else
    {
        pq->rear->next = pnew;
    }

    pq->rear = pnew;
    pq->items++;

    return true;
}
bool DeQueue(ITEM *pitem, QUEUE *pq)
{
    NODE *pt;

    if (QueueIsEmpty(pq))
    {
        return false;
    }

    CopyToItem(pq->front, pitem);

    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;

    if (pq->items == 0)
    {
        pq->rear = NULL;
    }

    return true;
}
void EmptyTheQueue(QUEUE *pq)
{
    ITEM dummy;

    while (!QueueIsEmpty(pq))
    {
        DeQueue(&dummy, pq);
    }
}
static void CopyToNode(ITEM item, NODE *pn)
{
    pn->item = item;
}
static void CopyToItem(NODE *pn, ITEM *pi)
{
    *pi = pn->item;
}