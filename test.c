#include <stdio.h>
#include <stdlib.h>
typedef struct arrayList
{
    int     size;
    int     index;
    int     elements;
    int     avaliableMemory;
    void    *array;
} arrayList;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Intialisation of arrayList
void intialise_arrayList(struct arrayList *a1, int arraySize)
{
    a1->array = calloc(arraySize, sizeof(double)); // 8 bytes

    if (a1->array == NULL)
    {
        exit(1);
    }
    
    a1->size = arraySize; //How many elements can be stored in the array
    a1->index = 0; // The current index 
    a1->avaliableMemory = arraySize * sizeof(double); // The amount of memory the array has
    a1->elements = 0;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
// Add elemet to arrayList
void add_element(struct arrayList *a1, int element)
{
    void *status = NULL;

    // No longer any space in the arrayList
    if (a1->index == a1->size)
    {
        // Reallocates memory (no cast as realloc returns void pointer by default)
        status = realloc(a1->array, a1->size * sizeof(double));
        //Checks for failure in memory allocation 
        if (status == NULL)
        {
            exit(1);
        }

        // Inserts specified element
        
        ((double *)(a1-> array))[a1->index++] = (double) element;


        a1->size = a1->size * 2;
        a1->avaliableMemory = a1->avaliableMemory * 2;
    }
    else
    {
    ((double *)(a1-> array))[a1->index++] = (double) element;
    }

    a1->elements++;
}

double cast_helper(int element)
{
    return (double) element;
}

void arraylist_insert(struct arrayList *a1, void * element, int index)
{
    void *pointer = NULL;

    pointer = malloc(a1->size * sizeof(double));

    if (pointer == NULL)
    {
        exit(1);
    }
    
        for (int i = 0; i < index; i++)
        {
            ((double *) pointer)[i] = ((double *)(a1->array))[i];
        }
        a1->elements++;
        // Insert the double element
        ((double *)pointer)[index] =  cast_helper(*(int *)element);

        for (int i = index + 1, x = index; i < a1->elements + 1; i++, x++)
        {
            ((double *)pointer)[i] = ((double *)(a1->array))[x];
        }

    // Releases the memory of the previous arrayList
    free(a1->array);
    // Assigns the new pointer
    a1->array = pointer;
}


void displayElements(struct arrayList *a1)
{

        for (int i = 0; i < a1->elements; i++)
        {
            // if (a1->array[i] != 0)
            // {
            //     printf("%d ", a1->array[i]);
            // }
            printf("%f ", ((double *)a1->array)[i]);
        }

}


int main(int argc, char const *argv[])
{
    arrayList array;
    int element = 20;

    intialise_arrayList(&array, 3);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    add_element(&array, 10);
    arraylist_insert(&array, &element, 2);
    displayElements(&array);

    getchar();
    return 0;
}
