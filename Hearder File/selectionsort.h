#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "quicksort.h"

void selectionSort(int array[], int size)
{
    int i, j, min_idx;

    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (array[j] < array[min_idx])
                min_idx = j;
        swap(&array[min_idx], &array[i]);
    }
}
#endif // SELECTIONSORT_H
