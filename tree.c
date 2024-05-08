#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

typedef struct pair
{
    TRNODE *parent;
    TRNODE *child;
} PAIR;

static TRNODE *make_node(const ITEM *pi);

static bool to_left(const ITEM *i1, const ITEM *i2);
static bool to_right(const ITEM *i1, const ITEM *i2);

static void add_node(TRNODE *new_node, TRNODE *root);
static void in_order(const TRNODE *root, void (*pfun)(ITEM item));
static PAIR seek_item(const ITEM *pi, const TREE *ptree);

static void delete_node(TRNODE **ptr);
static void delete_all_nodes(TRNODE *ptr);

void initialize_tree(TREE *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}
bool tree_is_empty(const TREE *ptree)
{
    if (ptree->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool tree_is_full(const TREE *ptree)
{
    if (ptree->size == MAXITEMS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int tree_item_count(const TREE *ptree)
{
    return ptree->size;
}
bool add_item(const ITEM *pi, TREE *ptree)
{
    TRNODE *new_node;

    if (tree_is_full(ptree))
    {
        fprintf(stderr, "The tree if full\n");
        return false;
    }
    if (seek_item(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attemp to add a duplicate element\n");
    }

    new_node = make_node(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Error creating node\n");
        return false;
    }

    if (ptree->root == NULL)
    {
        ptree->root = new_node;
    }
    else
    {
        add_node(new_node, ptree->root);
    }
    ptree->size++;

    return true;
}
bool in_tree(const ITEM *pi, const TREE *ptree)
{
    return ((seek_item(pi, ptree).child == NULL) ? false : true);
}
bool delete_item(const ITEM *pi, TREE *ptree)
{
    PAIR look;

    look = seek_item(pi, ptree);
    if (look.child == NULL)
    {
        fprintf(stderr, "Attemp to delete non-added element\n");
        return false;
    }

    if (look.parent == NULL)
    {
        delete_node(&ptree->root);
    }
    else if (look.parent->left == look.child)
    {
        delete_node(&look.parent->left);
    }
    else if (look.parent->right == look.child)
    {
        delete_node(&look.parent->right);
    }
    ptree->size--;

    return true;
}
void traverse(const TREE *ptree, void (*pfun)(ITEM item))
{
    if (ptree != NULL)
    {
        in_order(ptree->root, pfun);
    }
}
void delete_all(TREE *ptree)
{
    if (ptree != NULL)
    {
        delete_all_nodes(ptree->root);
    }

    ptree->root = NULL;
    ptree->size = 0;
}
static void in_order(const TRNODE *root, void (*pfun)(ITEM Item))
{
    if (root != NULL)
    {
        in_order(root->left, pfun);
        (*pfun)(root->item);
        in_order(root->right, pfun);
    }
}
static void delete_all_nodes(TRNODE *root)
{
    TRNODE *pright;

    if (root != NULL)
    {
        pright = root->right;

        delete_all_nodes(root->left);
        free(root);
        delete_all_nodes(root->right);
    }
}
static void add_node(TRNODE *new_node, TRNODE *root)
{
    if (to_left(&new_node->item, &root->item))
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            add_node(new_node, root->left);
        }
    }
    else if (to_right(&new_node->item, &root->item))
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            add_node(new_node, root->right);
        }
    }
    else
    {
        fprintf(stderr, "Node allocation error");
        exit(EXIT_FAILURE);
    }
}
static bool to_right(const ITEM *i1, const ITEM *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
    {
        return true;
    }
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
static bool to_left(const ITEM *i1, const ITEM *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
    {
        return true;
    }
    else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
static TRNODE *make_node(const ITEM *pi)
{
    TRNODE *new_node;

    new_node = (TRNODE *)malloc(sizeof(TRNODE));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}
static PAIR seek_item(const ITEM *pi, const TREE *ptree)
{
    PAIR look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
    {
        return look;
    }

    while (look.child != NULL)
    {
        if (to_left(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (to_right(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            break;
        }
    }

    return look;
}
static void delete_node(TRNODE **ptr)
{
    TRNODE *temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
        {
        }
        temp->right = (*ptr)->right;
        temp = *ptr;

        *ptr = (*ptr)->left;
        free(temp);
    }
}