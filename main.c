#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array, array2;
    double element = 20.00;

    intialise_arrayList(&array, 1, INT);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);

    arraylist_insert(&array, &element, 3);
    displayElements(&array);

    getchar();
    return 0;
}
