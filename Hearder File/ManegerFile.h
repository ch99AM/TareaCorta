//
// Created by christian on 08/09/18.
//
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <cstdlib>

#ifndef TAREACORTA_MANEGERFILE_H
#define TAREACORTA_MANEGERFILE_H


using namespace std;

void converBin();
int num();

class ManegerFile {

public:
    /**
     * Pasa los numeros de un archivo de texto a un archivo binario.
     * @param name Nombre del archivo a convertir en binario
     */
    void converBin(char *name){
        FILE *read, *write;
        read = fopen(name,"r+" );
        write = fopen("Doc.bin", "wb");
        if(write == NULL or read == NULL){
            cout << "Se a producido un error en converBin"<<endl;
            exit(1);
        }
        string temp;
        char num[1];
        int leidos;
        leidos = fread(num, 1,1,read);
        while(leidos != 0) {
            if(*num == ','){
                int temp1[1];
                *temp1 = (stoi(temp));
                fwrite (temp1, sizeof(int),1,write);
                temp = "";
            }
            else{
                temp +=string(1, *num);
            }
            leidos = fread(num, 1, 1, read);
        }
        fclose(read);
        fclose(write);
    };

    ///Numeros random //
    int num() {
        int a;
        a = (random() % 8457);
        return a;

    };
};
#endif //TAREACORTA_MANEGERFILE_H
