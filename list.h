#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 50        // size of the film title

struct film
{
    char title[TSIZE];  // title of the film
    int rating;         // rate of the film
};

// type definitions 

typedef struct film ITEM;

typedef struct node
{
    ITEM item;
    struct node *next;
} NODE;

typedef NODE *LIST;

// functions prototypes

// operation: initialize list
// preconditions: plist is pointer at the LIST
// postconditions:  list initializated with empty content
void Initializelist(LIST *plist);

// operation: determining whether a list is empty
// preconditions: plist is pointer at the initializated list
// postconditions: the function is returning True, if list
//empty, and false if list full
bool ListIsEmpty(const LIST *plist);

// operation: determining whether a list is full
// preconditions: plist is pointer at the initializated list
// postconditions: the function is returns True, if list
//full, and false if list empty
bool ListIsFull(const LIST *plist);

// operation: determining the number of elements in a list
// preconditions: plist is pointer at the initializated list
// postconditions: function is returning the number
//of elements in a list
unsigned int ListItemCount(const LIST *plist);

// operation: adds an element to the end of the list
// preconditions: item is the element to be added to the list
// postconditions: if it impossible, function adds element to the
//end of the list and returns True, False otherwise
bool AddItem(ITEM item, LIST *plist);

// operation: applying a function to each element of a list
// preconditions: 1.plist is pointer at the initializated list
//                 2.pfun points to a function that takes
//an ITEM argument and returns nothing
// postconditions: pfun function executes on each element in the list
void Traverse(const LIST *plist, void (*pfun)(ITEM item));

// operation: free memory
// preconditions: plist is pointer at the initializated list
// postconditions: any memory allocated for the list is freed
void EmptyTheList(LIST *plist);

#endif