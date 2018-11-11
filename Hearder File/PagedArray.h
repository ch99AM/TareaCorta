//
// Created by christian on 08/09/18.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include "ManegerFile.h"

#ifndef TAREACORTA_PAGEDARRAY_H
#define TAREACORTA_PAGEDARRAY_H


using namespace std;
///////Nuevo tipo page para manejar las paginas de pagedArray /////////
struct Page{
    int *lista;
    int inicio=0, final=0, fre=0, nPg=0;
};
///////////////////////////////////////////////////////////////////////
int pos_max();
class PagedArray{


////////Atributos///////////////////////////////////
private:
    int maxPag = 6; //definimos el maximo de nuemro de paginas que podemos tener el memroia.
    int pagesUpload = 0;
    Page *memory;
    FILE *file;
    ManegerFile manegerFile = ManegerFile();

public:
    int totalPos = 0;

    ////// Metodos //////////////////////////////
public:
    /**
     *  Sobrecarga al operador [], funiona como un buscardor de indices por normal,
     *  pero por debajo utiliza la paginacion para manejar el archivo
     *
     * @param pos -> Posicoon que se busca
     *
     * @return -> El entero de la posicion buscada
     */
    int &operator[](int pos){
        if (pos <= totalPos){
            if(pagesUpload < maxPag) {
                for (int i = 0; i < pagesUpload; i++) {
                    if (memory[i].inicio <= pos and pos <= memory[i].final) {
                        memory[i].fre += 1;
                      //  cout <<  memory[i].lista[pos - ((pos / 256) * 256)] <<endl;////////////////////////////////////////
                        return memory[i].lista[pos - ((pos / 256) * 256)];
                    }
                }
                uploadPage(pos);
                memory[pagesUpload-1].fre += 1;
//                cout << memory[pagesUpload - 1].lista[pos - ((pos / 256) * 256)] <<endl; ////////////////////////////////////
                return memory[pagesUpload - 1].lista[pos - ((pos / 256) * 256)];
            }
            else{
                for (int i = 0; i < pagesUpload ; i++) {
                    if(memory[i].inicio <=  pos and pos <= memory[i].final){
                        memory[i].fre += 1;
                      //  cout << memory[i].lista[pos - ((pos / 256) * 256)] << endl;//////////////////////////////////////////
                        return memory[i].lista[pos - ((pos / 256) * 256)];
                    }
                }
                LRU(pos);
                return operator[](pos);
            }
        }
        else{
            cout << "Indice invaliado"<< endl;
        }
    }

    /**
     * Constructor de la clase
     * @param nameTXT Nombre del archivo con el que se va a trabajar
     */
    PagedArray(char *nameTXT){
        manegerFile.converBin(nameTXT);
        totalPos = pos_max();
        memory = (Page*)malloc(sizeof(Page)*maxPag);

    }
private:

    /**
     * Descarga en el archivo una pagina cuando la memoria esta llena
     * @param array  -> lista que se escribira en el disco
     * @param inicio -> Posicion deonde inicia la lista
     */
    void download(int *array, int inicio){
        file = fopen("Doc.bin", "r+b");
        if (!file) {
            cout << "Error al arbir el archivo binario" << endl;
            exit(1);
        }
        fseek(file, inicio, SEEK_SET);
        fwrite(array, sizeof(int), 256, file);

        fclose(file);
    }

    /**
     * Carga paginas con memorria vaciada
     * @param pos -> Carga una pagina cuando hay memoria libre
     */
    void uploadPage(int pos){
        this->memory[pagesUpload].lista = (int *)calloc(sizeof(int),256);
        this->upload(this->memory[pagesUpload].lista, pos);// Perdir cargar array de pagina

        // Inicializo los atributos de la pagina
        this->memory[pagesUpload].inicio = ((pos/256) *256);
        this->memory[pagesUpload].final = this->memory[pagesUpload].inicio + 255;
        this->memory[pagesUpload].nPg = (pos/256);
        this->memory[pagesUpload].fre = 0;
        this->pagesUpload++;
    }

    /** Cargar partes del archivo binario
    * @param array -> Lista donde se guardaran la parte cargada
    * @param pos -> posicion del elemento que se necesita
    */
    void upload(int *array, int pos){
        file = fopen("Doc.bin", "rb+");
        if (!file){
            cout << "Error al arbir el archivo binario"<< endl;
            exit(1);
        }
        //////
        fseek(file, (pos/256)*256*sizeof(int), SEEK_SET);
        fread(array, sizeof(int), 256, file);
        fclose(file);
    }

    /**
     * Algoritmo de remplazo
     * @param pos -> posicion de la pagina a cargar
     */
    void LRU(int pos){
        int menorUso = memory[pagesUpload-1].fre;
        int pagMenosUso = (pagesUpload-1);
        for (int i = 0; i < pagesUpload; ++i) {
            if(menorUso > memory[i].fre){
                pagMenosUso = i;
                menorUso = memory[i].fre;
            }
            memory[i].fre = memory[i].fre/2; // Reducciomos la frecuencia para que se mantenga en entero
        }
        this-> download(memory[pagMenosUso].lista, memory[pagMenosUso].inicio);
        this-> upload(memory[pagMenosUso].lista, pos);
        this->memory[pagMenosUso].nPg = pos/256;
        this->memory[pagMenosUso].inicio = (pos/256)*256;
        this->memory[pagMenosUso].final = this->memory[pagMenosUso].inicio + 255;
        this->memory[pagMenosUso].fre = 0 ;
    }

    /**
     * Obtener el numero maximo de elementos de archivo
     * @return  Numero de psociones que hay en el archivo binario.
     */
    int pos_max(){
        int pos_max = 0;
        fstream fentrada("Doc.bin", ios::in | ios::binary);
        if(!fentrada){
            cout << "Error al abrir el archivo en pos_max";
            exit(1); }
        fentrada.seekg(0, ios::end);pos_max = fentrada.tellg()/4;
        fentrada.close();
        return pos_max;
    }
};

#endif //TAREACORTA_PAGEDARRAY_H
