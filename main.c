#include <stdio.h>
#include "arrayList.h"

int main(int argc, char const *argv[])
{
    arrayList array;

    intialiseArray(&array, 10);

    
    printf("Array is empty : %d", arraylist_is_empty(&array));
    
    getchar();
    return 0;
}
