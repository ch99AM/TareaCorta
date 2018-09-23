#include  <iostream>
#include "PagedArray.h"


class Ordenamiento {

public:

    /////Metodos de ordenamiento///////
    void insertionsort(char *name){
        PagedArray array = PagedArray(name);
        insertionSort(array);
    }
    void selectionSort(char *name){
        PagedArray array = PagedArray(name);
        selectionSort(array);
    }
    void quickSort(char *name){
        PagedArray array = PagedArray(name);
        quickSort(&array, 0, array.totalPos);
        writeOut(array, array.totalPos);
    }

private:

//////////insertionSort///////////////namiento{
    void insertionSort(PagedArray array) {
        int n = array.totalPos;
        int key, j;
        for (int i = 1; i < n; i++) {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
        writeOut(array,n);
    }
//////////////////////////////////////////////

//////////Quicksort/////////////////////////

    // Función para dividir el array y hacer los intercambios
    int divide(PagedArray &array, int start, int final) {
        int left;
        int right;
        int pivot;
        int temp;

        pivot = array[start];
        left = start;
        right = final;

        //Mientras no se cruzen los índices
        while (left < right) {
            while (array[right] > pivot) {
                right--;
            }

            while ((left < right) && (array[left] <= pivot)) {
                left++;
            }

            // Si todavía no se cruzan los indices seguimos intercambiando
            if (left < right) {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }

        // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
        temp = array[right];
        array[right] = array[start];
        array[start] = temp;

        // La nueva posición del pivot
        return right;
    }

    // Función recursiva para hacer el ordenamiento
    void quickSort(PagedArray *array, int start, int final) {
        int pivot;

        if (start < final) {
            pivot = divide(array[0], start, final);

            quickSort(array, start, pivot - 1);

            quickSort(array, pivot + 1, final);
        }
    }

//////////////////////////////////////////////

/////////////SelectionSort///////////////////
    void swap(int *ele1, int *ele2) {
        int tmp = *ele1;
        *ele1 = *ele2;
        *ele2 = tmp;
    }

    void selectionSort(PagedArray array) {
        int size = array.totalPos;
        int  min_idx;

        for (int i = 0; i < size - 1; i++) {
            min_idx = i;
            for (int j = i + 1; j < size; j++)
                if (array[j] < array[min_idx])
                    min_idx = j;
            swap(&array[min_idx], &array[i]);
        }
        writeOut(array,size);
    }

/////////////Archivo de salida ordenado//////////////////
    void writeOut(PagedArray array, int length ) {
        ofstream ordenado("Ordenado.txt", ios::out);
        for (int i = 0; i < length; ++i) {
            ordenado << array[i] << ',';
        }
        ordenado.close();
    }
};