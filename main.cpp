
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Ordenamiento.h"
#include <fstream>
#include <string>

using namespace std;

void menu(){
        char *opArch= (char*)malloc(sizeof(string));
        char algoritmo;
        Ordenamiento ordenar = Ordenamiento();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        cout << "TAREA CORTA" << endl
        << "Escoja una de las siguientes opciones de archivos para ordenar" << endl<< endl
        << "1kB.txt" << endl << "4kB.txt" <<endl<< "8kB.txt" <<endl<< "12kB.txt" <<endl<< "24kB.txt"<<endl<<"36kB.txt"<<endl;
        cin >> opArch;
        cout << "Escoja un algoritmo para aplicar el ordenamiento" << endl
        << "QuickSort ------> 1"<<endl<< "SelectionSort --> 2" << endl << "InsertionSort --> 3"<< endl;
        cin >> algoritmo;
        switch (algoritmo){
                case '1' :{
                        ordenar.quickSort(opArch);
                }
                case '2' :{
                        ordenar.selectionSort(opArch);
                }
                case '3' :{
                        ordenar.insertionsort(opArch);
                }
        }
}

int main() {
        char a;
        while (true) {
                menu();
                cout << "EL archivo ordenado esta listo " << endl
                     << "Puede encontrar en: ../TareaCorta /cmake-build-debug/Ordenado.txt"
                     << endl << "Digite 0 para salir o presione 1 para continuar" << endl;
                cin >> a;
                if (a == '0')return 0;

        }
}
