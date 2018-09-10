#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
using namespace std;

void swap(int* ele1, int* ele2)
{
    int tmp = *ele1;
    *ele1 = *ele2;
    *ele2 = tmp;
}

int partition (int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partIndx = partition(array, low, high);

        quickSort(array, low, partIndx - 1);
        quickSort(array, partIndx + 1, high);
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

#endif // QUICKSORT_H
