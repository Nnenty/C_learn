#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

typedef struct item
{
    char petname[20];
    char petkind[20];
} ITEM;

#define MAXITEMS 10

typedef struct trnode
{
    ITEM item;

    struct trnode *left;
    struct trnode *right;
} TRNODE;
typedef struct tree
{
    TRNODE *root;
    int size;
} TREE;

void initialize_tree(TREE *ptree);

bool tree_is_empty(const TREE *ptree);
bool tree_is_full(const TREE *ptree);
bool in_tree(const ITEM *pi, const TREE *ptree);
int tree_item_count(const TREE *ptree);

void traverse(const TREE *ptree, void (*pfun)(ITEM item));

bool add_item(const ITEM *pi, TREE *ptree);
void delete_all(TREE *ptree);
bool delete_item(const ITEM *pi, TREE *ptree);

#endif