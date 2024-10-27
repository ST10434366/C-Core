#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array, array2;


    intialise_arrayList(&array, 10);
    
    add_element(&array, 10);

    // displayElements(&array);
    array2 = deep_copy(&array);
    add_element(&array2, 11);
    displayElements(&array2);

    getchar();
    return 0;
}
