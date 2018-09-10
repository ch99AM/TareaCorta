//
// Created by christian on 08/09/18.
//
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <stack>
#include <cstdlib>

#ifndef TAREACORTA_MANEGERFILE_H
#define TAREACORTA_MANEGERFILE_H

using namespace std;

string read();
void write();
int num();
string DecimalToBinario(int dec);

class ManegerFile {

public:
    string read(char *name){
         ifstream read_file(name, ios::in|ios::binary);


        if (!read_file) {
            cout << "No se puede abrir el archivo" << endl;
            exit(1);
        }
        string text;

        read_file >> text;

        return text;
    };

    void write(char *name) {
        ofstream write_file(name, ios::binary | ios::out);

        if (write_file.fail()) {
            cout << "Error al escribir el archivo" << endl;
            exit(1);
        }
       while(write_file.tellp()< (sizeof(int)*2000)+2000){
            int temp = num();
            if (temp/100 < 1 and temp/10 < 1) {
                cout << sizeof(temp) << endl;
            }
            write_file << num()<<',';
        }

        write_file.close();
    };

    //////////No tocar//////////////////
    int num() {
        int a;
        a = (random() % 6548);
        return a;

    };

    ///////////No tocar///////////////////
    string DecimalToBinario(int dec) {
        stringstream salida;
        int num = dec;
        stack<int>* bin = new std::stack<int>();
        while (num >= 2) {
            bin->push(num % 2);
            (num /= 2) ;
            if (num == 1 || num == 0) {
                bin->push(num);
            }
        }
        while (!bin->empty()) {
            salida << bin->top();
            bin->pop();
        }
        return salida.str();
    };
};
#endif //TAREACORTA_MANEGERFILE_H
