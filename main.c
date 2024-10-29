#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array, array2;


    intialise_arrayList(&array, 1, INT);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 11);
    add_element(&array, 10);
    add_element(&array, 10);
    int element = 20;
    arraylist_insert(&array, &element, 2);
    displayElements(&array);

    getchar();
    return 0;
}
