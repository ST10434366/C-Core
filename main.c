#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array;

    intialiseArray(&array, 10);
    
    addElement(&array, 10);
    addElement(&array, 2);
    addElement(&array, 5);
    addElement(&array, 1);
    addElement(&array, 20);
    addElement(&array, 21);
    addElement(&array, 23);
    addElement(&array, 1);
    
    arraylist_sort_descending(&array);
    displayElements(&array);

    getchar();
    return 0;
}
