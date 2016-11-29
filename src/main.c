#include <stdlib.h>
#include <stdio.h>
#include "helper/list.h"

/**
 * Frees a (void *) that is in reality an (int *)
 * @param integerVoidPointer
 */
void freeIntPointer(void *integerVoidPointer)
{
    if (integerVoidPointer != NULL)
        free((int *)integerVoidPointer);
}

void *intComparator(void *a, void *b)
{
    if (a != NULL && b != NULL) {
        if (*(int *)a >= *(int *)b)
            return a;
        else
            return b;
    } else
        return NULL;
}

int main()
{
    // declare the list
    List *l1;
    // list is now []

    // instantiate, initialize and add 1st element to the list
    int *i1 = malloc(sizeof(int));
    *i1 = 10;
    list_addFirst(&l1, i1);
    // list is now [10]

    // instantiate, initialize and add 2nd element to the list
    int *i2 = malloc(sizeof(int));
    *i2 = 11;
    list_addFirst(&l1, i2);
    // list is now [11, 10]

    // instantiate, initialize and add 3rd element to the list
    int *i3 = malloc(sizeof(int));
    *i3 = 12;
    list_addLast(&l1, i3);
    // list is now [11, 10, 12]

    // instantiate, initialize and add 4th element to the list
    int *i4 = malloc(sizeof(int));
    *i4 = 0;
    list_addLast(&l1, i4);
    // list is now [11, 10, 12, 0]

    // print the element in position 1 (that is 10)
    printf("the element in position 1 is: %d\n", *(int *)list_get(l1, 1));

    // remove the element that is in position 1
    list_remove(&l1, 1, freeIntPointer);
    // list is now [11, 12]

    // print the max element (that is 12)
    printf("the max element of the list is: %d\n", *(int *)list_max(l1, intComparator));

    // remove all the list elements
    list_removeAll(&l1, freeIntPointer);
    // list is now []
}
