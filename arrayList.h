#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct arrayList
{
    int size;
    int index;
    int avaliableMemory;
    int *array;
} arrayList;


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Intialisation of arrayList
void intialiseArray(struct arrayList *a1, int arraySize)
{
    a1->array = (int *)calloc(arraySize, arraySize * sizeof(int)); // 8 bytes

    if (a1->array == NULL)
    {
        exit(1);
    }
    
    a1->size = arraySize; //How many elements can be stored in the array
    a1->index = 0; // The current index 
    a1->avaliableMemory = arraySize * sizeof(int); // The amount of memory the array has
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Add elemet to arrayList
void addElement(struct arrayList *a1, int element)
{
    int *status = NULL;

    if (a1->index == a1->size)
    {
        status = (int *)realloc(a1->array, a1->size * sizeof(int));
        if (status == NULL)
        {
            exit(1);
        }

        a1->size = a1->size * 2;
        a1->avaliableMemory = a1->avaliableMemory * 2;
        a1->array[a1->index++] = element;
    }
    else
    {
        a1->array[a1->index ++] = element;
    }
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Resizes the arrayList
void resizeArray(struct arrayList *a1)
{
    //Check for zero value
    int *pointer = NULL;

    pointer = (int*) malloc(a1->size * sizeof(int));

    for (int i = 0; i < a1->size - 1; i++)
    {
        pointer[i] = a1->array[i];
    }
    
    free((a1->array));
    a1->array = (int*) malloc((a1->size - 1) * sizeof(int));

    for (int i = 0; i < a1->size - 1; i++)
    {
        a1->array[i] = *pointer;
        ++pointer;
    }
}  

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Removes element from arrayList
void removeElement(struct arrayList *a1, int elementIndex)
{
    a1->array[elementIndex] = 0;
    //Add resize array function
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Displays all elements in the arrayList
void displayElements(struct arrayList *a1)
{
    
    for (int i = 0; i < a1->size; i++)
    {
        printf("%d ", a1->array[i]);
    }
}


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Displays element at specified index in the arrayList
void displayElement(struct arrayList *a1, int index)
{
    printf("\nElement at index %d : %d", index, a1->array[index]);
}
