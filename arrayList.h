//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^{ BEGINNING OF FILE }^^^^^^^^^^^^^^^^^^^^^^^^^^//
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Type
{
    INT     = sizeof(int),
    FLOAT   = sizeof(float),
    DOUBLE  = sizeof(double),
    CHAR    = sizeof(char)
} Type;

typedef struct arrayList
{
    int     size;
    int     index;
    int     elements;
    int     avaliableMemory;
    void    *array;
    Type    dataType;
} arrayList;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Intialisation of arrayList
void intialise_arrayList(struct arrayList *a1, int arraySize, Type dataType)
{
    a1->array = (void *)calloc(arraySize, arraySize * dataType); // 8 bytes

    if (a1->array == NULL)
    {
        exit(1);
    }
    
    a1->size = arraySize; //How many elements can be stored in the array
    a1->index = 0; // The current index 
    a1->avaliableMemory = arraySize * dataType; // The amount of memory the array has
    a1->elements = 0;
    a1->dataType = dataType;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Add elemet to arrayList
void add_element(struct arrayList *a1, double element)
{
    double *status = NULL;

    if (a1->index == a1->size)
    {
        status = (double *)realloc(a1->array, a1->size * sizeof(double));
        if (status == NULL)
        {
            exit(1);
        }

        switch (a1->dataType)
        {
        case DOUBLE:
            ((double * )(a1-> array))[a1->index++] = element;
            break;
        
        default:
            break;
        }

        a1->size = a1->size * 2;
        a1->avaliableMemory = a1->avaliableMemory * 2;
    }
    else
    {
        ((double *)(a1->array))[a1->index++] = element;
    }
    a1->elements++;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Insert element at specific index shifting other elements
// Rudimentary but decent for now 
void arraylist_insert(struct arrayList *a1, int element, int index)
{
    int *pointer = NULL;

    pointer = (int *) malloc(a1->size * (sizeof(int)));

    if (pointer == NULL)
    {
        exit(1);
    }
    
    for (int i = 0; i < index; i++)
    {
        pointer[i] = a1->array[i];
    }

    pointer[index] = element;

    for (int i = index+ 1; i < a1->size; i++)
    {
        pointer[i] = a1->array[i];
    }
    
    free(a1->array);
    a1->array = pointer;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Removes element at specific index and shifts elements down
void arraylist_remove(struct arrayList *a1, int element, int index)
{
    int *pointer = NULL;
    pointer = (int *) malloc(a1->size * sizeof(int));

    if (pointer == NULL)
    {
        exit(1);
    }
    
    for (int i = 0; i < index; i++)
    {
        pointer[i] = a1->array[i];
    }
    
    pointer[index] = element;

    for (int i = index + 1; i < a1->size; i++)
    {
        pointer[i] = a1->array[i];
    }
    
    free(a1->array);
    a1->array = pointer;
    a1->elements--;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Pops/removes the last element of the array
void arraylist_pop(struct arrayList *a1)
{
    a1->array[a1->index - 1] = 0;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Cleares all the elements but keeps the memory allocated for array
void arraylist_clear(struct arrayList *a1)
{
    int *end = a1->array + a1->index;

    //Add a counter for the number of user added elements in the struct otherwise this will add unnecessary addtional operations (setting values to zero that are zero)
    for (; a1->array < end; a1->array++)
    {
        a1->array = 0;
    }
    a1->elements = 0;
    
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Returns elements at specifc index (maybe use void pointer so it is not type specifc)

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Return the first element of the array 
int arraylist_front(struct arrayList *a1)
{
    return *(a1->array);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Return the last element of the array
// Requires a counter to return a user inserted value otherwise 0 place holder will be returned
int arraylist_back(struct arrayList *a1)
{
    return *(a1->array + a1->elements - 1);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Return the size of the array 
int arraylist_size(struct arrayList *a1)
{
    //Needs counter to get the number of user inserted elements.
    return a1->size;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Returns the number of bytes allocated to the arrayList
int arraylist_bytes(struct arrayList *a1)
{
    return a1->avaliableMemory;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Return the current allocated capacity of the array (number of elements)
int arraylist_capacity(struct arrayList *a1)
{
    return a1->size;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Return if array is empty (boolean value)
bool arraylist_is_empty(struct arrayList *a1)
{
    return a1->index > 0;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Shrink the array to fit the existing elements
void arraylist_shrink_to_fit(struct arrayList *a1)
{
    int* pointer = NULL;
    pointer = (int *) malloc(a1->elements * sizeof(int));

    if (pointer == NULL)
    {
        exit(1);
    }
    
    for (int i = 0; i < 8; i++)
    {
        pointer[i] = a1->array[i];
    }

    free(a1->array);
    a1->array = pointer;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Searches the array for a specific index and returns false if not found 
bool arraylist_find(struct arrayList *a1, int index)
{
    if (a1->array[index])
    {
        return true;
    }

    return false;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Bubble Sorts the array in ascending order
void arraylist_sort_ascending(struct arrayList *a1)
{
    for (int x = 0; x < a1->elements; x++)
    {
        for (int i = 0; i < a1->elements - 1; i++)
        {
            if (a1->array[i] > a1->array[i + 1])
            {
                int temp = a1->array[i];
                a1->array[i] = a1->array[i + 1];
                a1->array[i + 1] = temp;
            }
        }
    }
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Bubble Sorts the array in descending order
void arraylist_sort_descending(struct arrayList *a1)
{
    for (int x = 0; x < a1->elements; x++)
    {
        for (int i = 0; i < a1->elements - 1; i++)
        {
            if (a1->array[i] < a1->array[i + 1])
            {
                int temp = a1->array[i];
                a1->array[i] = a1->array[i + 1];
                a1->array[i + 1] = temp;
            }
        }
    }
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Swaps two elements in the arraylist 

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Reverses the order of elements within the array (NOTE: IMPROVE THE READABILITY)
void arraylist_reverse(struct arrayList *a1)
{
    int *pointer = NULL;
    pointer = (int *) malloc(a1->size * sizeof(int));

    if (pointer == NULL)
    {
        exit(1);
    }

    for (int i = a1->size, x = 0; i > 0; i--, x++)
    {
        pointer[x]= a1->array[i];
        
    }
    
    free(a1->array);
    a1->array = pointer;
    free(pointer);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Maps a function to each array element (Add a struct within the struct that acts as a map for each element)

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Filter and create new array list with elements that have satisfied a condition 

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Iteratres over the elements applying a function to it (for loop)

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Creates a deep copy of the arraylist 
arrayList deep_copy(struct arrayList *a1)
{   
    arrayList copy;
    copy = *a1;
    return copy;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Custom comparators sets a custom comparison 

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
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

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Removes element from arrayList
void removeElement(struct arrayList *a1, int elementIndex)
{
    a1->array[elementIndex] = 0;
    //Add resize array function
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Displays all elements in the arrayList
void displayElements(struct arrayList *a1)
{
    //use a counter in the struct to determine the correct number of elements ot print instead of filtering by zero (which maybe an actual element)
    for (int i = 0; i < a1->elements; i++)
    {
        // if (a1->array[i] != 0)
        // {
        //     printf("%d ", a1->array[i]);
        // }
        printf("%lf ", ((double *)a1->array)[i]);
    }
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Displays element at specified index in the arrayList
void displayElement(struct arrayList *a1, int index)
{
    printf("\nElement at index %d : %d", index, a1->array[index]);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^{ END OF FILE }^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//