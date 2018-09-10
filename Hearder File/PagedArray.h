//
// Created by christian on 08/09/18.
//

#include <iostream>
#include <stdlib.h>
#include <string>


#include "ManegerFile.h"
#include "QuickSort.h"
#include "ManegerFile.h"

#ifndef TAREACORTA_PAGEDARRAY_H
#define TAREACORTA_PAGEDARRAY_H

struct Page{
int *lista;
int inicio, final, fre, nPg;
};
using namespace std;
class PagedArray{
private:
    int pagesUpload = 0;
    Page *memory =(Page*)malloc(sizeof(Page)*6);
    long totalPos;
    FILE *file;

    int &operator[](int pos){


    };
    void download(){

    };
    string upload(){
        string arrayN;


        return arrayN;
    };

    Page createPageds(){
        ManegerFile file = ManegerFile();
        string array = file.read("1kB.dat");
        int lista[array.length()];
        int a = 0;
        string temp;

        for (int i = 0; i < array.length(); ++i) {
            if (array[i] == ','){
                cout << " , ";
                lista[a] = stoi(temp);
                a++;
                temp = "";
            }
            else{
                cout << string(1, array[i]);
                temp += string(1, array[i]);
            }
        }
        for (int j = 0; j < (a/256); ++j) {


        }
    };
};

#endif //TAREACORTA_PAGEDARRAY_H
