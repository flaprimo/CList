#ifndef LIST_H
#define LIST_H

typedef struct list_t {
    void *info; // pointer to the information that the list node holds

    struct list_t *next; // pointer to the list successor
} List;

// add a list node as the first element of the list
void list_addFirst(List **l, void *info);

// add a list node as the last element of the list
void list_addLast(List **l, void *info);

// get a l->info given the position in the list
void *list_get(List *l, int index);

// remove a list node given the position in the list and a function that correctly frees the l->info pointer
void list_remove(List **l, int index, void (*freeInfo)(void *));

// remove every list node given the position in the list and a function that correctly frees the l->info pointer
void list_removeAll(List **l, void (*freeInfo)(void *));

// returns the max of a list
void *list_max(List *l, void *(*comparator)(void *, void *));

#endif //LIST_H