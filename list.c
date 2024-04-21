#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(ITEM item, NODE *pnode);

void InitializeList(LIST *plist)
{
    *plist = NULL;
}
bool ListIsEmpty(const LIST *plist)
{
    if (*plist == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ListIsFull(const LIST *plist)
{
    NODE *pt;
    bool full;

    pt = (NODE *)malloc(sizeof(NODE));
    if (pt == NULL)
    {
        full = true;
    }
    else
    {
        full = false;
    }

    free(pt);

    return full;
}
unsigned int ListItemCount(const LIST *plist)
{
    unsigned int count = 0;
    NODE *pnode = *plist;

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}
bool AddItem(ITEM item, LIST *plist)
{
    NODE *pnew;
    NODE *scan = *plist;

    pnew = (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL)
    {
        return false;
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (scan == NULL)
    {
        *plist = pnew;
    }
    else
    {
        while (scan->next != NULL)
        {
            scan = scan->next;
        }
        scan->next = pnew;
    }

    return true;
}
void Traverse(const LIST *plist, void (*pfun)(ITEM item))
{
    NODE *pnode = *plist;

    while (pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}
void FreeTheList(LIST *plist)
{
    NODE *psave;

    while (*plist != NULL)
    {
        psave = (*plist)->next;

        free(*plist);

        *plist = psave;
    }
}
static void CopyToNode(ITEM item, NODE *pnode)
{
    pnode->item = item;
}