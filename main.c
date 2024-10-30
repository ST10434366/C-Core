#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array, array2;
    double element = 10;

    intialise_arrayList(&array, 1, DOUBLE);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    // arraylist_insert(&array, 20, 2);
    displayElements(&array);

    getchar();
    return 0;
}
